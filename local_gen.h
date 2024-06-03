#pragma once
#include <filesystem>
#include <span>
#include <string>
#include <unordered_set>
#include <map>
#include <set>
#include "util.h"


namespace wis {
class Context;
class LocalGenParser
{
public:
    LocalGenParser() = default;
    int Parse(std::filesystem::path p); // returns 0 on success
    void GenerateSubsetTables(const wis::Context& context, std::ostream& stream);

private:
    std::unordered_set<std::string> m_optional;
    std::map<std::string, std::unordered_set<std::string, string_hash>> m_tables;
};

} // namespace wis