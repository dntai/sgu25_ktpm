#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "math_lib.h"

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}

TEST(FindMaxTest, DifferentValues) {
    EXPECT_EQ(findMax(1, 2, 3), 3);
    EXPECT_EQ(findMax(10, 5, 7), 10);
    EXPECT_EQ(findMax(-1, -2, -3), -1);
}

TEST(FindMaxTest, EqualValues) {
    EXPECT_EQ(findMax(5, 5, 5), 5); 
    EXPECT_EQ(findMax(7, 7, 3), 7);
    EXPECT_EQ(findMax(2, 8, 8), 8);
}

TEST(FindMaxTest, TwoEqualMax) {
    EXPECT_EQ(findMax(9, 9, 3), 9);
    EXPECT_EQ(findMax(4, 6, 6), 6);
    EXPECT_EQ(findMax(8, 2, 8), 8);
}

