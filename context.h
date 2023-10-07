#pragma once
#include <tinyxml2.h>
#include <stdexcept>
#include <vector>
#include <unordered_map>
#include <string>

namespace wis {
struct Feature {
    std::vector<std::string_view> commands;
    std::vector<std::string_view> handles;
};
struct Command {
    std::string_view name;
    std::vector<std::string_view> param_types;
};
struct Handle {
    std::string_view name;
    Handle* parent = nullptr;
    Handle* destroy_parent = nullptr;
    Handle* pool = nullptr;
    Command* destroy_command = nullptr;
};

class Context
{
public:
    Context(const tinyxml2::XMLDocument& doc);

private:
    void ReadRegistry(const tinyxml2::XMLElement& registry);
    void ReadExtensions(const tinyxml2::XMLElement& extensions);
    void ReadExtension(const tinyxml2::XMLElement& extension);

    // Types
    void ReadTypes(const tinyxml2::XMLElement& types);
    void ReadType(const tinyxml2::XMLElement& type);

    // Commands
    void ReadCommands(const tinyxml2::XMLElement& commands);
    void ReadCommand(const tinyxml2::XMLElement& command);

    // Features
    void ReadFeature(const tinyxml2::XMLElement& feature);
    void ReadRequire(const tinyxml2::XMLElement& require, Feature& feature);

    static std::unordered_map<std::string_view, std::string_view> GetAttributes(const tinyxml2::XMLElement& element) noexcept
    {
        std::unordered_map<std::string_view, std::string_view> attributes;
        for (auto* attribute = element.FirstAttribute(); attribute != nullptr; attribute = attribute->Next()) {
            attributes[attribute->Name()] = attribute->Value();
        }
        return attributes;
    }

    // Second pass
    void ComposeHandleInfo();

public:
    std::unordered_map<std::string_view, std::string_view> handle_parents;
    std::unordered_map<std::string_view, std::string_view> handle_aliases;
    std::unordered_map<std::string_view, std::string_view> command_aliases;

    std::unordered_map<std::string_view, Feature> features;
    std::unordered_map<std::string_view, Feature> extensions;
    std::unordered_map<std::string_view, Command> commands;
    std::unordered_map<std::string_view, Handle> handles;
};
} // namespace wis