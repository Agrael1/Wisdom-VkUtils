#include <iostream>
#include <span>
#include <string>
#include <vector>

#include "format.h"
#include "context.h"

constexpr inline std::string_view clang_format_exe = CLANG_FORMAT_EXECUTABLE;
constexpr inline std::string_view vulkan_spec_xml = VK_SPEC;

int main(int argc, const char* argv[])
{
    [[nodiscard]] int better_main(const std::span<const std::string_view> args);
    const size_t buf_size = (argc + 1);

    std::vector<std::string_view> args;
    args.reserve(argc);
    for (int i = 0; i < argc; i++) {
        args.emplace_back(argv[i]);
    }

    return better_main(args);
}

[[nodiscard]] int better_main([[maybe_unused]] const std::span<const std::string_view> args)
{
    if (!clang_format_exe.empty()) {
        std::puts("clang-format executable: " CLANG_FORMAT_EXECUTABLE);
    }

    tinyxml2::XMLDocument doc;
    std::cout << wis::format("Wisdom Vk Utils: Loading {}\n", vulkan_spec_xml);
    tinyxml2::XMLError error = doc.LoadFile(vulkan_spec_xml.data());
    if (error != tinyxml2::XML_SUCCESS) {
        std::cout << wis::format("Wisdom Vk Utils: failed to load file {} with error <{}>", vulkan_spec_xml, std::to_string(error));
        return -1;
    }

    try {
        std::cout << "Parsing...\n";
        wis::Context ctx(doc);


    } catch (const std::exception& e) {
        std::cout << "Wisdom Vk Utils: Exception: " << e.what() << '\n';
        return -1;
    } catch (...) {
        std::cout << "Wisdom Vk Utils: Unknown exception\n";
        return -1;
    }
}

return 0;
}