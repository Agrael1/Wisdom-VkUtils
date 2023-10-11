#include "generator.h"
#include "format.h"
#include <ostream>
#include <ranges>
#include <unordered_set>

struct FeatureHash {
    std::size_t operator()(const std::span<std::string_view>& k) const noexcept
    {
        std::size_t hash = 0;
        for (auto& i : k) {
            hash ^= std::hash<std::string_view>()(i);
        }
        return hash;
    }
};

struct FeatureEqual {
    bool operator()(const std::span<std::string_view>& lhs, const std::span<std::string_view>& rhs) const
    {
        return lhs.size() == rhs.size() && std::equal(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
    }
};

auto SortByFeature(const std::unordered_set<std::string_view>& commands, std::unordered_map<std::string_view, std::vector<std::string_view>>& command_to_features)
{
    // stores the commands under the same features
    std::unordered_map<std::span<std::string_view>, std::vector<std::string_view>, FeatureHash, FeatureEqual> feature_blocks;
    for (auto command : commands) {
        feature_blocks[command_to_features[command]].push_back(command);
    }
    return feature_blocks;
}
std::string MakeGuard(std::span<std::string_view> features)
{
    std::string output{ "#if " };
    for (auto& i : features) {
        output += wis::format("defined({}) || ", i);
    }
    output.pop_back();
    output.pop_back();
    output.pop_back();
    output += "\n";
    return output;
}

std::string MakeTable(auto feature_blocks)
{
    std::string output;
    for (auto& [feature, cmds] : feature_blocks) {
        output += MakeGuard(feature);
        for (auto& i : cmds) {
            output += wis::format("PFN_{} {};\n", i, i);
        }
        output += "#endif\n";
    }
    return output;
}

std::string MakeGlobalCommands(const std::unordered_set<std::string_view>& commands, std::unordered_map<std::string_view, std::vector<std::string_view>>& features)
{
    auto feature_blocks = SortByFeature(commands, features);

    std::string output{ "struct VkGlobalTable{\n" };
    output += "void Init(LibToken token) noexcept{\n";

    for (auto& [feature, cmds] : feature_blocks) {
        output += MakeGuard(feature);
        for (auto& i : cmds) {
            output += wis::format("\t{} = token.GetProcAddress<decltype({})>();\n", i, i);
        }
        output += "#endif\n";
    }

    return output + wis::format("}}\npublic:\n{}}};\n", MakeTable(feature_blocks));
}


std::string MakeInstanceCommands(const std::unordered_set<std::string_view>& commands, std::unordered_map<std::string_view, std::vector<std::string_view>>& features)
{
    auto feature_blocks = SortByFeature(commands, features);

    std::string output{ "struct VkInstanceTable{\n" };
    output += "void Init(VkInstance instance, VkGlobalTable global_table) noexcept{\n";

    for (auto& [feature, cmds] : feature_blocks) {
        output += MakeGuard(feature);
        for (auto& i : cmds) {
            output += wis::format("\t{} = (PFN_{})global_table.vkGetInstanceProcAddr(instance, \"{}\");\n", i, i, i);
        }
        output += "#endif\n";
    }

    return output + wis::format("}}\npublic:\n{}}};\n", MakeTable(feature_blocks));
}

std::string MakeDeviceCommands(const std::unordered_set<std::string_view>& commands, std::unordered_map<std::string_view, std::vector<std::string_view>>& features)
{
    auto feature_blocks = SortByFeature(commands, features);

    std::string output{ "struct VkDeviceTable{\n" };
    output += "void Init(VkDevice device, VkGlobalTable global_table) noexcept{\n";

    for (auto& [feature, cmds] : feature_blocks) {
        output += MakeGuard(feature);
        for (auto& i : cmds) {
            output += wis::format("\t{} = (PFN_{})global_table.vkGetDeviceProcAddr(device, \"{}\");\n", i, i, i);
        }
        output += "#endif\n";
    }

    return output + wis::format("}}\npublic:\n{}}};\n", MakeTable(feature_blocks));
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
#include "vk_libinit.h"

namespace wis {

)" };

    std::unordered_map<std::string_view, std::vector<std::string_view>> command_to_features;
    std::unordered_set<std::string_view> global_commands;
    std::unordered_set<std::string_view> instance_commands;
    std::unordered_set<std::string_view> device_commands;
    global_commands.emplace("vkGetInstanceProcAddr");
    global_commands.emplace("vkGetDeviceProcAddr");
    global_commands.emplace("vkCreateInstance");

    std::vector<std::string_view> to_erase;
    command_to_features.reserve(context.commands.size());

    for (auto&& [fname, f] : context.features) {
        for (auto&& c : f.commands) {
            command_to_features[c].push_back(fname);
            auto xcommand = context.GetCommand(c);
            if (global_commands.contains(c)) {
                continue;
            }
            if (xcommand.IsGlobal(context)) {
                global_commands.emplace(c);
                continue;
            }
            if (xcommand.IsDevice(context)) {
                device_commands.emplace(c);
                continue;
            }
            if (xcommand.IsInstance(context)) {
                instance_commands.emplace(c);
            }
        }
    }
    for (auto&& [ename, e] : context.extensions) {
        for (auto&& c : e.commands) {
            command_to_features[c].push_back(ename);

            auto xcommand = context.GetCommand(c);
            if (global_commands.contains(c)) {
                continue;
            }

            if (xcommand.IsGlobal(context)) {
                global_commands.emplace(c);
                continue;
            }
            if (xcommand.IsDevice(context)) {
                device_commands.emplace(c);
                continue;
            }
            if (xcommand.IsInstance(context)) {
                instance_commands.emplace(c);
            }
        }
    }
    // Global commands
    output += MakeGlobalCommands(global_commands, command_to_features);
    output += "\n";

    // Instance commands
    output += MakeInstanceCommands(instance_commands, command_to_features);
    output += "\n";

    // Device commands
    output += MakeDeviceCommands(device_commands, command_to_features);
    output += "\n";

    stream << output + "}\n";
}

std::string wis::Generator::MakeHandleTraits(const Context& context)
{
    std::string output;
    std::unordered_map<std::string_view, std::vector<std::string_view>> handle_to_ext;
    handle_to_ext.reserve(context.handles.size());
    std::vector<std::string_view> to_erase;

    for (auto&& [fname, f] : context.features) {
        for (auto&& h : f.handles) {
            handle_to_ext[h].push_back(fname);
        }
    }
    for (auto&& [ename, e] : context.extensions) {
        for (auto&& h : e.handles) {
            handle_to_ext[h].push_back(ename);
        }
    }

    for (auto& [hname, extst] : handle_to_ext) {
        if (extst.size() == 1) {
            continue;
        }
        auto& handle = context.handles.at(hname);
        output += "#if ";
        for (auto& i : extst) {
            output += wis::format("defined({}) || ", i);
        }
        output.pop_back();
        output.pop_back();
        output.pop_back();

        output += wis::format("\n{}\n#endif\n\n", MakeHandleTrait(handle));
        to_erase.push_back(hname);
    }
    for (auto& i : to_erase | std::views::reverse) {
        handle_to_ext.erase(i);
    }

    for (auto&& [fname, f] : context.features) {
        if (f.handles.empty()) {
            continue;
        }
        output += wis::format("#ifdef {}\n", fname);
        for (auto hname : f.handles) {
            if (!handle_to_ext.contains(hname)) {
                continue;
            }
            auto& handle = context.handles.at(hname);
            output += wis::format("{}\n", MakeHandleTrait(handle));
        }
        output += "#endif\n\n";
    }
    for (auto&& [fname, f] : context.extensions) {
        if (f.handles.empty()) {
            continue;
        }
        output += wis::format("#ifdef {}\n", fname);
        for (auto hname : f.handles) {
            if (!handle_to_ext.contains(hname)) {
                continue;
            }
            auto& handle = context.handles.at(hname);
            output += wis::format("{}\n", MakeHandleTrait(handle));
        }
        output += "#endif\n\n";
    }
    return output;
}

std::string wis::Generator::MakeHandleTrait(const Handle& handle)
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
