#include <gtest/gtest.h>
#include "max_value.h"
#include <limits>

// Test with positive numbers
TEST(FindMaxValueTest, PositiveNumbers) {
    std::vector<int> vec = {3, 7, 2, 9, 4, 1};
    EXPECT_EQ(findMaxValue(vec), 9);
}

// Test with negative numbers
TEST(FindMaxValueTest, NegativeNumbers) {
    std::vector<int> vec = {-5, -2, -10, -3, -8};
    EXPECT_EQ(findMaxValue(vec), -2);
}

// Test with mixed positive and negative numbers
TEST(FindMaxValueTest, MixedNumbers) {
    std::vector<int> vec = {-5, 10, -3, 7, 0, -1};
    EXPECT_EQ(findMaxValue(vec), 10);
}

// Test with single element
TEST(FindMaxValueTest, SingleElement) {
    std::vector<int> vec = {42};
    EXPECT_EQ(findMaxValue(vec), 42);
}

// Test with duplicate maximum values
TEST(FindMaxValueTest, DuplicateMaxValues) {
    std::vector<int> vec = {5, 9, 3, 9, 1};
    EXPECT_EQ(findMaxValue(vec), 9);
}

// Test with all same values
TEST(FindMaxValueTest, AllSameValues) {
    std::vector<int> vec = {7, 7, 7, 7};
    EXPECT_EQ(findMaxValue(vec), 7);
}

// Test with maximum int value
TEST(FindMaxValueTest, MaxIntValue) {
    std::vector<int> vec = {1, 2, std::numeric_limits<int>::max(), 3};
    EXPECT_EQ(findMaxValue(vec), std::numeric_limits<int>::max());
}

// Test with minimum int value
TEST(FindMaxValueTest, MinIntValue) {
    std::vector<int> vec = {std::numeric_limits<int>::min(), -1, -100};
    EXPECT_EQ(findMaxValue(vec), -1);
}

// Test empty vector throws exception
TEST(FindMaxValueTest, EmptyVector) {
    std::vector<int> vec;
    EXPECT_THROW(findMaxValue(vec), std::invalid_argument);
}

// Test with max at beginning
TEST(FindMaxValueTest, MaxAtBeginning) {
    std::vector<int> vec = {10, 5, 3, 1};
    EXPECT_EQ(findMaxValue(vec), 10);
}

// Test with max at end
TEST(FindMaxValueTest, MaxAtEnd) {
    std::vector<int> vec = {1, 3, 5, 10};
    EXPECT_EQ(findMaxValue(vec), 10);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
