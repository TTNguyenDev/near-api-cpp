/*!
 * toolbox.
 * strings.cpp
 *
 * \date 11/30/2019
 * \author Eduard Maximovich (edward.vstock@gmail.com)
 * \link   https://github.com/edwardstock
 */
#include "toolbox/strings.hpp"

#include <exception>
#include <fstream>
#include <istream>
#include <sstream>
#include <stdexcept>

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__) || defined(__MINGW32__) || \
    defined(__MINGW64__)
#define TOOLBOXPP_WIN32 1
#endif

#ifdef _MSC_VER
#include <ctype.h>
#include <tchar.h>
#define __CHAR_TO_LOWER(c) _totlower(c)
#define __CHAR_TO_UPPER(c) _totupper(c)

#ifdef TOOLBOX_ENABLE_MB
#include <clocale>
#include <wchar.h>
#define __WCHAR_TO_LOWER(c) _towlower_l(c, _get_current_locale())
#define __WCHAR_TO_UPPER(c) _towupper_l(c, _get_current_locale())
#endif // TOOLBOX_ENABLE_MB
#else  // other
#define __CHAR_TO_LOWER(c) std::tolower(c)
#define __WCHAR_TO_LOWER(c) std::towlower(c)
#define __CHAR_TO_UPPER(c) std::toupper(c)
#define __WCHAR_TO_UPPER(c) std::towupper(c)
#endif

bool toolbox::strings::has_substring_icase(const std::string& substring, const std::string& source) {
    size_t cmp = compare(source, substring);
    return cmp != std::string::npos;
}

bool toolbox::strings::has_substring(const std::string& substring, const std::string& source) {
    return source.find(substring) != std::string::npos;
}
bool toolbox::strings::has_substring(char substring, const std::string& source) {
    return source.find(substring) != std::string::npos;
}
std::vector<std::string> toolbox::strings::split(const std::string& source, const std::string& delimiter) {
    if (delimiter.empty()) {
        return std::vector<std::string>(0);
    }

    std::string src = source;

    std::vector<std::string> result;
    size_t current = 0;
    while (current != src.npos) {
        current = src.find(delimiter);
        if (current != src.npos && src.substr(current, delimiter.length()) == delimiter) {
            result.push_back(src.substr(0, current));
            src = src.substr(current + (delimiter.length()), src.npos);
        }
    }
    if (src.length() > 0) {
        result.push_back(src);
    }

    return result;
}
std::vector<std::string> toolbox::strings::split(const std::string& source, const char& delimiter) {
    std::stringstream ss;
    ss.str(source);
    std::string item;
    std::vector<std::string> elements;
    while (std::getline(ss, item, delimiter)) {
        elements.push_back(item);
    }

    return elements;
}
std::vector<std::string> toolbox::strings::split_by_len(const std::string& src, size_t max) {
    std::vector<std::string> out;
    if (src.length() > max) {
        size_t got = 0;
        for (size_t i = 0; i < src.length(); i += max) {
            size_t n;
            if (got + max > src.length()) {
                n = src.length() - got;
            } else {
                n = got + max;
                got = n;
            }
            auto part = src.substr(i, n);

            out.push_back(part);
        }
    } else {
        out.push_back(src);
    }

    return out;
}
std::pair<std::string, std::string> toolbox::strings::split_pair(const std::string& source, const char& delimiter) {
    std::vector<std::string> elements = split(source, delimiter);

    if (elements.empty()) {
        return std::pair<std::string, std::string>(std::string(), std::string());
    }

    if (elements.size() == 1) {
        return std::pair<std::string, std::string>(elements.at(0), std::string());
    }

    return std::pair<std::string, std::string>(elements.at(0), elements.at(1));
}
std::pair<std::string, std::string> toolbox::strings::split_pair(const std::string& source,
                                                                 const std::string& delimiter) {
    if (delimiter.empty()) {
        return std::pair<std::string, std::string>(std::string(), std::string());
    }
    return split_pair(source, delimiter.c_str()[0]);
}

std::string toolbox::strings::repeat(const std::string& in, size_t n) {
    std::stringstream ss;
    for (size_t i = 0; i < n; i++) {
        ss << in;
    }

    return ss.str();
}
std::string toolbox::strings::repeat(char in, size_t n) {
    std::stringstream ss;
    for (size_t i = 0; i < n; i++) {
        ss << in;
    }

    return ss.str();
}

std::string toolbox::strings::trim(const std::string& in) {
    std::string out = in;
    trim_ref(out);
    return out;
}
void toolbox::strings::trim_ref(std::string& in) {
    const std::vector<std::string> search{
        "\t", "\n", "\r", "\x0B"};
    const std::vector<std::string> replace{""};
    substr_replace_all(search, replace, in);
}

void toolbox::strings::replace(const std::string& search, const std::string& replace, std::string& source) {
    source = substr_replace_ret(search, replace, source);
}
void toolbox::strings::substr_replace_all(const std::string& search, const std::string& replace, std::string& source) {
    source = substr_replace_all_ret(search, replace, source);
}
void toolbox::strings::substr_replace_all(const std::vector<std::string>& search, const std::vector<std::string>& replace,
                                          std::string& source) {
    source = substr_replace_all_ret(search, replace, source);
}

void toolbox::strings::substr_replace_all(const std::vector<std::string>& search, const std::string& replace, std::string& source) {
    substr_replace_all(search, std::vector<std::string>{replace}, source);
}

