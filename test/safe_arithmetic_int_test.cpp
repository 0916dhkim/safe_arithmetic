#include <gtest/gtest.h>
extern "C" {
#include <safe_arithmetic/safe_arithmetic_int.h>
#include <limits.h>
}

TEST(Integer, CheckMaximumPlusZero) {
	EXPECT_TRUE(check_add_safe(INT_MAX, 0)) << "Maximum plus 0 should not overflow.";
}

TEST(Integer, CheckMaximumPlusOne) {
	EXPECT_FALSE(check_add_safe(INT_MAX, 1)) << "Maximum plus 1 should overflow.";
}

TEST(Integer, MaximumPlusOne) {
	EXPECT_DEATH(add_safe(INT_MAX, 1), ".*") << "Maximum plus 1 should overflow";
}

TEST(Integer, CheckMinimumMinusZero) {
	EXPECT_TRUE(check_add_safe(INT_MIN, -0)) << "Minimum minus 0 should not underflow.";
}

TEST(Integer, CheckMinimumMinusOne) {
	EXPECT_FALSE(check_add_safe(INT_MIN, -1)) << "Minimum minus 1 should underflow.";
}

TEST(Integer, MinimumMinusOne) {
	EXPECT_DEATH(add_safe(INT_MIN, -1), ".*") << "Minimum minus 1 should underflow.";
}