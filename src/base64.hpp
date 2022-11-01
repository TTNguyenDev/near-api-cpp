#ifndef BASE64_H
#define BASE64_H

#include <span>
#include <vector>
#include <optional>
#include <string>
#include <string_view>

namespace NearCpp
{
    std::string Base64Encode(const std::span<char> data);
    std::optional<std::vector<char>> Base64Decode(const std::string_view data);
}

#endif