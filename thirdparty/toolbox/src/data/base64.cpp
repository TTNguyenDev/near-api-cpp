/*!
 * toolbox.
 * base64.cpp
 *
 * \date 2019
 * \author Eduard Maximovich (edward.vstock@gmail.com)
 * \link   https://github.com/edwardstock
 */

#include "toolbox/data/base64.h"

#include "toolbox/data/utils.h"

#include <cctype>

bool toolbox::data::is_base64(uint8_t c) {
    return (isalnum(c) || (c == '+') || (c == '/'));
}

std::string toolbox::data::get_base64_chars() {
    static std::string val = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                             "abcdefghijklmnopqrstuvwxyz"
                             "0123456789+/";

    return val;
}

std::string toolbox::data::base64_encode(const std::string& raw_string) {
    std::vector<uint8_t> tmp = to_bytes(raw_string);
    const uint8_t* bytes_to_encode = tmp.data();
    size_t in_len = tmp.size();

    std::string ret;
    int i = 0;
    int j = 0;
    uint8_t char_array_3[3];
    uint8_t char_array_4[4];

    while (in_len--) {
        char_array_3[i++] = *(bytes_to_encode++);
        if (i == 3) {
            char_array_4[0] = (char_array_3[0] & 0xFCu) >> 2u;
            char_array_4[1] = ((char_array_3[0] & 0x03u) << 4u) + ((char_array_3[1] & 0xF0u) >> 4u);
            char_array_4[2] = ((char_array_3[1] & 0x0fu) << 2u) + ((char_array_3[2] & 0xc0u) >> 6u);
            char_array_4[3] = char_array_3[2] & 0x3Fu;

            for (i = 0; (i < 4); i++)
                ret += get_base64_chars()[char_array_4[i]];
            i = 0;
        }
    }

    if (i) {
        for (j = i; j < 3; j++)
            char_array_3[j] = '\0';

        char_array_4[0] = (char_array_3[0] & 0xfcu) >> 2u;
        char_array_4[1] = ((char_array_3[0] & 0x03u) << 4u) + ((char_array_3[1] & 0xf0u) >> 4u);
        char_array_4[2] = ((char_array_3[1] & 0x0fu) << 2u) + ((char_array_3[2] & 0xc0u) >> 6u);
        char_array_4[3] = char_array_3[2] & 0x3fu;

        for (j = 0; (j < i + 1); j++)
            ret += get_base64_chars()[char_array_4[j]];

        while ((i++ < 3))
            ret += '=';
    }

    return ret;
}

std::string toolbox::data::base64_decode(const std::string& encoded_string) {
    int in_len = encoded_string.size();
    int i = 0;
    int j = 0;
    int in_ = 0;
    unsigned char char_array_4[4], char_array_3[3];
    std::string ret;

    while (in_len-- && (encoded_string[in_] != '=') && is_base64(encoded_string[in_])) {
        char_array_4[i++] = encoded_string[in_];
        in_++;
        if (i == 4) {
            for (i = 0; i < 4; i++)
                char_array_4[i] = get_base64_chars().find(char_array_4[i]);

            char_array_3[0] = (char_array_4[0] << 2u) + ((char_array_4[1] & 0x30u) >> 4u);
            char_array_3[1] = ((char_array_4[1] & 0xfu) << 4u) + ((char_array_4[2] & 0x3cu) >> 2u);
            char_array_3[2] = ((char_array_4[2] & 0x3u) << 6u) + char_array_4[3];

            for (i = 0; (i < 3); i++)
                ret += char_array_3[i];
            i = 0;
        }
    }

    if (i) {
        for (j = i; j < 4; j++)
            char_array_4[j] = 0;

        for (j = 0; j < 4; j++)
            char_array_4[j] = get_base64_chars().find(char_array_4[j]);

        char_array_3[0] = (char_array_4[0] << 2u) + ((char_array_4[1] & 0x30u) >> 4u);
        char_array_3[1] = ((char_array_4[1] & 0xfu) << 4u) + ((char_array_4[2] & 0x3cu) >> 2u);
        char_array_3[2] = ((char_array_4[2] & 0x3u) << 6u) + char_array_4[3];

        for (j = 0; (j < i - 1); j++)
            ret += char_array_3[j];
    }

    return ret;
}

std::vector<uint8_t> toolbox::data::base64_encode_bytes(const std::vector<uint8_t>& raw) {
    return to_bytes(base64_encode(to_ascii(raw)));
}
std::vector<uint8_t> toolbox::data::base64_decode_bytes(const std::vector<uint8_t>& encoded) {
    return to_bytes(base64_decode(to_ascii(encoded)));
}
std::vector<uint8_t> toolbox::data::base64_encode_chars(const std::vector<char>& raw) {
    return to_bytes(base64_encode(to_ascii(raw)));
}
std::vector<uint8_t> toolbox::data::base64_decode_chars(const std::vector<char>& encoded) {
    return to_bytes(base64_decode(to_ascii(encoded)));
}
