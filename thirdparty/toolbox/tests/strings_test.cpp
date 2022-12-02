/*! 
 * toolbox. 2017
 * 
 * \author Eduard Maximovich <edward.vstock@gmail.com>
 * \link https://github.com/edwardstock
 */

#include "gtest/gtest.h"
#include <toolbox/strings.hpp>
#include <toolbox/strings/regex.h>

using namespace toolbox::strings;

TEST(Strings, HasSubstringIgnoreCase) {
    ASSERT_TRUE(has_substring_icase("AAA", "AAA"));
    ASSERT_TRUE(has_substring_icase("A", "AAA"));
    ASSERT_TRUE(has_substring_icase("a", "AAA"));
    ASSERT_FALSE(has_substring_icase("bbb", "AAA"));
    ASSERT_FALSE(has_substring_icase("aaaa", "A"));
    ASSERT_FALSE(has_substring_icase("1", "A"));
    // unicode test
    ASSERT_TRUE(has_substring_icase("Ю", "ЮЮЮ"));
    ASSERT_FALSE(has_substring_icase("ЯЯЯ", "Л"));
}

TEST(Strings, HasSubstring) {
    ASSERT_TRUE(has_substring("AAA", "AAA"));
    ASSERT_TRUE(has_substring("A", "AAA"));
    ASSERT_FALSE(has_substring("a", "AAA"));
    ASSERT_FALSE(has_substring("bbb", "AAA"));
    ASSERT_FALSE(has_substring("aaaa", "A"));
    ASSERT_FALSE(has_substring("1", "A"));
    ASSERT_FALSE(has_substring("HTTP/1.1 400 Bad Request", "HTTP"));
    // unicode test
    ASSERT_TRUE(has_substring("Привет", "Привет! Как дела?"));
    ASSERT_FALSE(has_substring("Как дела?", "Привет"));
}

TEST(Strings, HasSubstringChar) {
    ASSERT_TRUE(has_substring('A', "AAA"));
    ASSERT_FALSE(has_substring('a', "AAA"));
    ASSERT_FALSE(has_substring('d', "{a,b,c}"));
}

#ifdef HAVE_REGEX_H

TEST(Strings, RegexFindAllPatternEnvironmentVariables) {
    const std::string source = "cp $HOME/value.txt $PWD/new_value.txt";
    const std::string pattern = R"(\$[A-Z0-9_]+)";

    ASSERT_TRUE(matches_pattern(pattern, source));

    auto res_all = find_all_pattern(pattern, source);

    ASSERT_EQ(2, res_all.size());
    ASSERT_STREQ("$HOME", res_all[0][0].c_str());
    ASSERT_STREQ("$PWD", res_all[1][0].c_str());
}

TEST(Strings, RegexMatchesPattern) {
    ASSERT_TRUE(matches_pattern("[0-9]", "abc123"));
    ASSERT_TRUE(matches_pattern(rxns::regex("[a-z0-9]"), "abc123"));
    ASSERT_TRUE(matches_pattern("HTTP", "HTTP/1.1 400 Bad Request"));
    ASSERT_FALSE(matches_pattern("[!@#$]", "abc123"));
    ASSERT_TRUE(matches_pattern("[а-я]", "привет"));
    ASSERT_FALSE(matches_pattern("[а-я]", "hello"));
}

TEST(Strings, RegexMatchAll) {
    auto result = find_all_pattern(R"((\[[a-z]+\]))", "[abc]\n\n[def]gagag[ghi]rg45w5[jkl]");
    std::vector<std::string> mustBeFounded{
        "[abc]",
        "[def]",
        "[ghi]",
        "[jkl]"};
    size_t found = 0;
    for (auto& matches : result) {
        ASSERT_EQ(2UL, matches.size());
        const std::string match = matches[1];
        for (auto &f: mustBeFounded) {
            if (f == match) {
                found++;
                break;
            }
        }
    }

    ASSERT_EQ(mustBeFounded.size(), found);

    auto result2 = find_all_pattern(rxns::regex(R"((\[[a-z]+\]))"), "[abc]\n\n[def]gagag[ghi]rg45w5[jkl]");
    size_t found2 = 0;
    for (auto &matches: result2) {
        ASSERT_EQ(2UL, matches.size());
        const std::string match = matches[1];
        for (auto &f: mustBeFounded) {
            if (f == match) {
                found2++;
                break;
            }
        }
    }

    ASSERT_EQ(mustBeFounded.size(), found2);
}

TEST(Strings, RegexFindPatternFirst) {
    auto result1 = find_pattern_first(R"((\[[a-z]+\]))", "[abc]\n\n[def]gagag[ghi]rg45w5[jkl]");
    std::string mustBeFounded = "[abc]";

    ASSERT_STREQ(result1.c_str(), mustBeFounded.c_str());

    auto result2 = find_pattern_first(rxns::regex(R"((\[[a-z]+\]))"), "[abc]\n\n[def]gagag[ghi]rg45w5[jkl]");

    ASSERT_STREQ(result2.c_str(), mustBeFounded.c_str());
}

