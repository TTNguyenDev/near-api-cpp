/*!
 * toolbox.
 * bytes_benchmark.cpp
 *
 * \date 2019
 * \author Eduard Maximovich (edward.vstock@gmail.com)
 * \link   https://github.com/edwardstock
 */
#include "toolbox/data/bytes_data.h"
#include "toolbox/log.h"
#include "toolbox/time_profiler.h"

#include <gtest/gtest.h>

using namespace toolbox::data;

TEST(BenchmarkBytesData, PushBack) {
    bytes_data data;
    toolbox::tlog::get().set_level(toolbox::LEVEL_ALL);
    uint8_t val = (uint8_t) 0xFF;
    const std::string tag = "Pushing back 100m elements";

    toolbox::time_profiler::get().begin(tag);

    for (size_t i = 0; i < 100000000; i++) {
        data.push_back(val);
    }

    toolbox::time_profiler::get().end(tag);
}

TEST(BenchmarkBytesData, WriteBack) {
    bytes_data data;

    using tp = toolbox::time_profiler;
    const std::string tag = "Write back 100m elements";
    const uint8_t val = (uint8_t) 0xFF;
    tp::get().begin(tag);

    for (size_t i = 0; i < 100000; i++) {
        data.write_back(val);
    }

    tp::get().end(tag);
}

TEST(BenchmarkBytesData, WriteBytePosition) {
    bytes_data data;

    const std::string tag = "Write 100m elements";
    const uint8_t val = (uint8_t) 0xFF;
    toolbox::time_profiler::get().begin(tag);

    for (size_t i = 0; i < 100000; i++) {
        data.write(i, val);
    }

    toolbox::time_profiler::get().end(tag);
}

TEST(BenchmarkBytesData, AllocatedWriteBytePosition) {
    bytes_data data(100000);

    using tp = toolbox::time_profiler;
    const std::string tag = "Write 100m elements";
    const uint8_t val = (uint8_t) 0xFF;
    tp::get().begin(tag);

    for (size_t i = 0; i < 100000; i++) {
        data.write(i, val);
    }

    tp::get().end(tag);
}

TEST(BenchmarkBytesData, WriteReservedBytePosition) {
    bytes_data data;
    data.get().reserve(100000);

    const std::string tag = "Write 100m elements";
    const uint8_t val = (uint8_t) 0xFF;
    toolbox::time_profiler::get().begin(tag);

    for (size_t i = 0; i < 100000; i++) {
        data.write(i, val);
    }

    toolbox::time_profiler::get().end(tag);
}