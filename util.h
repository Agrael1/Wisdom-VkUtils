#pragma once
#include <span>
#include <string>

namespace wis {
struct FeatureHash {
    std::size_t operator()(const std::span<const std::string_view>& k) const noexcept
    {
        std::size_t hash = 0;
        for (auto& i : k) {
            hash ^= std::hash<std::string_view>()(i);
        }
        return hash;
    }
};

struct FeatureEqual {
    bool operator()(const std::span<const std::string_view>& lhs, const std::span<const std::string_view>& rhs) const
    {
        return lhs.size() == rhs.size() && std::equal(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
    }
};

struct string_hash {
    using is_transparent = void;
    [[nodiscard]] size_t operator()(const char* txt) const
    {
        return std::hash<std::string_view>{}(txt);
    }
    [[nodiscard]] size_t operator()(std::string_view txt) const
    {
        return std::hash<std::string_view>{}(txt);
    }
    [[nodiscard]] size_t operator()(const std::string& txt) const
    {
        return std::hash<std::string>{}(txt);
    }
};
} // namespace wis
