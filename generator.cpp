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
    std::string output{ "#pragma once\n"
                        "#include <vulkan/vulkan.h>\n" };
    stream << output;
}

std::string wis::Generator::MakeHandleTraits(const Context& context)
{
    std::string output;
    std::unordered_map<std::string_view, std::vector<std::string_view>> handle_to_ext;
    handle_to_ext.reserve(context.handles.size());

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
        output.insert(output.size() - 4, wis::format("\n{}\n#endif\n\n", MakeHandleTrait(handle)));
        handle_to_ext.erase(hname);
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
            auto& exts = handle_to_ext.at(hname);

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
