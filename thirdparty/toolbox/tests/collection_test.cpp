/*! 
 * toolbox. 2017
 * 
 * \author Eduard Maximovich <edward.vstock@gmail.com>
 * \link https://github.com/edwardstock
 */
#include "gtest/gtest.h"
#include <iostream>
#include <toolbox/collections.h>

using namespace toolbox::collections;

TEST(Collections, MapToKeys) {
    std::map<int, int> m{
        {1, 2},
        {3, 4},
        {5, 6}
    };
    std::vector<int> keys;

    keys = map_keys_to_vector(m);

    ASSERT_EQ(keys[0], 1);
    ASSERT_EQ(keys[1], 3);
    ASSERT_NE(keys[2], 6);
}

TEST(Collections, UnorderedMapToKeys) {
    std::unordered_map<int, int> m{
        {1, 2},
        {3, 4},
        {5, 6}
    };
    std::vector<int> keys;

    keys = map_keys_to_vector(m);

    std::vector<int> keysMustExists{
        1, 3, 5
    };

    size_t found = 0;
    for (auto &k: keys) {
        for (auto &req: keysMustExists) {
            if (req == k) {
                found++;
                break;
            }
        }
    }

    ASSERT_EQ(keysMustExists.size(), found);

}

TEST(Collections, MultimapToKeys) {
    std::unordered_map<int, int> m{
        {1, 2},
        {3, 4},
        {5, 6}
    };
    std::vector<int> keys;

    keys = map_keys_to_vector(m);

    std::vector<int> keysMustExists{
        1, 3, 5
    };

    size_t found = 0;
    for (auto &k: keys) {
        for (auto &req: keysMustExists) {
            if (req == k) {
                found++;
                break;
            }
        }
    }

    ASSERT_EQ(keysMustExists.size(), found);

}

TEST(Collections, MapToValues) {
    std::map<int, int> m{
        {1, 2},
        {3, 4},
        {5, 6}
    };
    std::vector<int> values;

    values = map_vals_to_vector(m);

    ASSERT_EQ(values[0], 2);
    ASSERT_EQ(values[1], 4);
    ASSERT_NE(values[2], 5);
}
