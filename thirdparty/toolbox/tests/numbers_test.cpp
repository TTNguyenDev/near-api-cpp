/*! 
 * toolbox. 2017
 * 
 * \author Eduard Maximovich <edward.vstock@gmail.com>
 * \link https://github.com/edwardstock
 */

#include "gtest/gtest.h"
#include <toolbox/strings/decimal_formatter.h>
#include <toolbox/strings/regex.h>

#ifdef HAVE_REGEX_H
using namespace toolbox::strings;

TEST(Numbers, NumIsReal) {
    std::string num1 = "256.464646958";
    std::string num2 = "1e-4";
    std::string num3 = "12E-4";
    std::string num4 = "-137,29";
    std::string num5 = "-225.29";
    std::string num6 = "NaN";
    std::string num7 = "111";
    std::string num8 = "192.168.1.1";

    ASSERT_TRUE(num_is_real(num1));
    ASSERT_TRUE(num_is_real(num2));
    ASSERT_TRUE(num_is_real(num3));
    ASSERT_FALSE(num_is_real(num4));
    ASSERT_TRUE(num_is_real(num5));
    ASSERT_FALSE(num_is_real(num6));
    ASSERT_TRUE(num_is_real(num7)); // integer is real too
    ASSERT_FALSE(num_is_real(num8));
}

TEST(Numbers, NumIsInteger) {
    std::string num1 = "256.958";
    std::string num2 = "1e-4";
    std::string num3 = "12E-4";
    std::string num4 = "-137";
    std::string num5 = "-225.29";
    std::string num6 = "NaN";
    std::string num7 = "111";
    std::string num8 = "1e+19";

    ASSERT_FALSE(num_is_integer(num1));
    ASSERT_FALSE(num_is_integer(num2));
    ASSERT_FALSE(num_is_integer(num3));
    ASSERT_TRUE(num_is_integer(num4));
    ASSERT_FALSE(num_is_integer(num5));
    ASSERT_FALSE(num_is_integer(num6));
    ASSERT_TRUE(num_is_integer(num7));
    ASSERT_TRUE(num_is_integer(num8));
}

#endif

TEST(Numbers, DecimalFormatter) {
    toolbox::strings::decimal_formatter form("1567948125.105");

    form.set_delimiter('\'');
    form.set_min_precision(4);
    form.set_max_precision(18);

    ASSERT_STREQ("1'567'948'125.1050", form.format().c_str());

    form.set_delimiter(' ');
    ASSERT_STREQ("1 567 948 125.1050", form.format().c_str());
}

TEST(Numbers, DecimalFormatterFractions) {
    toolbox::strings::decimal_formatter form("1567948125.10203040506070809080706050");

    form.set_delimiter('\'');
    form.set_min_precision(4);
    form.set_max_precision(18);

    ASSERT_STREQ("1'567'948'125.102030405060708090", form.format().c_str());
}

TEST(Numbers, DecimalFormatterMaxFrations) {
    toolbox::strings::decimal_formatter f1("7621.303804564358533662");
    f1.set_min_precision(2);
    f1.set_max_precision(8);
    ASSERT_STREQ("7 621.30380456", f1.format().c_str());

    toolbox::strings::decimal_formatter f2("7621.000000000000000000");
    f2.set_min_precision(2);
    f2.set_max_precision(8);
    ASSERT_STREQ("7 621.00", f2.format().c_str());
}

TEST(Numbers, SimpleFormatter) {
    ASSERT_STREQ("1 567 948 125.1050", toolbox::strings::decimal_formatter()("1567948125.105").c_str());
}

TEST(Numbers, SimpleFormatterMinFracts) {
    ASSERT_STREQ("1 567 948 125.1000", toolbox::strings::decimal_formatter()("1567948125.1").c_str());
}

TEST(Numbers, SimpleFormatterNoFractions) {
    ASSERT_STREQ("1 567 948 125.0000", toolbox::strings::decimal_formatter()("1567948125").c_str());
}