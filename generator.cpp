#include "generator.h"
#include "format.h"
#include <ostream>
#include <ranges>
#include <unordered_set>
#include <array>

struct FeatureHash {
    std::size_t operator()(const std::span<const std::string_view>& k) const noexcept
    {
        std::size_t hash = 0;
        for (auto& i : k) {
            hash ^= std::hash<std::string_view>()(i);
        }
        return hash;
    }
};

struct FeatureEqual {
    bool operator()(const std::span<const std::string_view>& lhs, const std::span<const std::string_view>& rhs) const
    {
        return lhs.size() == rhs.size() && std::equal(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
    }
};

auto SortByFeature(const auto& commands,
                   const std::unordered_map<std::string_view, std::vector<std::string_view>>& command_to_features)
{
    // stores the commands under the same features
    std::unordered_map<std::span<const std::string_view>, std::vector<std::string_view>, FeatureHash, FeatureEqual> feature_blocks;
    for (auto command : commands) {
        auto features = std::span{ command_to_features.at(command) };
        feature_blocks[features].push_back(command);
    }
    return feature_blocks;
}

std::string MakeGuard(auto& features)
{
    std::string output{};
    for (auto& i : features) {
        output += wis::format("defined({}) || ", i);
    }
    output.pop_back();
    output.pop_back();
    output.pop_back();
    return output;
}

template<size_t size>
std::string Replace(std::string_view og, const std::array<std::pair<std::string_view, std::string_view>, size>& map)
{
    std::string out{ og };
    for (auto&& [a, b] : map) {
        for (auto pos = out.find(a); pos != std::string::npos; pos = out.find(a)) {
            out.replace(pos, a.length(), b);
        }
    }
    return out;
}

std::string MakeTable(auto& feature_blocks)
{
    std::string output;
    for (auto& [feature, cmds] : feature_blocks) {
        output += "#if " + MakeGuard(feature) + '\n';
        for (auto& i : cmds) {
            output += wis::format("PFN_{} {};\n", i, i);
        }
        output += "#endif\n";
    }
    return output;
}

std::string MakeCommandInit(std::string_view init_format, std::string_view cmd,
                            std::span<const std::string_view> cmd_features,
                            const std::unordered_map<std::string_view, std::vector<std::string_view>>& features,
                            std::span<const std::string_view> aliases)
{
    using mapty = std::pair<std::string_view, std::string_view>;
    std::string output;
    std::unordered_set<std::string_view> left_features{ cmd_features.begin(), cmd_features.end() };

    for (auto&& a : aliases) {
        auto a_features = std::span{ features.at(a) };
        for (auto&& f : a_features) {
            if (left_features.contains(f)) {
                left_features.erase(f);
            }
        }
    }
    output += "#if " + MakeGuard(left_features) + '\n';
    output += Replace(init_format, std::array{
                                           mapty{ "{cmd}", cmd },
                                           mapty{ "{type}", cmd },
                                   });

    for (auto&& a : aliases) {
        output += "#elif " + MakeGuard(features.at(a)) + '\n';
        output += Replace(init_format, std::array{
                                               mapty{ "{cmd}", cmd },
                                               mapty{ "{type}", a },
                                       });
    }
    output += "#endif\n";

    return output;
}

std::string MakeGlobalCommands(const std::unordered_set<std::string_view>& commands,
                               const std::unordered_map<std::string_view, std::vector<std::string_view>>& features,
                               const std::unordered_map<std::string_view, std::vector<std::string_view>>& commands_to_aliases)
{
    auto feature_blocks = SortByFeature(commands, features);

    std::string output{ "struct VkGlobalTable{\n" };
    output += "void Init(LibTokenView token) noexcept{\n";

    for (auto& [feature, cmds] : feature_blocks) {
        output += "#if " + MakeGuard(feature) + '\n';
        for (auto& i : cmds) {
            if (auto it = commands_to_aliases.find(i); it != commands_to_aliases.end()) {
                output += MakeCommandInit("\t{cmd} = token.GetProcAddress<decltype({type})>(\"{type}\");\n", i, feature, features, it->second);
                continue;
            }
            output += wis::format("\t{} = token.GetProcAddress<decltype({})>(\"{}\");\n", i, i, i);
        }
        output += "#endif\n";
    }

    return output + wis::format("}}\npublic:\n{}}};\n", MakeTable(feature_blocks));
}

std::string MakeInstanceCommands(const std::unordered_set<std::string_view>& commands,
                                 const std::unordered_map<std::string_view, std::vector<std::string_view>>& features,
                                 const std::unordered_map<std::string_view, std::vector<std::string_view>>& commands_to_aliases)
{
    auto feature_blocks = SortByFeature(commands, features);

    std::string output{ "struct VkInstanceTable{\n" };
    output += "void Init(VkInstance instance, VkGlobalTable global_table) noexcept{\n";

    for (auto& [feature, cmds] : feature_blocks) {
        output += "#if " + MakeGuard(feature) + '\n';
        for (auto& i : cmds) {
            if (auto it = commands_to_aliases.find(i); it != commands_to_aliases.end()) {
                output += MakeCommandInit("\t{cmd} = (PFN_{cmd})global_table.vkGetInstanceProcAddr(instance, \"{type}\");\n", i, feature, features, it->second);
                continue;
            }
            output += wis::format("\t{} = (PFN_{})global_table.vkGetInstanceProcAddr(instance, \"{}\");\n", i, i, i);
        }
        output += "#endif\n";
    }

    return output + wis::format("}}\npublic:\n{}}};\n", MakeTable(feature_blocks));
}

std::string MakeDeviceCommands(const std::unordered_set<std::string_view>& commands,
                               const std::unordered_map<std::string_view, std::vector<std::string_view>>& features,
                               const std::unordered_map<std::string_view, std::vector<std::string_view>>& commands_to_aliases)
{
    auto feature_blocks = SortByFeature(commands, features);

    std::string output{ "struct VkDeviceTable{\n" };
    output += "void Init(VkDevice device, VkGlobalTable global_table) noexcept{\n";

    for (auto& [feature, cmds] : feature_blocks) {
        output += "#if " + MakeGuard(feature) + '\n';
        for (auto& i : cmds) {
            if (auto it = commands_to_aliases.find(i); it != commands_to_aliases.end()) {
                output += MakeCommandInit("\t{cmd} = (PFN_{cmd})global_table.vkGetDeviceProcAddr(device, \"{type}\");\n", i, feature, features, it->second);
                continue;
            }
            output += wis::format("\t{} = (PFN_{})global_table.vkGetDeviceProcAddr(device, \"{}\");\n", i, i, i);
        }
        output += "#endif\n";
    }

    return output + wis::format("}}\npublic:\n{}}};\n", MakeTable(feature_blocks));
}

std::string MakeAliasTypedefs(const std::unordered_map<std::string_view, std::vector<std::string_view>>& features,
                              const std::unordered_map<std::string_view, std::vector<std::string_view>>& commands_to_aliases)
{
    std::string output;
    for (auto&& [command, aliases] : commands_to_aliases) {
        auto& cmd_features = features.at(command);
        std::unordered_set<std::string_view> left_features{ cmd_features.begin(), cmd_features.end() };

        for (auto&& a : aliases) {
            auto a_features = std::span{ features.at(a) };
            for (auto&& f : a_features) {
                if (left_features.contains(f)) {
                    left_features.erase(f);
                }
            }
        }
        output += wis::format("#if !({})\n", MakeGuard(left_features));
        const char* first = "#if ";
        const char* last = "#elif ";

        for (auto&& a : aliases) {
            output += first + MakeGuard(features.at(a)) + '\n';
            output += wis::format("using PFN_{} = PFN_{};\n", command, a);
            first = last;
        }
        if (first == last)
            output += "#endif\n";
        output += "#endif\n";
    }
    return output;
}

//////////////////////////////////////////////////////////////////////////

std::string MakeAliasTypedefs(std::string_view format,
                              const std::unordered_map<std::string_view, std::vector<std::string_view>>& features,
                              const std::unordered_map<std::string_view, wis::Handle>& handles)
{
    using mapty = std::pair<std::string_view, std::string_view>;
    std::string output;
    for (auto&& [hname, handle] : handles) {
        if (handle.aliases.empty())
            continue;

        auto& cmd_features = features.at(hname);
        std::unordered_set<std::string_view> left_features{ cmd_features.begin(), cmd_features.end() };

        for (auto&& a : handle.aliases) {
            auto a_features = std::span{ features.at(a) };
            for (auto&& f : a_features) {
                if (left_features.contains(f)) {
                    left_features.erase(f);
                }
            }
        }
        output += wis::format("#if !({})\n", MakeGuard(left_features));
        const char* first = "#if ";
        const char* last = "#elif ";

        for (auto&& a : handle.aliases) {
            output += first + MakeGuard(features.at(a)) + '\n';

            output += Replace(format, std::array{
                                              mapty{ "{hnd}", hname },
                                              mapty{ "{alias}", a },
                                      });
            first = last;
        }
        if (first == last)
            output += "#endif\n";
        output += "#endif\n";
    }
    return output;
}

std::string MakeHandleTrait(const wis::Handle& handle)
{
    return wis::format(
            R"(template<>
class handle_traits<{}>
{{
public:
    using parent = {};
    using deleter_parent = {};
    using deleter_pool = {};
    using deleter_pfn = {};

    constexpr static inline deleter_pfn default_deleter() noexcept
    {{
        return {};
    }}
}};

)",
            handle.name,
            handle.parent ? handle.parent->name : "empty_type",
            handle.destroy_parent ? handle.destroy_parent->name : "empty_type",
            handle.pool ? handle.pool->name : "empty_type",
            handle.destroy_command ? wis::format("function_pointer_t<decltype({})>", handle.destroy_command->name) : "nullptr_t",
            handle.destroy_command ? handle.destroy_command->name : "nullptr");
}

