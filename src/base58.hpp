#ifndef BASE58_H
#define BASE58_H

#include <string>
#include <vector>

namespace NearCpp
{
    extern const uint8_t Base58Map[];
    extern const uint8_t AlphaMap[];

    struct CodecMapping
    {
        CodecMapping(const uint8_t* amap, const uint8_t* bmap) : AlphaMapping(amap), BaseMapping(bmap) {}
        const uint8_t* AlphaMapping;
        const uint8_t* BaseMapping;
    };

    std::string Base58Encode(const std::vector<uint8_t>& data, CodecMapping mapping);
    std::vector<uint8_t> Base58Decode(const std::string& data, CodecMapping mapping);
}

#endif