#include <iostream>
#include <span>
#include <string>
#include <vector>
#include <fstream>
#include <array>

#include "format.h"
#include "generator.h"
#include "local_gen.h"

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

void FormatFiles(std::span<const char* const> files)
{
    if (clang_format_exe.empty()) {
        return;
    }
    std::string cmd;
    for (auto f : files) {
        cmd += f;
        cmd += ' ';
    }
    std::cout << "Wisdom Vk Utils: Formatting:\n"
              << cmd << '\n';
    std::string command = wis::format("\"{}\" -i --style=file {}", clang_format_exe, cmd);
    if (int ret = std::system(command.c_str()); ret != 0) {
        std::cout << "Wisdom Vk Utils: failed to format files with error <" << ret << ">\n";
    }
}

int GenerateAPI(tinyxml2::XMLDocument&& doc)
{
    try {
        constexpr std::array files{ OUTPUT_FOLDER "/vk_handle_traits.hpp", OUTPUT_FOLDER "/vk_loader.hpp", OUTPUT_FOLDER "/vk_movable.hpp" };

        std::cout << "Parsing...\n";
        wis::Context ctx(doc);
        std::cout << "Generating...\n";
        std::ofstream out_managed(files[0]);
        if (!out_managed.is_open()) {
            std::cout << "Wisdom Vk Utils: Failed to open output file\n";
            return -1;
        }

        wis::Generator gen;
        gen.GenerateHandleTraits(ctx, out_managed);

        std::ofstream out_move(files[2]);
        if (!out_move.is_open()) {
            std::cout << "Wisdom Vk Utils: Failed to open output file\n";
            return -1;
        }

        gen.GenerateMovableHandles(ctx, out_move);

        std::ofstream out_loader(files[1]);
        if (!out_loader.is_open()) {
            std::cout << "Wisdom Vk Utils: Failed to open output file\n";
            return -1;
        }

        gen.GenerateLoader(ctx, out_loader);

        out_move.close();
        out_managed.close();
        out_loader.close();
        FormatFiles(files);

    } catch (const std::exception& e) {
        std::cout << "Wisdom Vk Utils: Exception: " << e.what() << '\n';
        return -1;
    } catch (...) {
        std::cout << "Wisdom Vk Utils: Unknown exception\n";
        return -1;
    }
    return 0;
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

    if (args.size() == 1)
        return GenerateAPI(std::move(doc));

    std::filesystem::path output;
    std::filesystem::path input;
    bool local = false;

    for (int a = 0; a < args.size(); a++) {
        auto i = args[a];
        if (i == "-h" || i == "--help") {
            std::cout << "Wisdom Vk Utils: Usage: <executable> [-h|--help]\n";
            return 0;
        }

        if (i == "--local" || i == "-l") {
            local = true;
            continue;
        }

        if (i == "--input" || i == "-i") {
            if (args.size() < a + 1) {
                std::cout << "Wisdom Vk Utils: Missing input file\n";
                return -1;
            }
            try {
                input = args[a + 1];
            } catch (const std::exception& e) {
                std::cout << "Wisdom Vk Utils: Exception: " << e.what() << '\n';
                return -1;
            }
            continue;
        }

        if (i == "--output" || i == "-o") {
            if (args.size() < a + 1) {
                std::cout << "Wisdom Vk Utils: Missing output file\n";
                return -1;
            }
            try {
                output = args[a + 1];
            } catch (const std::exception& e) {
                std::cout << "Wisdom Vk Utils: Exception: " << e.what() << '\n';
                return -1;
            }
            continue;
        }
    }

    if (local && !input.empty() && !output.empty()) {
        wis::LocalGenParser parser;
        if (int ret = parser.Parse(input); ret != 0) {
            std::cout << "Wisdom Vk Utils: Failed to parse local file\n";
            return -1;
        }

        std::ofstream out(output);
        if (!out.is_open()) {
            std::cout << "Wisdom Vk Utils: Failed to open output file\n";
            return -1;
        }

        parser.GenerateSubsetTables(wis::Context(doc), out);
        out.close();

        std::string output_str = output.string();
        std::array<const char*, 1> files{ output_str.c_str() };
        FormatFiles(files);
    } else {
        std::cout << "Wisdom Vk Utils: Invalid arguments\n";
        return -1;
    }

    return 0;
}