std::string MakeHandleTraits(const std::unordered_map<std::string_view, wis::Handle>& handles,
                             const std::unordered_map<std::string_view, std::vector<std::string_view>>& features)
{
    auto feature_blocks = SortByFeature(handles | std::views::keys, features);
    std::string output;

    for (auto& [feature, fhandles] : feature_blocks) {
        output += "#if " + MakeGuard(feature) + '\n';
        for (auto& i : fhandles) {
            output += wis::format("{}\n", MakeHandleTrait(handles.at(i)));
        }
        output += "#endif\n";
    }

    return output;
}

std::string MakeHandleTraits(const wis::Context& context)
{
    std::string output;
    std::unordered_map<std::string_view, std::vector<std::string_view>> handle_to_ext;

    handle_to_ext.reserve(context.handles.size());
    std::vector<std::string_view> to_erase;

    for (auto&& [fname, f] : context.features) {
        for (auto&& h : f.handles) {
            auto& hnd = context.GetHandle(h);
            handle_to_ext[hnd.name].push_back(fname);
            if (hnd.name != h)
                handle_to_ext[h].push_back(fname);
        }
    }
    for (auto&& [ename, e] : context.extensions) {
        for (auto&& h : e.handles) {
            auto& hnd = context.GetHandle(h);
            handle_to_ext[hnd.name].push_back(ename);
            if (hnd.name != h)
                handle_to_ext[h].push_back(ename);
        }
    }

    output += MakeAliasTypedefs("using {hnd} = {alias};\n", handle_to_ext, context.handles);
    output += "\n";

    output += MakeHandleTraits(context.handles, handle_to_ext);
    output += "\n";
    return output;
}