TEST(Strings, RegexFindPattern) {
    const char* mustBeFounded = "[abc]";

    auto result1 = find_pattern(R"((\[[a-z]+\]))", "[abc]\n\n[def]gagag[ghi]rg45w5[jkl]");
    ASSERT_EQ(2UL, result1.size());
    ASSERT_FALSE(result1.empty());
    ASSERT_STREQ(result1[1].c_str(), mustBeFounded);

    auto result2 = find_pattern(rxns::regex(R"((\[[a-z]+\]))"), "[abc]\n\n[def]gagag[ghi]rg45w5[jkl]");
    ASSERT_EQ(2UL, result2.size());
    ASSERT_FALSE(result2.empty());
    ASSERT_STREQ(result2[1].c_str(), mustBeFounded);

    auto result3 = find_pattern(R"(HTTP\/\d\.\d.(\d+).(.*))", "HTTP/1.1 400 Bad Request");
    ASSERT_EQ(3UL, result3.size());
    ASSERT_STREQ(result3[1].c_str(), "400");
    ASSERT_STREQ(result3[2].c_str(), "Bad Request");
}

#endif

TEST(Strings, SplitPair) {
    auto result1 = split_pair("abc,def", ",");
    ASSERT_STREQ("abc", result1.first.c_str());
    ASSERT_STREQ("def", result1.second.c_str());

    auto result2 = split_pair("abc, def", ",");
    ASSERT_STREQ("abc", result2.first.c_str());
    ASSERT_STREQ(" def", result2.second.c_str());

    auto result3 = split_pair("abc, ", ',');
    ASSERT_STREQ("abc", result3.first.c_str());
    ASSERT_STREQ(" ", result3.second.c_str());

    auto result4 = split_pair("abc", ",");
    ASSERT_STREQ("abc", result4.first.c_str());
    ASSERT_STREQ("", result4.second.c_str());

    auto result5 = split_pair("", ',');
    ASSERT_STREQ("", result5.first.c_str());
    ASSERT_STREQ("", result5.second.c_str());

    auto result6 = split_pair(",", ",");
    ASSERT_STREQ("", result6.first.c_str());
    ASSERT_STREQ("", result6.second.c_str());

    auto result7 = split_pair("abcdef", ',');
    ASSERT_STREQ("abcdef", result7.first.c_str());
    ASSERT_STREQ("", result7.second.c_str());

    auto result8 = split_pair("привет! как дела?", '!');
    ASSERT_STREQ("привет", result8.first.c_str());
    ASSERT_STREQ(" как дела?", result8.second.c_str());
}

TEST(Strings, Split) {
    std::vector<std::string> mustBeInList{
        "abc", "def", "ghi", "jkl"
    };

    auto result1 = split("abc/def/ghi/jkl", '/');
    ASSERT_EQ(4UL, result1.size());
    size_t found1 = 0;
    for (auto &result: result1) {
        for (auto &m: mustBeInList) {
            if (result == m) {
                found1++;
                break;
            }
        }
    }

    ASSERT_EQ(found1, mustBeInList.size());

    auto result2 = split("abc/def/ghi/jkl", "/");
    ASSERT_EQ(4UL, result2.size());
    size_t found2 = 0;
    for (auto &result: result2) {
        for (auto &m: mustBeInList) {
            if (result == m) {
                found2++;
                break;
            }
        }
    }

    ASSERT_EQ(found2, mustBeInList.size());

    std::vector<std::string> mustBeInList3{
        "abc/", "ghi/jkl"
    };
    auto result3 = split("abc/def/ghi/jkl", "def/");
    ASSERT_EQ(result3.size(), mustBeInList3.size());

    size_t found3 = 0;
    for (auto& t : result3) {
        for (auto& m : mustBeInList3) {
            if (m == t) {
                found3++;
                break;
            }
        }
    }
    ASSERT_EQ(found3, mustBeInList3.size());

    std::string src = "some;value";
    auto result4 = split(src, "");
    ASSERT_EQ(0, result4.size());
}

TEST(Strings, Trim) {
    std::string test1 = "hello world!\n\taa\n\tbbb\n\tccc";
    std::string res = trim(test1);
    ASSERT_STREQ("hello world!aabbbccc", res.c_str());
}

TEST(Strings, TrimRef) {
    std::string test1 = "hello world!\n\taa\n\tbbb\n\tccc";
    trim_ref(test1);
    ASSERT_STREQ("hello world!aabbbccc", test1.c_str());
}

TEST(Strings, Replace) {
    std::string test1 = "hello world!";
    replace("hello", "hell or", test1);
    replace("world", "piece", test1);
    replace("!", "?", test1);
    ASSERT_STREQ("hell or piece?", test1.c_str());
}

