/*!
 * toolbox.
 * log.cpp
 *
 * \date 11/30/2019
 * \author Eduard Maximovich (edward.vstock@gmail.com)
 * \link   https://github.com/edwardstock
 */

#include "toolbox/log.h"

#include "toolbox/strings.hpp"

#include <iomanip>

toolbox::tlog::tlog()
    : out_stream(&std::cout), err_stream(&std::cerr) {
}
std::string toolbox::tlog::level_to_string(toolbox::level_t level) {
    if (!levelMap.count(level)) {
        return "Unknown error!";
    }

    return levelMap[level];
}
toolbox::level_t toolbox::tlog::string_to_level(const std::string& level) {
    for (auto& t : levelMap) {
        if (toolbox::strings::equals_icase(t.second, level)) {
            return t.first;
        }
    }

    return LEVEL_ERROR;
}
bool toolbox::tlog::can_log(toolbox::level_t level) {
    return ((m_level & level) != 0) && (m_buffer_limit == 0 || logs[level].size() <= m_buffer_limit);
}
void toolbox::tlog::set_out_stream(std::ostream* out) {
    out_stream = out;
}
void toolbox::tlog::set_err_stream(std::ostream* out) {
    err_stream = out;
}
void toolbox::tlog::set_level(toolbox::level_t level) {
    m_level = level;
}
void toolbox::tlog::set_level(const std::string& level_s) {
    m_level = string_to_level(level_s);
}
void toolbox::tlog::set_verbosity(toolbox::level_t verbosity) {
    switch (verbosity) {
    case 0:
        set_level(VERBOSITY_0);
        break;
    case 1:
        set_level(VERBOSITY_1);
        break;
    case 2:
        set_level(VERBOSITY_2);
        break;

    default:
        set_level(VERBOSITY_2);
    }
}
void toolbox::tlog::set_datetime_enable(bool enabled) {
    m_print_datetime = enabled;
}
void toolbox::tlog::set_buffer_limit(std::size_t limit) {
    m_buffer_limit = limit;
}
void toolbox::tlog::clear() {
    logs.clear();
}
void toolbox::tlog::flush() {
    std::lock_guard<mutex_t> locker(log_mutex);
    for (auto& levels : logs) {
        while (!levels.second.empty()) {
            if (levels.first > LEVEL_INFO) {
                *err_stream << levels.second.front() << std::endl;
            } else {
                *out_stream << levels.second.front() << std::endl;
            }

            levels.second.pop();
        }
    }
}
void toolbox::tlog::log(toolbox::level_t level, const char* tag, const char* message) {
    log(level, std::string(tag), std::string(message));
}
void toolbox::tlog::log(toolbox::level_t level, const std::string& tag, const std::string& message) {
    if (!can_log(level)) {
        return;
    }
    std::lock_guard<mutex_t> locker(log_mutex);
    std::string out = tag + ": " + message;
    logs[level].push(out);
#ifndef TOOLBOXPP_LOGGER_NO_AUTOFLUSH
    flush();
#endif
}
void toolbox::tlog::log(toolbox::level_t level, const char* file, int line, const char* tag,
                        const char* message) {
    log(level, std::string(file), line, std::string(tag), std::string(message));
}
void toolbox::tlog::log(toolbox::level_t level, const std::string& file, int line, const std::string& tag,
                        const std::string& message) {
    if (!can_log(level)) {
        return;
    }

    std::stringstream out;

    if (m_print_datetime) {
        time_t t = time(nullptr);
        tm* timeinfo = localtime(&t);
        char tbuffer[30];
        strftime(tbuffer, 30, "%Y-%m-%d %T", timeinfo);
        out << "[" << tbuffer << "]";
    }

    out << "[" << std::setw(8) << level_to_string(level) << "] ";

    if (level < LEVEL_ERROR) {
        out << tag << ": " << message;
    } else {
        out << tag << ": " << message << "\n\t" << file << ":" << line;
    }
    std::lock_guard<mutex_t> locker(log_mutex);
    logs[level].push(out.str());

#ifndef TOOLBOXPP_LOGGER_NO_AUTOFLUSH
    flush();
#endif
}
void toolbox::tlog::e(const char* file, int line, const char* tag, const char* message) {
    e(std::string(file), line, std::string(tag), std::string(message));
}
void toolbox::tlog::e(const std::string& file, int line, const std::string& tag, const std::string& message) {
    log(LEVEL_ERROR, file, line, tag, message);
}
void toolbox::tlog::e(const std::string& tag, const std::string& message) {
    log(LEVEL_ERROR, tag, message);
}
void toolbox::tlog::e(const char* tag, const char* message) {
    e(std::string(tag), std::string(message));
}
void toolbox::tlog::crit(const char* file, int line, const char* tag, const char* message) {
    crit(std::string(file), line, std::string(tag), std::string(message));
}
void toolbox::tlog::crit(const std::string& file, int line, const std::string& tag, const std::string& message) {
    log(LEVEL_CRITICAL, file, line, tag, message);
}
void toolbox::tlog::crit(const std::string& tag, const std::string& message) {
    log(LEVEL_CRITICAL, tag, message);
}
void toolbox::tlog::crit(const char* tag, const char* message) {
    crit(std::string(tag), std::string(message));
}
void toolbox::tlog::w(const char* file, int line, const char* tag, const char* message) {
    w(std::string(file), line, std::string(tag), std::string(message));
}
void toolbox::tlog::w(const std::string& file, int line, const std::string& tag, const std::string& message) {
    log(LEVEL_WARNING, file, line, tag, message);
}
void toolbox::tlog::w(const std::string& tag, const std::string& message) {
    log(LEVEL_WARNING, tag, message);
}
void toolbox::tlog::w(const char* tag, const char* message) {
    w(std::string(tag), std::string(message));
}
void toolbox::tlog::i(const char* file, int line, const char* tag, const char* message) {
    i(std::string(file), line, std::string(tag), std::string(message));
}
void toolbox::tlog::i(const std::string& file, int line, const std::string& tag, const std::string& message) {
    log(LEVEL_INFO, file, line, tag, message);
}
void toolbox::tlog::i(const std::string& tag, const std::string& message) {
    log(LEVEL_INFO, tag, message);
}
void toolbox::tlog::i(const char* tag, const char* message) {
    i(std::string(tag), std::string(message));
}
void toolbox::tlog::d(const char* file, int line, const char* tag, const char* message) {
    d(std::string(file), line, std::string(tag), std::string(message));
}
void toolbox::tlog::d(const std::string& file, int line, const std::string& tag, const std::string& message) {
    log(LEVEL_DEBUG, file, line, tag, message);
}
void toolbox::tlog::d(const std::string& tag, const std::string& message) {
    log(LEVEL_DEBUG, tag, message);
}
void toolbox::tlog::d(const char* tag, const char* message) {
    d(std::string(tag), std::string(message));
}

//#endif
