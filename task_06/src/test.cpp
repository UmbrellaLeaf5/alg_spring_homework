// test lib:
#include <gtest/gtest.h>

// my libs:
#include "find_n_order_statistic.hpp"

TEST(FindNOrderStatistic, Simple) {
  std::vector<int> vec = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  ASSERT_EQ(FindNOrderStatistic(vec, 1), 1);
  ASSERT_EQ(FindNOrderStatistic(vec, 9), 9);
  ASSERT_EQ(FindNOrderStatistic(vec, 3), 3);
  ASSERT_EQ(FindNOrderStatistic(vec, 5), 5);
  ASSERT_EQ(FindNOrderStatistic(vec, 4), 4);
  ASSERT_EQ(FindNOrderStatistic(vec, 0), 0);
  ASSERT_EQ(FindNOrderStatistic(vec, 8), 8);

  std::vector<int> a{51, 83, 11, 64, 66, 57, 55};
  ASSERT_EQ(FindNOrderStatistic(a, 3), 55);

  std::vector<int> b{
      41, 99, 43, 22, 33, 60, 61, 8, 1, 97,
  };
  ASSERT_EQ(FindNOrderStatistic(b, 5), 43);
}

TEST(FindNOrderStatistic, Unsorted_And_Sorted) {
  std::vector<int> vec = {9, 2, 3, 0, 7, 1, 6, 4, 8, 5};
  ASSERT_EQ(FindNOrderStatistic(vec, 0), 0);
  ASSERT_EQ(FindNOrderStatistic(vec, 4), 4);
  ASSERT_EQ(FindNOrderStatistic(vec, 8), 8);

  std::vector<int> vec_2 = {69, 228, 420, 1488};
  ASSERT_EQ(FindNOrderStatistic(vec_2, 0), 69);
  ASSERT_EQ(FindNOrderStatistic(vec_2, 2), 420);
  ASSERT_EQ(FindNOrderStatistic(vec_2, 3), 1488);
}

TEST(FindNOrderStatistic, Backwards) {
  std::vector<int> vec = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
  ASSERT_EQ(FindNOrderStatistic(vec, 0), 0);
  ASSERT_EQ(FindNOrderStatistic(vec, 4), 4);
  ASSERT_EQ(FindNOrderStatistic(vec, 8), 8);
}

TEST(FindNOrderStatistic, Empty) {
  std::vector<int> vec;
  ASSERT_THROW(FindNOrderStatistic(vec, 0), std::runtime_error);
}

TEST(FindNOrderStatistic, OutOfRange) {
  std::vector<int> vec = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  ASSERT_THROW(FindNOrderStatistic(vec, 12), std::runtime_error);
}

TEST(FindNOrderStatistic, Wrong_N) {
  std::vector<int> vec = {1, 2, 3};
  EXPECT_THROW(FindNOrderStatistic(vec, 3), std::runtime_error);
}