std::string toolbox::strings::substr_replace_ret(const std::string& search, const std::string& replace,
                                                 const std::string& source) {
    if (source.empty() || source.length() < search.length()) {
        return source;
    }

    size_t found = source.find(search);
    if (found == std::string::npos) {
        return source;
    }

    std::string begin, end;
    begin = source.substr(0, found);
    end = source.substr(found + search.length(), std::string::npos);
    std::stringstream ss;
    ss << begin << replace << end;

    return ss.str();
}
std::string toolbox::strings::substr_replace_all_ret(const std::string& search, const std::string& replace,
                                                     const std::string& source) {
    std::string result = substr_replace_ret(search, replace, source);
    while (result.find(search) != std::string::npos) {
        result = substr_replace_ret(search, replace, result);
    }

    return result;
}
std::string toolbox::strings::substr_replace_all_ret(const std::vector<std::string>& search,
                                                     const std::vector<std::string>& replace, const std::string& source) {
    std::vector<std::string> toReplace;
    if (replace.size() != search.size() && replace.size() == 1) {
        for (std::size_t i = 0; i < search.size(); i++) {
            toReplace.push_back(replace[0]);
        }
    } else if ((search.size() != replace.size() && replace.size() > 1) || search.empty() || replace.empty()) {
        throw std::invalid_argument("search & replace vectors must be equal size and not empty!");
    } else {
        toReplace = replace;
    }

    std::string result;

    for (size_t i = 0; i < search.size(); i++) {
        result = substr_replace_all_ret(search[i], toReplace[i], i == 0 ? source : result);
    }

    return result;
}

std::string toolbox::strings::substr_replace_all_ret(const std::vector<std::string>& search, const std::string& replace, const std::string& source) {
    return substr_replace_all_ret(search, std::vector<std::string>{replace}, source);
}

void toolbox::strings::substr_remove(std::string& source, const std::string& removable) {
    size_t n = removable.length();

    for (size_t i = source.find(removable); i != std::string::npos; i = source.find(removable)) {
        source.erase(i, n);
    }
}
void toolbox::strings::substr_remove_all(std::string& source, std::vector<std::string> removables) {
    for (auto& replace : removables) {
        substr_remove(source, replace);
    }
}
std::string toolbox::strings::substr_inverse(const std::string& source, char whence) {
    strlen_t from;
    std::string out;
    if (~whence >= 0) {
        from = source.rfind(~whence);
        out = source.substr(from + 1, std::string::npos);
    } else {
        from = source.find(whence);
        out = source.substr(0, from);
    }

    return out;
}
std::string toolbox::strings::substr_inverse(const std::string& source, const std::string& begin, const std::string& end,
                                             long offset) {
    strlen_t to, from = source.find(begin);
    if (from == std::string::npos) {
        from = 0;
    }
    to = source.rfind(end);

    from += -(offset);
    to += 1 + offset;
    std::string out = source.substr(0, from);
    out.append(source.substr(to, std::string::npos));
    return out;
}
std::string toolbox::strings::substr_inverse(const std::string& source, char begin, char end, long offset) {
    return substr_inverse(source, std::string(1, begin), std::string(1, end), offset);
}
std::string toolbox::strings::substr_inverse(const std::string& source, const std::string& begin) {
    strlen_t from = source.find(begin);
    if (from == std::string::npos) {
        from = 0;
    }
    return source.substr(0, from);
}
std::string toolbox::strings::substr_clip(const std::string& source, const std::string& search, size_t width,
                                          bool icase) {
    size_t pos = icase ? compare(source, search) : source.find(search);
    if (pos == std::string::npos) {
        return source;
    }

    size_t searchLength = search.length();
    size_t sourceLength = source.length();

    // if width equals search length, return search string
    if (searchLength == width || sourceLength == searchLength || sourceLength == width) {
        return search;
    }

    // if width size less than search size, return part of search string
    if (width < searchLength || sourceLength < width) {
        return search.substr(0, width);
    }

    long centerOfSearch, centerOfWidth, begin;

    centerOfSearch = pos + (searchLength / 2);
    centerOfWidth = width / 2;

    if (centerOfSearch - centerOfWidth < 0) {
        begin = 0;
    } else {
        begin = centerOfSearch - centerOfWidth;
    }

    return source.substr((size_t) begin, width);
}
std::string toolbox::strings::glue(const std::string& glue, const std::vector<std::string>& strings) {
    std::string out;

    size_t size = strings.size();
    size_t i = 0;
    for (auto& s : strings) {
        if (i == 0 || i == size) {
            out.append(s);
        } else {
            out.append(glue).append(s);
        }

        i++;
    }

    return out;
}
std::string toolbox::strings::to_string(std::ifstream& inputStream) {
    return std::string((std::istreambuf_iterator<char>(inputStream)), std::istreambuf_iterator<char>());
}
std::string toolbox::strings::to_lower_case(const std::string& s) {
    std::stringstream tmp;
    for (char i : s) {
        tmp << static_cast<char>(__CHAR_TO_LOWER(i));
    }

    return tmp.str();
}

std::string toolbox::strings::to_upper_case(const std::string& s) {
    std::stringstream tmp;
    for (char i : s) {
        tmp << static_cast<char>(__CHAR_TO_UPPER(i));
    }

    return tmp.str();
}

bool toolbox::strings::equals_icase(const std::string& s1, const std::string& s2) {
    if (s1.length() != s2.length())
        return false;

    return std::equal(s1.begin(), s1.end(), s2.begin(),
                      [](unsigned char a, unsigned char b) { return __CHAR_TO_LOWER(a) == __CHAR_TO_LOWER(b); });
}
