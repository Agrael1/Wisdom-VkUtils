#include "context.h"
#include <ranges>

wis::Context::Context(const tinyxml2::XMLDocument& doc)
{
    auto* registry = doc.FirstChildElement("registry");
    if (!registry)
        throw std::runtime_error("No registry element found in the document");

    ReadRegistry(*registry);
    ComposeHandleInfo();
}

void wis::Context::ReadRegistry(const tinyxml2::XMLElement& registry)
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

void wis::Context::ReadExtensions(const tinyxml2::XMLElement& extensions)
{
    for (auto child = extensions.FirstChildElement(); child != nullptr; child = child->NextSiblingElement()) {
        std::string_view value = child->Value();
        if (value == "extension") {
            ReadExtension(*child);
        }
    }
}

void wis::Context::ReadExtension(const tinyxml2::XMLElement& extension)
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

void wis::Context::ReadTypes(const tinyxml2::XMLElement& types)
{
    for (auto child = types.FirstChildElement(); child != nullptr; child = child->NextSiblingElement()) {
        std::string_view value = child->Value();
        if (value == "type") {
            ReadType(*child);
        }
    }
}

void wis::Context::ReadType(const tinyxml2::XMLElement& type)
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

void wis::Context::ReadCommands(const tinyxml2::XMLElement& commands)
{
    for (auto child = commands.FirstChildElement(); child != nullptr; child = child->NextSiblingElement()) {
        std::string_view value = child->Value();
        if (value == "command") {
            ReadCommand(*child);
        }
    }
}

void wis::Context::ReadCommand(const tinyxml2::XMLElement& command)
{
    auto attributes = GetAttributes(command);
    // parse alias
    if (auto alias_it = attributes.find("alias"); alias_it != attributes.end()) {
        auto name = attributes.find("name");
        if (name == attributes.end())
            throw std::runtime_error("Alias without name");

        command_aliases[name->second] = alias_it->second;
        return;
    }

    // parse command
    Command cmd;

    for (auto child = command.FirstChildElement(); child != nullptr; child = child->NextSiblingElement()) {
        std::string_view value = child->Value();
        if (value == "proto") {
            auto name = child->FirstChildElement("name");
            if (!name)
                throw std::runtime_error("Command without name");
            cmd.name = name->GetText();
        }
        if (value == "param") {
            auto type = child->FirstChildElement("type");
            if (!type)
                break;

            cmd.param_types.emplace_back(type->GetText());
        }
    }

    commands[cmd.name] = cmd;
}

// Features

void wis::Context::ReadFeature(const tinyxml2::XMLElement& feature)
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

void wis::Context::ReadRequire(const tinyxml2::XMLElement& require, Feature& feature)
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

void wis::Context::ComposeHandleInfo()
{
    // Create all handles
    for (auto& [name, parent] : handle_parents) {
        auto& xhandle = handles[name];
        xhandle.name = name;
    }

    // Set parents
    for (auto& [name, parent] : handle_parents) {
        auto& xhandle = handles[name];
        if (parent.empty())
            continue;
        xhandle.parent = &handles[parent];
    }

    // Search for destruction commands
    for (auto& [name, command] : commands) {
        // Free
        auto substr = name.substr(2, 4);
        if (substr == "Free") {
            auto& destroy_parent = handles[command.param_types[0]];
            auto dhandle = std::ranges::find_if(std::views::reverse(command.param_types), [this](std::string_view a) { return handles.contains(a); });
            if (dhandle == command.param_types.rend())
                throw std::runtime_error("Free command without handle parameter");

            auto& destroy_handle = handles[*dhandle];
            destroy_handle.destroy_command = &command;
            destroy_handle.destroy_parent = destroy_handle.name == destroy_parent.name ? nullptr : &destroy_parent;

            if (auto it = std::ranges::find(command.param_types, "uint32_t"); it != command.param_types.end()) {
                destroy_handle.pool = &handles[*--it];
            }
            continue;
        }

        substr = name.substr(2, 7);
        if (substr == "Destroy" || substr == "Release") {
            auto& destroy_parent = handles[command.param_types[0]];

            auto dhandle = std::ranges::find_if(std::views::reverse(command.param_types), [this](std::string_view a) { return handles.contains(a); });
            if (dhandle == command.param_types.rend())
                throw std::runtime_error("Free command without handle parameter");

            auto& destroy_handle = handles[*dhandle];
            if (destroy_handle.destroy_command != nullptr)
                continue; // already set (Free command)

            destroy_handle.destroy_command = &command;
            destroy_handle.destroy_parent = destroy_handle.name == destroy_parent.name ? nullptr : &destroy_parent;
        }
    }
}

bool wis::Command::is_global(const Context& ctx) const noexcept
{
    for (auto& i : param_types) {
        if (ctx.handles.contains(i)) {
            return false;
        }
    }
    return true;
}
