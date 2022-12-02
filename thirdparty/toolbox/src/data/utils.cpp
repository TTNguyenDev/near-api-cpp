/*!
 * toolbox.
 * utils.cpp
 *
 * \date 11/30/2019
 * \author Eduard Maximovich (edward.vstock@gmail.com)
 * \link   https://github.com/edwardstock
 */

#include "toolbox/data/utils.h"

#include <iomanip>
#include <sstream>

std::vector<uint8_t> toolbox::data::hex_to_bytes(const std::string& hex) {
    std::vector<uint8_t> bytes;

    for (size_t i = 0; i < hex.length(); i += 2) {
        std::string byteString = hex.substr(i, 2);
        auto byte = (uint8_t) strtol(byteString.c_str(), nullptr, 16);
        bytes.push_back(byte);
    }

    return bytes;
}

std::string toolbox::data::bytes_to_hex(const uint8_t* data, size_t len) {
    std::stringstream ss;
    ss << std::hex;
    for (size_t i = 0; i < len; ++i) {
        ss << std::setw(2) << std::setfill('0') << (int) data[i];
    }

    return ss.str();
}

std::string toolbox::data::to_ascii(const std::vector<char>& input) {
    return std::string(input.begin(), input.end());
}
std::string toolbox::data::to_ascii(const std::vector<uint8_t>& input) {
    return std::string(input.begin(), input.end());
}

std::vector<char> toolbox::data::to_chars(const std::vector<uint8_t>& input) {
    std::vector<char> out;
    out.reserve(input.size());
    std::for_each(input.begin(), input.end(), [&out](const uint8_t& val) {
        out.push_back(static_cast<char>(val));
    });

    return out;
}

std::vector<uint8_t> toolbox::data::to_bytes(const std::vector<char>& input) {
    std::vector<uint8_t> out;
    out.reserve(input.size());
    std::for_each(input.begin(), input.end(), [&out](const char& val) {
        out.push_back(static_cast<uint8_t>(val));
    });

    return out;
}

std::vector<uint8_t> toolbox::data::to_bytes(const char* data, size_t len) {
    std::vector<char> tmp(data, data + len);
    return std::vector<uint8_t>(tmp.begin(), tmp.end());
}

std::vector<uint8_t> toolbox::data::to_bytes(std::string input) {
    std::vector<uint8_t> out(input.size());
    std::copy(input.begin(), input.end(), out.begin());
    input.clear();

    return out;
}
