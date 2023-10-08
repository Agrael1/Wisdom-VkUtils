#include "generator.h"
#include "format.h"
#include <ostream>
#include <ranges>

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
namespace wis {
struct VulkanTable
{
)" };

    std::unordered_map<std::string_view, std::vector<std::string_view>> command_to_features;
    command_to_features.reserve(context.commands.size());
    std::vector<std::string_view> to_erase;

    for (auto&& [fname, f] : context.features) {
        for (auto&& c : f.commands) {
            command_to_features[c].push_back(fname);
        }
    }
    for (auto&& [ename, e] : context.extensions) {
        for (auto&& c : e.commands) {
            command_to_features[c].push_back(ename);
        }
    }

    std::span<std::string_view> last_features{};
    std::string accumulator;

    for (auto& [cname, extst] : command_to_features) {
        if (extst.size() == 1) {
            continue;
        }

        if ((last_features.size() != extst.size() || !std::equal(last_features.begin(), last_features.end(), extst.begin())) && !last_features.empty()) {
            output += wis::format("#if ");
            for (auto& i : last_features) {
                output += wis::format("defined({}) || ", i);
            }
            output.pop_back();
            output.pop_back();
            output.pop_back();
            output += "\n";

            output += wis::format("{}#endif\n\n", accumulator);
            accumulator.clear();
        }
        last_features = extst;
        accumulator += wis::format("PFN_{} {};\n", cname, cname);

        to_erase.push_back(cname);
    }
    for (auto& i : to_erase | std::views::reverse) {
        command_to_features.erase(i);
    }

    for (auto&& [fname, f] : context.features) {
        if (f.commands.empty()) {
            continue;
        }
        output += wis::format("#ifdef {}\n", fname);
        for (auto cname : f.commands) {
            if (!command_to_features.contains(cname)) {
                continue;
            }

            output += wis::format("PFN_{} {};\n", cname, cname);
        }
        output += "#endif\n\n";
    }
    for (auto&& [fname, f] : context.extensions) {
        if (f.commands.empty()) {
            continue;
        }
        output += wis::format("#ifdef {}\n", fname);
        for (auto cname : f.commands) {
            if (!command_to_features.contains(cname)) {
                continue;
            }

            output += wis::format("PFN_{} {};\n", cname, cname);
        }
        output += "#endif\n\n";
    }

    /*for (auto& [cname, _] : context.commands) {
        output += wis::format("PFN_{} {};\n", cname, cname);
    }*/

    stream << output + "};\n}\n";
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
