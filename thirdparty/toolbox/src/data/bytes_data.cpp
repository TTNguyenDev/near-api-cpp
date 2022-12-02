/*!
 * toolbox.
 * bytes_data.cpp
 *
 * \date 11/30/2019
 * \author Eduard Maximovich (edward.vstock@gmail.com)
 * \link   https://github.com/edwardstock
 */
#include "toolbox/data/bytes_data.h"

#include "toolbox/data/utils.h"

#include <algorithm>
#include <atomic>
#include <cstring>
#include <map>
#include <limits>

using namespace toolbox::data;

bytes_data bytes_data::from_chars(const std::vector<char>& data) {
    return toolbox::data::to_bytes(data);
}

bytes_data bytes_data::from_chars(const char* data, size_t len) {
    return toolbox::data::to_bytes(data, len);
}

bytes_data bytes_data::from_string_raw(const std::string& data) {
    return toolbox::data::to_bytes(data);
}

bytes_data::bytes_data()
    : basic_data<uint8_t>() {
}

bytes_data::bytes_data(const basic_data& other)
    : basic_data<uint8_t>(other) {
}
bytes_data::bytes_data(basic_data&& other)
    : basic_data<uint8_t>(std::move(other)) {
}
bytes_data::bytes_data(size_t size)
    : basic_data<uint8_t>(size) {
}
bytes_data::bytes_data(std::initializer_list<uint8_t> ilist)
    : basic_data<uint8_t>(ilist) {
}
bytes_data::bytes_data(std::initializer_list<std::vector<uint8_t>> ilist)
    : basic_data<uint8_t>(ilist) {
}
bytes_data::bytes_data(std::vector<uint8_t> data)
    : basic_data<uint8_t>(std::move(data)) {
}
bytes_data::bytes_data(const uint8_t* data, size_t len)
    : basic_data<uint8_t>(data, len) {
}
bytes_data::bytes_data(const char* hexString)
    : basic_data<uint8_t>(hex_to_bytes(hexString)) {
}
bytes_data::bytes_data(const std::string& hexString)
    : basic_data<uint8_t>(hex_to_bytes(hexString)) {
}

std::string bytes_data::to_hex() const {
    return bytes_to_hex(data(), size());
}

std::string bytes_data::to_string() const {
    return std::string(begin(), end());
}

size_t bytes_data::write(size_t pos, uint16_t val) {
    return write_batch({{pos + 0, (uint8_t)(val >> 8u)}, {pos + 1, (uint8_t)(val)}});
}
size_t bytes_data::write(size_t pos, int32_t val) {
    return write(pos, static_cast<uint32_t>(val));
}
size_t bytes_data::write(size_t pos, uint32_t val) {
    return write_batch({{pos + 0, (uint8_t)(val >> 24u)},
                        {pos + 1, (uint8_t)(val >> 16u)},
                        {pos + 2, (uint8_t)(val >> 8u)},
                        {pos + 3, (uint8_t)(val)}});
}
size_t bytes_data::write(size_t pos, uint64_t val) {
    return write_batch({
        {pos + 0, (uint8_t)(val >> 56u)},
        {pos + 1, (uint8_t)(val >> 48u)},
        {pos + 2, (uint8_t)(val >> 40u)},
        {pos + 3, (uint8_t)(val >> 32u)},
        {pos + 4, (uint8_t)(val >> 24u)},
        {pos + 5, (uint8_t)(val >> 16u)},
        {pos + 6, (uint8_t)(val >> 8u)},
        {pos + 7, (uint8_t)(val)},
    });
}

size_t bytes_data::write_back(uint16_t val) {
    return write(size(), val);
}
size_t bytes_data::write_back(uint32_t val) {
    return write(size(), val);
}
size_t bytes_data::write_back(uint64_t val) {
    return write(size(), val);
}

size_t bytes_data::write_back(char val) {
    return write_back((uint8_t) val);
}

