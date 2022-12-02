/*!
 * toolbox. 2017
 *
 * \author Eduard Maximovich <edward.vstock@gmail.com>
 * \link https://github.com/edwardstock
 */

#include "gtest/gtest.h"
#include <cstdio>
#include <toolbox/io.h>

using namespace toolbox::io;

TEST(IO, ReadWriteExistCheck) {
    char* tmpPath = std::getenv("TMP");
    std::string tmp(tmpPath == nullptr ? "" : tmpPath);
    if (tmp.empty()) {
        tmp = "/tmp";
    }
#ifdef _MSC_VER
    const std::string ds = "\\";
#else
    const std::string ds = "/";
#endif

    std::string targetPath = tmp + ds + "test_file.txt";

    bool written = file_write_string(targetPath, "CONTENT");
    ASSERT_TRUE(written);

    bool exist = file_exists(targetPath);
    ASSERT_TRUE(exist);

    std::string content = file_read_full(targetPath);
    ASSERT_STREQ(content.c_str(), "CONTENT");

    remove(targetPath.c_str());
    ASSERT_FALSE(file_exists(targetPath));
}
