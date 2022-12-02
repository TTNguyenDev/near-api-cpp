/*!
 * toolbox. 2017
 *
 * \author Eduard Maximovich <edward.vstock@gmail.com>
 * \link https://github.com/edwardstock
 */

#include "gtest/gtest.h"
#include <iostream>
#include <string>
#include <toolbox/term.h>

using namespace toolbox::term;

TEST(Term, ConfirmAnwserNo) {
    std::istringstream input1("no");
    std::ostringstream output1;

    bool result1 = confirm(input1, output1, "Wanna pizza?", false);
    ASSERT_FALSE(result1);
    ASSERT_STREQ("Wanna pizza? (yes|no) [no]: ", output1.str().c_str());

    // empty value means default value
    std::istringstream input2("");
    std::ostringstream output2;
    bool result2 = confirm(input2, output2, "Wanna pizza?", true);
    ASSERT_TRUE(result2);
    ASSERT_STREQ("Wanna pizza? (yes|no) [yes]: ", output2.str().c_str());
}

TEST(Term, ConfirmAnwserYes) {
    std::istringstream input("yes");
    std::ostringstream output;

    bool result = confirm(input, output, "Wanna pizza?", false);

    ASSERT_TRUE(result);
    ASSERT_STREQ("Wanna pizza? (yes|no) [no]: ", output.str().c_str());
}

TEST(Term, ConfirmAnwserNotAYesAndNotANo) {
    // i have no idea, how to test it
    ASSERT_TRUE(true);
}

TEST(Term, PromptPizzaContains) {

    std::string defaultStuffing = "ok, i'll take with Pepperoni";

    // answered
    std::istringstream input1("with double cheese");
    std::ostringstream output1;

    const std::string pizzaWith1 = prompt(input1, output1, "What with you wanna pizza?", false, defaultStuffing);

    ASSERT_STREQ(output1.str().c_str(), std::string("What with you wanna pizza? [" + defaultStuffing + "]: ").c_str());
    ASSERT_STREQ(pizzaWith1.c_str(), "with double cheese");

    // no anwser
    std::istringstream input2;
    std::ostringstream output2;

    const std::string pizzaWith2 = prompt(input2, output2, "With what stuffing to take pizza?", false, defaultStuffing);

    ASSERT_STREQ(output2.str().c_str(),
                 std::string("With what stuffing to take pizza? [" + defaultStuffing + "]: ").c_str());
    ASSERT_STREQ(pizzaWith2.c_str(), defaultStuffing.c_str());
}
