/*!
 * toolbox.
 * bytes_buffer.cpp
 *
 * \date 11/30/2019
 * \author Eduard Maximovich (edward.vstock@gmail.com)
 * \link   https://github.com/edwardstock
 */

#include "toolbox/data/bytes_buffer.h"

using namespace toolbox::data;
bytes_buffer::bytes_buffer()
    : bytes_data() {
}
bytes_buffer::bytes_buffer(const basic_data& other)
    : bytes_data(other) {
}
bytes_buffer::bytes_buffer(basic_data&& other)
    : bytes_data(std::move(other)) {
}
bytes_buffer::bytes_buffer(size_t size)
    : bytes_data(size) {
}
bytes_buffer::bytes_buffer(std::initializer_list<uint8_t> ilist)
    : bytes_data(ilist) {
}
bytes_buffer::bytes_buffer(std::initializer_list<std::vector<uint8_t>> ilist)
    : bytes_data(ilist) {
}
bytes_buffer::bytes_buffer(std::vector<uint8_t> data)
    : bytes_data(std::move(data)) {
}
bytes_buffer::bytes_buffer(const uint8_t* data, size_t len)
    : bytes_data(data, len) {
}
bytes_buffer::bytes_buffer(const char* hexString)
    : bytes_data(hexString) {
}
bytes_buffer::bytes_buffer(const std::string& hexString)
    : bytes_data(hexString) {
}

size_t bytes_buffer::pop_front_to(size_t outPosition, basic_data<uint8_t>& out) {
    if (outPosition >= out.size()) {
        throw std::out_of_range("'outPosition' is >= than 'out' size");
    }
    return pop_front_to(out.size() - outPosition, outPosition, out);
}
size_t bytes_buffer::pop_front_to(size_t readLength, size_t position, basic_data<uint8_t>& out) {
    return pop_front_to(readLength, out.begin() + position, out);
}
size_t bytes_buffer::pop_back_to(basic_data<uint8_t>& out) {
    return pop_back_to(out.size(), out);
}
size_t bytes_buffer::pop_back_to(size_t readLength, basic_data<uint8_t>& out) {
    if (readLength == 0 || out.empty() || empty()) {
        return 0;
    }
    size_t s = std::min(readLength, size());
    s = std::min(s, out.size());

    auto data = take_range_from(size() - s);
    out.write(0, std::move(data));

    int64_t resizeLen = size() - readLength;
    if (resizeLen < 0) {
        resize(0);
        return s;
    }
    resize(resizeLen);
    return s;
}

size_t bytes_buffer::pop_front_to(size_t readLength, bytes_data::iterator position, basic_data<uint8_t>& out) {
    if (readLength == 0 || out.empty() || empty()) {
        return 0;
    }

    size_t s = readLength;
    if (readLength >= size()) {
        s = size();
    }

    if (s > out.size()) {
        s = out.size();
    }

    auto it = std::distance(out.begin(), position);
    for (size_t i = 0; i < s; i++) {
        out[i + it] = bytes_data::m_data.at(i);
    }

    // if we have read full buffer, than cleanup this
    if (s == size()) {
        clear();
        resize(0);
    } else {
        // otherwise, taking begin()+s + end() and rewrite this with new vector
        auto newData = std::vector<uint8_t>(bytes_data::m_data.begin() + s, bytes_data::m_data.end());
        clear();
        resize(newData.size());
        bytes_data::m_data = std::move(newData);
    }

    return s;
}
