/*!
 * toolbox.
 * regex.cpp
 *
 * \date 11/30/2019
 * \author Eduard Maximovich (edward.vstock@gmail.com)
 * \link   https://github.com/edwardstock
 */

#include "toolbox/strings/regex.h"

#include <vector>

#ifdef HAVE_REGEX_H

bool toolbox::strings::matches_pattern(const rxns::regex& pattern, const std::string& source) {
    rxns::smatch match;
    return rxns::regex_search(source, match, pattern);
}
bool toolbox::strings::matches_pattern(const std::string& pattern, const std::string& source) {
    return matches_pattern(rxns::regex(pattern, rxns::regex_constants::icase), source);
}
std::vector<std::vector<std::string>> toolbox::strings::find_all_pattern(const rxns::regex& pattern,
                                                                         const std::string& source) {
    std::vector<std::vector<std::string>> capturedGroups;
    std::vector<std::string> capturedSubgroups;
    const rxns::sregex_token_iterator endIterator;
    for (rxns::sregex_token_iterator it(source.cbegin(), source.cend(), pattern); it != endIterator; ++it) {
        capturedSubgroups.clear();
        std::string group = *it;
        rxns::smatch res;
        if (rxns::regex_search(group, res, pattern)) {
            for (size_t i = 0; i < res.size(); i++) { // NOLINT(modernize-loop-convert), sometimes foreach has
                // strange effect - size is 0, but iterator have != 0 items
                capturedSubgroups.push_back(res[i]);
            }

            if (!capturedSubgroups.empty()) {
                capturedGroups.push_back(capturedSubgroups);
            }
        }
    }

    return capturedGroups;
}
std::vector<std::vector<std::string>> toolbox::strings::find_all_pattern(const std::string& pattern,
                                                                         const std::string& source) {
    return find_all_pattern(rxns::regex(pattern, rxns::regex_constants::icase), source);
}
std::string toolbox::strings::find_pattern_first(const rxns::regex& pattern, const std::string& source) {
    rxns::smatch results;
    std::string result;
    bool found = rxns::regex_search(source, results, pattern);
    if (!found || results.size() < 2) {
        return std::string();
    }

    return results[1];
}
std::string toolbox::strings::find_pattern_first(const std::string& pattern, const std::string& source) {
    return find_pattern_first(rxns::regex(pattern, rxns::regex_constants::icase), source);
}
std::vector<std::string> toolbox::strings::find_pattern(const rxns::regex& rxPattern, const std::string& source) {
    rxns::smatch result;
    rxns::regex_search(source, result, rxPattern);

    std::vector<std::string> out(result.size());
    const size_t cnt = result.size();
    for (size_t i = 0; i < cnt; i++) {
        out[i] = result[i];
    }

    return out;
}
std::vector<std::string> toolbox::strings::find_pattern(const std::string& pattern, const std::string& source) {
    return find_pattern(rxns::regex(pattern, rxns::regex_constants::icase), source);
}
bool toolbox::strings::num_is_integer(const std::string& input) {
    return rxns::regex_match(input, rxns::regex(R"(^[-]?[0-9eE+]+?$)"));
}
bool toolbox::strings::num_is_real(const std::string& input) {
    return rxns::regex_match(input, rxns::regex(R"(^[-+]?[0-9]*\.?[0-9]+([eE][-+]?[0-9]+)?$)"));
}

#endif //HAVE_REGEX_H