void bytes_data::push_back(uint8_t val) {
    m_data.push_back(val);
}
void bytes_data::push_back(uint16_t val) {
    m_data.push_back(val >> 8u);
    m_data.push_back(val & 0xFFu);
}
void bytes_data::push_back(uint32_t val) {
    m_data.push_back(val >> 24u);
    m_data.push_back(val >> 16u);
    m_data.push_back(val >> 8u);
    m_data.push_back(val & 0xFFu);
}
void bytes_data::push_back(uint64_t val) {
    m_data.push_back(val >> 56u);
    m_data.push_back(val >> 48u);
    m_data.push_back(val >> 40u);
    m_data.push_back(val >> 32u);
    m_data.push_back(val >> 24u);
    m_data.push_back(val >> 16u);
    m_data.push_back(val >> 8u);
    m_data.push_back(val & 0xFFu);
}

void bytes_data::push_back(char val) {
    push_back((uint8_t) val);
}

void bytes_data::clear() {
    static volatile std::atomic<uint8_t> s_cleanseCounter{0u};
    auto* p = data();
    size_t const len = (uint8_t*) (data() + size()) - p;
    size_t loop = len;
    size_t count = s_cleanseCounter;
    while (loop--) {
        *(p++) = (uint8_t) count;
        count += (17u + ((size_t) p & 0x0Fu));
    }
    p = (uint8_t*) memchr((uint8_t*) data(), (uint8_t) count, len);
    if (p) {
        count += (63u + (size_t) p);
    }

    s_cleanseCounter = (uint8_t) count;
    memset((uint8_t*) data(), 0, len);
}

uint64_t bytes_data::to_num_any() const {
    return to_num_any(0, std::min((size_t) 8, size()));
}
uint64_t bytes_data::to_num_any(size_t from, size_t to) const {
    std::vector<uint8_t> data;
    try {
        data = take_range(from, std::min(from + 8, to));
    } catch (const std::exception& e) {
        return 0ULL;
    }

    size_t len = data.size();
    uint64_t out = 0x0ULL;
    for (uint8_t i = 0, p = len - 1; i < len; i++, p--) {
        out |= data[i] << (8u * p);
    }

    return out;
}
bytes_data::operator uint8_t() const {
    return to_num<uint8_t>();
}
bytes_data::operator char() const {
    return to_num<char>();
}
bytes_data::operator uint16_t() const {
    return to_num<uint16_t>();
}
bytes_data::operator uint32_t() const {
    return to_num<uint32_t>();
}
bytes_data::operator uint64_t() const {
    return to_num<uint64_t>();
}

std::ostream& toolbox::data::operator<<(std::ostream& os, const bytes_data& data) {
    os << data.to_string();
    return os;
}

std::istream& toolbox::data::operator>>(std::istream& input, bytes_data& data) {
    size_t block_read = 256;
    data.resize(256);
    data.reserve(4096);
    data.clear();

    input.read((char*) data.data(), block_read);
    size_t read_len = input.gcount();
    size_t total_read = read_len;
    size_t size_to_read;
    bool overflow = false;
    while (read_len != 0) {
        // LCOV_EXCL_START
        // don't cover edge case
        if (overflow) {
            throw std::runtime_error("Out of memory: can't resize buffer more than SIZE_MAX");
        }
        // LCOV_EXCL_STOP
        size_to_read = data.size();
        // preventing overflow, by subtracting current value, and checking, it's enough space to insert one more size
        if (std::numeric_limits<bytes_data::size_type>::max() - data.size() > data.size()) {
            data.resize(data.size() * 2);
        } else {
            // LCOV_EXCL_START
            overflow = true;
            data.resize(std::numeric_limits<bytes_data::size_type>::max());
            // LCOV_EXCL_STOP
        }

        input.read((char*) data.data() + total_read, size_to_read);
        read_len = input.gcount();
        total_read += read_len;
    }
    data.resize(total_read);
    return input;
}