void wis::Generator::GenerateHandleTraits(const Context& context, std::ostream& stream)
{
    std::string output{
        R"(#pragma once
#include <type_traits>
#include <vulkan/vulkan.h>


namespace wis {
class empty_type
{
};

template<typename T>
using function_pointer_t = std::conditional_t<std::is_function_v<std::remove_pointer_t<T>>, std::remove_pointer_t<T>*, nullptr_t>;

template<typename HandleType>
class handle_traits
{
public:
    using parent = empty_type;
    using deleter_parent = empty_type;
    using deleter_pool = empty_type;
    using deleter_pfn = nullptr_t;

    constexpr static inline deleter_pfn default_deleter() noexcept
    {
        return nullptr;
    }
};
)"
    };
    output += MakeHandleTraits(context);
    output += "}\n";
    stream << output;
}

void wis::Generator::GenerateLoader(const Context& context, std::ostream& stream)
{
    std::string output{ R"(#pragma once
#include <vulkan/vulkan.h>
#include "vk_libinit.hpp"

namespace wis {

)" };

    std::unordered_map<std::string_view, std::vector<std::string_view>> command_to_features;
    std::unordered_set<std::string_view> global_commands;
    std::unordered_set<std::string_view> instance_commands;
    std::unordered_set<std::string_view> device_commands;
    global_commands.emplace("vkGetInstanceProcAddr");
    global_commands.emplace("vkGetDeviceProcAddr");
    global_commands.emplace("vkCreateInstance");
    global_commands.emplace("vkDestroyInstance");

    std::vector<std::string_view> to_erase;
    command_to_features.reserve(context.commands.size());

    for (auto&& [fname, f] : context.features) {
        for (auto&& c : f.commands) {
            auto& xcommand = context.GetCommand(c);
            auto xcommand_name = xcommand.name;

            command_to_features[c].push_back(fname);
            if (c != xcommand_name) {
                command_to_features[xcommand_name].push_back(fname);
            }

            if (global_commands.contains(xcommand_name)) {
                continue;
            }
            if (xcommand.IsGlobal(context)) {
                global_commands.emplace(xcommand_name);
                continue;
            }
            if (xcommand.IsDevice(context)) {
                device_commands.emplace(xcommand_name);
                continue;
            }
            if (xcommand.IsInstance(context)) {
                instance_commands.emplace(xcommand_name);
            }
        }
    }
    for (auto&& [ename, e] : context.extensions) {
        for (auto&& c : e.commands) {
            auto& xcommand = context.GetCommand(c);
            auto xcommand_name = xcommand.name;

            command_to_features[c].push_back(ename);
            if (c != xcommand_name) {
                command_to_features[xcommand_name].push_back(ename);
            }

            if (global_commands.contains(xcommand_name)) {
                continue;
            }

            if (xcommand.IsGlobal(context)) {
                global_commands.emplace(xcommand_name);
                continue;
            }
            if (xcommand.IsDevice(context)) {
                device_commands.emplace(xcommand_name);
                continue;
            }
            if (xcommand.IsInstance(context)) {
                instance_commands.emplace(xcommand_name);
            }
        }
    }

    output += MakeAliasTypedefs(command_to_features, context.command_to_aliases);
    output += "\n";

    // Global commands
    output += MakeGlobalCommands(global_commands, command_to_features, context.command_to_aliases);
    output += "\n";

    // Instance commands
    output += MakeInstanceCommands(instance_commands, command_to_features, context.command_to_aliases);
    output += "\n";

    // Device commands
    output += MakeDeviceCommands(device_commands, command_to_features, context.command_to_aliases);
    output += "\n";

    stream << output + "}\n";
}

