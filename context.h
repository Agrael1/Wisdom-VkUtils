#pragma once
#include <tinyxml2.h>
#include <stdexcept>
#include <vector>
#include <unordered_map>
#include <string>

namespace wis {
struct Command {
};

class Context
{
public:
    Context(const tinyxml2::XMLDocument& doc)
    {
        auto* registry = doc.FirstChildElement("registry");
        if (!registry)
            throw std::runtime_error("No registry element found in the document");

        ReadRegistry(*registry);
    }

private:
    void ReadRegistry(const tinyxml2::XMLElement& registry)
    {
        for (auto child = registry.FirstChildElement(); child != nullptr; child = child->NextSiblingElement()) {
            std::string_view value = child->Value();
            if (value == "types") {
                ReadTypes(*child);
            }
            if (value == "commands") {
                ReadCommands(*child);
            }
        }
    }
    void ReadTypes(const tinyxml2::XMLElement& types)
    {
        for (auto child = types.FirstChildElement(); child != nullptr; child = child->NextSiblingElement()) {
            std::string_view value = child->Value();
            if (value == "type") {
                ReadType(*child);
            }
        }
    }
    void ReadType(const tinyxml2::XMLElement& type)
    {
        auto attributes = GetAttributes(type);
        auto category = attributes.find("category");
        if (category == attributes.end() || category->second != "handle")
            return;

        if (attributes.contains("alias")) {
            handle_aliases[attributes["alias"]] = attributes["name"];
        }

        auto parent = attributes.find("parent");
        std::string_view parent_name = parent != attributes.end() ? parent->second : "";
        auto name = type.FirstChildElement("name");
        if (name == nullptr)
            throw std::runtime_error("Type without name");

        handle_parents[name->GetText()] = parent_name;
    }

    // Commands
    void ReadCommands(const tinyxml2::XMLElement& commands)
    {
        for (auto child = commands.FirstChildElement(); child != nullptr; child = child->NextSiblingElement()) {
            std::string_view value = child->Value();
            if (value == "command") {
                ReadCommand(*child);
            }
        }
    }
    void ReadCommand(const tinyxml2::XMLElement& command)
    {
        auto attributes = GetAttributes(command);
        // parse alias
        if (auto alias_it = attributes.find("alias"); alias_it != attributes.end()) {
            auto name = attributes.find("name");
            if (name == attributes.end())
                throw std::runtime_error("Alias without name");

            command_aliases[alias_it->second] = name->second;
            return;
        }

        // parse command
        for (auto child = command.FirstChildElement(); child != nullptr; child = child->NextSiblingElement()) {
            std::string_view value = child->Value();
            if (value == "proto") {
                auto name = child->FirstChildElement("name");
                if (!name)
                    throw std::runtime_error("Command without name");
                command_names.emplace_back(name->GetText());
            }
        }
    }
    static std::unordered_map<std::string_view, std::string_view> GetAttributes(const tinyxml2::XMLElement& element) noexcept
    {
        std::unordered_map<std::string_view, std::string_view> attributes;
        for (auto* attribute = element.FirstAttribute(); attribute != nullptr; attribute = attribute->Next()) {
            attributes[attribute->Name()] = attribute->Value();
        }
        return attributes;
    }

public:
    std::unordered_map<std::string_view, std::string_view> handle_parents;
    std::unordered_map<std::string_view, std::string_view> handle_aliases;
    std::unordered_map<std::string_view, std::string_view> command_aliases;
    std::vector<std::string_view> command_names;
};
} // namespace wis