TEST(Strings, ReplaceAll) {
    std::string test1 = "hello world!";
    substr_replace_all("o", "!", test1);
    ASSERT_STREQ("hell! w!rld!", test1.c_str());

    substr_replace_all("ll", "bb", test1);
    ASSERT_STREQ("hebb! w!rld!", test1.c_str());

    const std::vector<std::string> from1{"aaa", "bbb"};
    const std::vector<std::string> to1{"yyy", "zzz"};
    std::string test2 = "aaabbb";
    substr_replace_all(from1, to1, test2);
    ASSERT_STREQ("yyyzzz", test2.c_str());

    std::vector<std::string> from2{"aaa", "bbb"};
    std::vector<std::string> to2{"yyy", "zzz"};
    std::string test3 = "aaabbb";
    substr_replace_all(from2, to2, test3);
    ASSERT_STREQ("yyyzzz", test3.c_str());

    std::vector<std::string> from3{"aaa", "bbb"};
    std::vector<std::string> to3{"yyy", "zzz", "qqq"};
    std::string test4 = "aaabbb";
    bool threw0 = false;
    try {
        auto res = substr_replace_all_ret(from3, to3, test3);
    } catch (const std::exception& e) {
        threw0 = true;
    }
    ASSERT_TRUE(threw0);

    std::vector<std::string> from4{"aaa", "bbb"};
    std::vector<std::string> to4{"yyy"};
    std::string test5 = "aaabbb";
    auto res = substr_replace_all_ret(from4, to4, test5);
    ASSERT_STREQ("yyyyyy", res.c_str());
}

TEST(Strings, RemoveSubstrings) {
    std::string test = "hello world!";
    substr_remove(test, " ");
    ASSERT_STREQ("helloworld!", test.c_str());
}

TEST(Strings, RemoveSubstringsVector) {
    std::string test = "hello world!";
    substr_remove_all(test, {"ll", "!", " "});
    ASSERT_STREQ("heoworld", test.c_str());
}

TEST(Strings, SubstringInverse) {
    std::string test = "hello world!";
    std::string res1 = substr_inverse(test, ' ');
    ASSERT_STREQ("hello", res1.c_str());

    std::string res2 = substr_inverse(test, ~' ');
    ASSERT_STREQ("world!", res2.c_str());
}

TEST(Strings, ToLower) {
    std::string test1 = "Upper Case";
    std::string res1 = to_lower_case(test1);
    ASSERT_NE(res1.compare(test1), 0);

    std::string test2 = "привет меДВЕД";
    std::string res2 = to_lower_case(test2);

    ASSERT_EQ(test2.compare(res2), 0);
}

TEST(Strings, ToUpper) {
    std::string test1 = "Upper Case";
    std::string res1 = to_upper_case(test1);
    ASSERT_NE(res1.compare(test1), 0);
    ASSERT_STREQ("UPPER CASE", res1.c_str());

    std::string test2 = "привет меДВЕД";
    std::string res2 = to_upper_case(test2);

    // it does not work with unicode
    ASSERT_EQ(test2.compare(res2), 0);
}

TEST(Strings, ClipSubstring) {
    std::string test1 = "aaa bbb ccc";
    std::string res1 = substr_clip(test1, "bbb", 7);
    ASSERT_STREQ("a bbb c", res1.c_str());

    std::string test2 = "aaabbbccc";
    std::string res2 = substr_clip(test2, "bbb", 3);
    ASSERT_STREQ("bbb", res2.c_str());
}

TEST(Strings, Glue) {
    std::string g = ";";
    const std::vector<std::string> data1{
        "aaa",
        "bbb",
        "ccc"
    };

    std::string res1 = glue(g, data1);
    ASSERT_STREQ("aaa;bbb;ccc", res1.c_str());

    const std::vector<std::string> data2{
        "ааа",
        "ббб",
        "ввв"
    };
    std::string res2 = glue(g, data2);
    ASSERT_STREQ("ааа;ббб;ввв", res2.c_str());
}

TEST(Strings, EqualsICase) {
#ifdef TOOLBOX_ENABLE_MB
    INIT_WCHAR_UNICODE();
#endif
    const std::string t1 = "FirSt";
    const std::string t2 = "fIRsT";

    ASSERT_TRUE(equals_icase(t1, t2));

    const std::string t3 = "ПервЫЙ";
    const std::string t4 = "пЕрВый";

    ASSERT_FALSE(equals_icase(t3, t4));

    const std::wstring t5 = L"ПервЫЙ";
    const std::wstring t6 = L"первый";

#ifdef TOOLBOX_ENABLE_MB
    ASSERT_TRUE(equalsIgnoreWCase(t5, t6));
#endif
}

TEST(Strings, RepeatString) {

    const std::string src = "==";
    const std::string target = repeat(src, 3);

    ASSERT_STREQ("======", target.c_str());
}

TEST(Strings, RepeatChar) {

    const std::string target = repeat("-", 4);
    ASSERT_STREQ("----", target.c_str());

    const std::string target2 = repeat("-", 0);
    ASSERT_STREQ("", target2.c_str());
}

TEST(Strings, SplitByLen) {
    std::string src = "Hello my beautiful world";
    auto res = split_by_len(src, 8);
    ASSERT_STREQ("Hello my", res[0].c_str());
    ASSERT_STREQ(" beautiful world", res[1].c_str());
}

TEST(Strings, Format) {
    std::string expected = "hello 225 world with dog";
    std::string res1 = toolbox::strings::format("hello %llu world with %s", 225, "dog");

    ASSERT_STREQ(expected.c_str(), res1.c_str());
}
