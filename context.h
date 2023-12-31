#pragma once
#include <tinyxml2.h>
#include <stdexcept>
#include <vector>
#include <unordered_map>
#include <string>
#include <unordered_set>

namespace wis {

struct Command;
class Context;

struct Feature {
    std::vector<std::string_view> commands;
    std::vector<std::string_view> handles;
};
struct Handle {
    std::string_view name;
    Handle* parent = nullptr;
    Handle* destroy_parent = nullptr;
    Handle* pool = nullptr;
    Command* destroy_command = nullptr;
    std::vector<std::string_view> aliases;

public:
    bool IsChildOf(std::string_view parent_name) const noexcept
    {
        if (name == parent_name)
            return true;

        auto* xparent = this->parent;
        while (xparent) {
            if (xparent->name == parent_name)
                return true;
            xparent = xparent->parent;
        }
        return false;
    }
};

struct Command {
    std::string_view name;
    std::vector<std::string_view> param_types;
    const Handle* GetAttachedHandle(const Context& ctx) const noexcept;
    bool IsGlobal(const Context& ctx) const noexcept { return !GetAttachedHandle(ctx); }
    bool IsInstance(const Context& ctx) const noexcept
    {
        auto* handle = GetAttachedHandle(ctx);
        return handle && handle->IsChildOf("VkInstance");
    }
    bool IsDevice(const Context& ctx) const noexcept
    {
        auto* handle = GetAttachedHandle(ctx);
        return handle && handle->IsChildOf("VkDevice");
    }
};

class Context
{
public:
    Context(const tinyxml2::XMLDocument& doc);

public:
    auto& GetCommand(std::string_view cmd) const
    {
        if (auto it = commands.find(cmd); it != commands.end()) {
            return it->second;
        }
        if (auto it = alias_to_command.find(cmd); it != alias_to_command.end()) {
            return commands.at(it->second);
        }
        throw std::runtime_error("Command not found");
    }
    auto& GetHandle(std::string_view hnd) const
    {
        if (auto it = handles.find(hnd); it != handles.end()) {
            return it->second;
        }
        if (auto it = alias_to_handle.find(hnd); it != alias_to_handle.end()) {
            return handles.at(it->second);
        }
        throw std::runtime_error("Command not found");
    }

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
    std::unordered_map<std::string_view, std::string_view> alias_to_handle;
    std::unordered_map<std::string_view, std::string_view> alias_to_command;

    std::unordered_map<std::string_view, std::vector<std::string_view>> command_to_aliases;

    std::unordered_map<std::string_view, Feature> features;
    std::unordered_map<std::string_view, Feature> extensions;
    std::unordered_map<std::string_view, Command> commands;
    std::unordered_map<std::string_view, Handle> handles;
};
} // namespace wis