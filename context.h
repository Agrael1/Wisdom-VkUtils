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
            } else if (value == "commands") {
                ReadCommands(*child);
            } else if (value == "feature") {
                ReadFeature(*child);
            } else if (value == "extensions") {
                ReadExtensions(*child);
            }
        }
    }
    void ReadExtensions(const tinyxml2::XMLElement& extensions)
    {
        for (auto child = extensions.FirstChildElement(); child != nullptr; child = child->NextSiblingElement()) {
            std::string_view value = child->Value();
            if (value == "extension") {
                ReadExtension(*child);
            }
        }
    }
    void ReadExtension(const tinyxml2::XMLElement& extension)
    {
        auto attributes = GetAttributes(extension);
        auto name = attributes.find("name");
        if (name == attributes.end())
            throw std::runtime_error("Extension without name");

        auto& extensionx = this->extensions[name->second];
        for (auto child = extension.FirstChildElement("require"); child != nullptr; child = child->NextSiblingElement("require")) {
            std::string_view value = child->Value();
            ReadRequire(*child, extensionx);
        }
    }

    // Types
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
            return;
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

    // Features
    void ReadFeature(const tinyxml2::XMLElement& feature)
    {
        auto attributes = GetAttributes(feature);
        auto name = attributes.find("name");
        if (name == attributes.end())
            throw std::runtime_error("Feature without name");

        auto& featurex = features[name->second];
        for (auto child = feature.FirstChildElement("require"); child != nullptr; child = child->NextSiblingElement("require")) {
            std::string_view value = child->Value();
            ReadRequire(*child, featurex);
        }
    }
    void ReadRequire(const tinyxml2::XMLElement& require, Feature& feature)
    {
        for (auto child = require.FirstChildElement("command"); child != nullptr; child = child->NextSiblingElement("command")) {
            auto name = child->FindAttribute("name");
            feature.commands.emplace_back(name->Value());
        }
        for (auto child = require.FirstChildElement("type"); child != nullptr; child = child->NextSiblingElement("type")) {
            std::string_view name = child->FindAttribute("name")->Value();
            if (handle_parents.contains(name) || handle_aliases.contains(name))
                feature.handles.emplace_back(name);
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
    std::unordered_map<std::string_view, Feature> features;
    std::unordered_map<std::string_view, Feature> extensions;
    std::vector<std::string_view> command_names;
};
} // namespace wis