// Copyright 2021 Evgenii Napylov

#include <gtest/gtest.h>

#include <limits>

#include "include/complex_number.h"

TEST(Napylov_Evgenii_ComplexNumberTest, Mult_by_conjugate) {
    ComplexNumber num1(3, 7);
    ComplexNumber num2(3, -7);
    ComplexNumber res = num1 * num2;
    ASSERT_EQ(58, res.getRe());
    ASSERT_EQ(0, res.getIm());
}

TEST(Napylov_Evgenii_ComplexNumberTest, Divide_by_real) {
    ComplexNumber num_complex(5, 10);
    ComplexNumber num_real(5, 0);
    ComplexNumber res = num_complex / num_real;
    ASSERT_EQ(1, res.getRe());
    ASSERT_EQ(2, res.getIm());
}

TEST(Napylov_Evgenii_ComplexNumberTest, Divide_by_zero) {
    ComplexNumber not_zero(1, 1);
    ComplexNumber zero(0, 0);
    ASSERT_ANY_THROW(not_zero / zero);
}

TEST(Napylov_Evgenii_ComplexNumberTest, Create_infinity) {
    constexpr double inf = std::numeric_limits<double>::infinity();
    EXPECT_NO_THROW(ComplexNumber num_inf(inf, inf));
}
