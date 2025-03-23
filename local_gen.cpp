#include "local_gen.h"
#include <unordered_map>
#include <unordered_set>
#include "context.h"
#include "format.h"
#include <array>
#include "util.h"

//////////////////////////////////////////////////////////////////////////

using namespace wis;

static auto SortByFeature(const auto& commands,
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

static std::string MakeGuard(auto& features)
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

static std::string MakeTableNoGuard(auto& feature_blocks, const std::unordered_set<std::string>& optional)
{
    std::string output;
    for (auto& [feature, cmds] : feature_blocks) {
        for (auto& i : cmds) {
            if (optional.contains(std::string{ i })) {
                output += "#if " + MakeGuard(feature) + '\n';
                output += wis::format("PFN_{} {};\n", i, i);
                output += wis::format("#else\n void* {};\n", i);
                output += "#endif\n";
            } else {
                output += wis::format("PFN_{} {};\n", i, i);
            }
        }
    }
    return output;
}

template<size_t size>
static std::string Replace(std::string_view og, const std::array<std::pair<std::string_view, std::string_view>, size>& map)
{
    std::string out{ og };
    for (auto&& [a, b] : map) {
        for (auto pos = out.find(a); pos != std::string::npos; pos = out.find(a)) {
            out.replace(pos, a.length(), b);
        }
    }
    return out;
}

static std::string MakeCommandInit(std::string_view init_format, std::string_view cmd,
                                   std::span<const std::string_view> cmd_features,
                                   const std::unordered_map<std::string_view, std::vector<std::string_view>>& features,
                                   std::span<const std::string_view> aliases)
{
    using mapty = std::pair<std::string_view, std::string_view>;
    std::string output = wis::format("static constexpr std::array {}_strings{{\n", cmd);
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
    output += wis::format("\t\"{}\",\n", cmd);
    output += "#endif\n";

    for (auto&& a : aliases) {
        output += "#if " + MakeGuard(features.at(a)) + '\n';
        output += wis::format("\t\"{}\",\n", a);
        output += "#endif\n";
    }
    output += "};\n";

    output += wis::format("for(auto {}_it : {}_strings)\n if(({}))\n break;\n",
                          cmd,
                          cmd,
                          Replace(init_format, std::array{
                                                       mapty{ "{cmd}", cmd },
                                                       mapty{ "{type}", wis::format("{}_it", cmd) },
                                               }));

    return output;
}

static std::string MakeAliasTypedefs(const std::unordered_map<std::string_view, std::vector<std::string_view>>& features,
                                     const std::unordered_map<std::string_view, std::vector<std::string_view>>& commands_to_aliases)
{
    std::string output;
    for (auto&& [command, aliases] : commands_to_aliases) {
        if (!features.contains(command))
            continue;

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

static std::string MakeGlobalCommands(std::string_view table_name,
                                      const std::unordered_set<std::string_view>& commands,
                                      const std::unordered_set<std::string>& optional,
                                      const std::unordered_map<std::string_view, std::vector<std::string_view>>& features,
                                      const std::unordered_map<std::string_view, std::vector<std::string_view>>& commands_to_aliases)
{
    if (commands.empty())
        return {};

    auto feature_blocks = SortByFeature(commands, features);

    std::string output = wis::format("struct {}Global{{\n{}\npublic:\n", table_name, MakeTableNoGuard(feature_blocks, optional));
    output += "bool Init(LibTokenView token) noexcept{\n";

    for (auto& [feature, cmds] : feature_blocks) {
        for (auto& i : cmds) {
            if (auto it = commands_to_aliases.find(i); it != commands_to_aliases.end()) {
                output += MakeCommandInit("{cmd} = token.GetProcAddress<decltype({cmd})>({type})", i, feature, features, it->second);
            } else {
                output += wis::format("\t{} = token.GetProcAddress<decltype({})>(\"{}\");\n", i, i, i);
            }
            if (!optional.contains(std::string{ i }))
                output += wis::format("\tif({} == nullptr) return false;\n", i);
        }
    }

    return output + "return true;\n}\n};\n";
}

static std::string MakeInstanceCommands(std::string_view table_name,
                                        const std::unordered_set<std::string_view>& commands,
                                        const std::unordered_set<std::string>& optional,
                                        const std::unordered_map<std::string_view, std::vector<std::string_view>>& features,
                                        const std::unordered_map<std::string_view, std::vector<std::string_view>>& commands_to_aliases)
{
    if (commands.empty())
        return {};

    auto feature_blocks = SortByFeature(commands, features);

    std::string output = wis::format("struct {}Instance{{\n{}\npublic:\n", table_name, MakeTableNoGuard(feature_blocks, optional));
    output += "bool Init(VkInstance instance, PFN_vkGetInstanceProcAddr vkGetInstanceProcAddr) noexcept{\n";

    for (auto& [feature, cmds] : feature_blocks) {
        for (auto& i : cmds) {
            if (auto it = commands_to_aliases.find(i); it != commands_to_aliases.end()) {
                output += MakeCommandInit("{cmd} = (PFN_{cmd})vkGetInstanceProcAddr(instance, {type})", i, feature, features, it->second);
            } else {
                output += wis::format("\t{} = (PFN_{})vkGetInstanceProcAddr(instance, \"{}\");\n", i, i, i);
            }
            if (!optional.contains(std::string{ i }))
                output += wis::format("\tif({} == nullptr) return false;\n", i);
        }
    }

    return output + "return true;\n}\n};\n";
}

static std::string MakeDeviceCommands(std::string_view table_name,
                                      const std::unordered_set<std::string_view>& commands,
                                      const std::unordered_set<std::string>& optional,
                                      const std::unordered_map<std::string_view, std::vector<std::string_view>>& features,
                                      const std::unordered_map<std::string_view, std::vector<std::string_view>>& commands_to_aliases)
{
    if (commands.empty())
        return {};

    auto feature_blocks = SortByFeature(commands, features);

    std::string output = wis::format("struct {}Device{{\n{}\npublic:\n", table_name, MakeTableNoGuard(feature_blocks, optional));
    output += "bool Init(VkDevice device, PFN_vkGetDeviceProcAddr vkGetDeviceProcAddr) noexcept{\n";

    for (auto& [feature, cmds] : feature_blocks) {
        for (auto& i : cmds) {
            if (auto it = commands_to_aliases.find(i); it != commands_to_aliases.end()) {
                output += MakeCommandInit("{cmd} = (PFN_{cmd})vkGetDeviceProcAddr(device, {type})", i, feature, features, it->second);
            } else {
                output += wis::format("\t{} = (PFN_{})vkGetDeviceProcAddr(device, \"{}\");\n", i, i, i);
            }
            if (!optional.contains(std::string{ i }))
                output += wis::format("\tif({} == nullptr) return false;\n", i);
        }
    }

    return output + "return true;\n}\n};\n";
}

#include <fstream>

int wis::LocalGenParser::Parse(std::filesystem::path p)
{
    auto clear_entry = [](std::string& s) {
        size_t pos = s.length();
        while (--pos > 0) {
            char c = s[pos];
            if (!isalnum(c) && c != '[' && c != ']' && c != '#') {
                s.erase(pos);
            }
        }
    };

    if (!std::filesystem::exists(p)) {
        return -1;
    }

    std::ifstream in{ p };
    if (!in.is_open()) {
        return -2;
    }

    std::string table_name = "VKTable";
    std::vector<std::string> table{};

    std::string line;
    while (std::getline(in, line)) {
        if (line.empty()) {
            continue;
        }
        clear_entry(line);
        if (line.empty()) {
            continue;
        }
        if (line.starts_with("#")) {
            continue;
        }
        if (line.starts_with("[opt]")) {
            auto opt = line.substr(5);
            m_optional.emplace(opt);
            table.push_back(opt);
            continue;
        }
        if (line.starts_with("[")) {
            auto close = line.find(']');
            if (close == std::string::npos) {
                continue;
            }

            m_tables[table_name] = { table.begin(), table.end() };
            table_name = line.substr(1, close - 1);
            continue;
        }
        table.push_back(line);
    }
    m_tables[table_name] = { table.begin(), table.end() };
    return 0;
}

void wis::LocalGenParser::GenerateSubsetTables(const wis::Context& context, std::ostream& stream)
{
    std::string output{ R"(#pragma once
#ifndef WISVK_MODULE_DECL
#include <array>
#include <vulkan/vulkan.h>
#include <wisvk/vk_libinit.hpp>
#define WISVK_EXPORT
#else
#define WISVK_EXPORT export
#endif // WISVK_MODULE_DECL

WISVK_EXPORT
namespace wis {

)" };

    for (auto& table : m_tables) {
        std::string_view table_name = table.first;
        auto& subset = table.second;

        if (subset.empty())
            continue;

        std::vector<std::string_view> to_erase{};
        std::vector<std::string_view> to_emplace{};

        // filter set
        for (auto& i : subset) {
            if (auto it = context.alias_to_command.find(i); it != context.alias_to_command.end()) {
                to_erase.push_back(i);
                to_emplace.push_back(it->second);
            }
        }
        for (auto& i : to_erase) {
            subset.erase(std::string{ i });
        }
        for (auto& i : to_emplace) {
            subset.emplace(i);
        }
        to_erase.clear();
        for (auto& i : subset) {
            if (!context.commands.contains(i)) {
                to_erase.push_back(i);
            }
        }
        for (auto& i : to_erase) {
            subset.erase(std::string{ i });
        }

        std::unordered_map<std::string_view, std::vector<std::string_view>> command_to_features;
        std::unordered_set<std::string_view> global_commands;
        std::unordered_set<std::string_view> instance_commands;
        std::unordered_set<std::string_view> device_commands;

        if (subset.contains("vkGetInstanceProcAddr")) {
            global_commands.emplace("vkGetInstanceProcAddr");
        }
        if (subset.contains("vkGetDeviceProcAddr")) {
            global_commands.emplace("vkGetDeviceProcAddr");
        }
        if (subset.contains("vkCreateInstance")) {
            global_commands.emplace("vkCreateInstance");
        }

        command_to_features.reserve(context.commands.size());

        for (auto&& [fname, f] : context.features) {
            for (auto&& c : f.commands) {
                auto& xcommand = context.GetCommand(c);
                auto xcommand_name = xcommand.name;

                if (!subset.contains(std::string{ xcommand_name })) {
                    continue;
                }

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

                if (!subset.contains(std::string{ xcommand_name })) {
                    continue;
                }

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

        output += MakeGlobalCommands(table_name, global_commands, m_optional, command_to_features, context.command_to_aliases);
        output += "\n";

        output += MakeInstanceCommands(table_name, instance_commands, m_optional, command_to_features, context.command_to_aliases);
        output += "\n";

        output += MakeDeviceCommands(table_name, device_commands, m_optional, command_to_features, context.command_to_aliases);
        output += "\n";
    }
    output += "}\n";
    stream << output;
}
