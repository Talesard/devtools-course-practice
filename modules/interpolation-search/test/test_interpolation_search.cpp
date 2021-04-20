// Copyright 2021 Napylov Evgeniy
#include <gtest/gtest.h>
#include <algorithm>
#include "include/interpolation_search.h"


TEST(InterpolationSearch, get_random_vector) {
    std::vector<int> vec;

    ASSERT_NO_THROW(vec = get_random_vec(100, -200, 200));
}

TEST(InterpolationSearch, empty_vector) {
    std::vector<int> vec(0);
    const int key = 123;

    int res = interpolation_search(vec, key, false);

    ASSERT_EQ(-1, res);
}

TEST(InterpolationSearch, exist_unique) {
    std::vector<int> vec = {-5, -4, -3, -2, -1, 0, 1, 2, 3, 4, 5};
    const int key = 2;

    int res = interpolation_search(vec, key, true);

    ASSERT_EQ(7, res);
}

TEST(InterpolationSearch, exist_not_unique) {
    std::vector<int> vec = { -5, -4, -4, -4, -3, -2, -1, 0,
                          1, 1, 1, 2, 2, 2, 2, 2, 3, 3, 4, 5 };
    const int key = 2;

    int res = interpolation_search(vec, key, false);

    ASSERT_EQ(11, res);
}

TEST(InterpolationSearch, not_exist_inside_not_unique) {
    std::vector<int> vec = { -5, -4, -4, -4, -3, -2, -1, 0,
                             0, 2, 2, 2, 2, 2, 3, 3, 4, 5 };
    const int key = 1;

    int res = interpolation_search(vec, key, false);

    ASSERT_EQ(-1, res);
}

TEST(InterpolationSearch, not_exist_outside_left_not_unique) {
    std::vector<int> vec = { -5, -4, -4, -4, -3, -2, -1, 0,
                             0, 2, 2, 2, 2, 2, 3, 3, 4, 5 };
    const int key = -100;

    int res = interpolation_search(vec, key, false);

    ASSERT_EQ(-1, res);
}

TEST(InterpolationSearch, not_exist_outside_right_not_unique) {
    std::vector<int> vec = { -5, -4, -4, -4, -3, -2, -1, 0,
                             0, 2, 2, 2, 2, 2, 3, 3, 4, 5 };
    const int key = 100;

    int res = interpolation_search(vec, key, false);

    ASSERT_EQ(-1, res);
}

TEST(InterpolationSearch, not_exist_inside_unique) {
    std::vector<int> vec = {-5, -4, -3, -2, -1, 0, 2, 3, 4, 5};
    const int key = 1;

    int res = interpolation_search(vec, key, true);

    ASSERT_EQ(-1, res);
}

TEST(InterpolationSearch, not_exist_outside_left_unique) {
    std::vector<int> vec = { -5, -4, -3, -2, -1, 0, 2, 3, 4, 5 };
    const int key = -100;

    int res = interpolation_search(vec, key, true);

    ASSERT_EQ(-1, res);
}

TEST(InterpolationSearch, not_exist_outside_right_unique) {
    std::vector<int> vec = { -5, -4, -3, -2, -1, 0, 2, 3, 4, 5 };
    const int key = 100;

    int res = interpolation_search(vec, key, true);

    ASSERT_EQ(-1, res);
}

TEST(InterpolationSearch, random) {
    std::vector<int> vec = get_random_vec(101, -500, 500);
    const int key = 123;

    std::sort(vec.begin(), vec.end());
    int res_interp = interpolation_search(vec, key, false);
    int res_linear = linear_search(vec, key);

    ASSERT_EQ(res_linear, res_interp);
}

TEST(InterpolationSearch, not_exist_outside_left_random) {
    std::vector<int> vec = get_random_vec(102, -500, 500);
    const int key = -600;

    std::sort(vec.begin(), vec.end());
    int res_interp = interpolation_search(vec, key, false);
    int res_linear = linear_search(vec, key);

    ASSERT_EQ(res_linear, res_interp);
}

TEST(InterpolationSearch, not_exist_outside_right_random) {
    std::vector<int> vec = get_random_vec(103, -500, 500);
    const int key = 600;

    std::sort(vec.begin(), vec.end());
    int res_interp = interpolation_search(vec, key, false);
    int res_linear = linear_search(vec, key);

    ASSERT_EQ(res_linear, res_interp);
}
