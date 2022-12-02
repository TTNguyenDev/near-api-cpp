/*!
 * toolbox.
 * io.cpp
 *
 * \date 11/30/2019
 * \author Eduard Maximovich (edward.vstock@gmail.com)
 * \link   https://github.com/edwardstock
 */

#include "toolbox/io.h"

#include "toolbox/strings.hpp"

#include <cerrno>
#include <cstring>
#include <fstream>
#include <sys/stat.h>

std::string toolbox::io::file_read_full(const std::string& path) {
    std::ifstream input(path);

    if (!input.is_open()) {
        perror(strerror(errno));
        return "";
    }

    const std::string out = toolbox::strings::to_string(input);
    input.close();
    return out;
}
bool toolbox::io::file_exists(const std::string& path) {
    struct stat s;
    return stat(path.c_str(), &s) == 0;
}
bool toolbox::io::file_write_string(const std::string& path, const std::string& data) {
    std::ofstream out(path);
    if (!out.is_open()) {
        perror(strerror(errno));
        return false;
    }

    out << data;
    out.flush();
    out.close();
    return true;
}
