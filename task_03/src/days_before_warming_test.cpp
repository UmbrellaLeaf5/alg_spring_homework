// test lib:
#include <gtest/gtest.h>

// my libs:
#include "days_before_warming.hpp"

// std usings:
using std::cout, std::cin, std::endl;

TEST(DaysBeforeWarming_test, Subtest_1) {
  std::vector<Temperature> vec{1, 2, 3, 4, 5};
  std::vector<size_t> ans{1, 1, 1, 1, 0};

  ASSERT_EQ(DaysBeforeWarmingSillyLooping(vec), ans);
  ASSERT_EQ(DaysBeforeWarmingSmarterLooping(vec), ans);
  ASSERT_EQ(DaysBeforeWarmingStackLooping(vec), ans);
}

TEST(DaysBeforeWarming_test, Subtest_2) {
  std::vector<Temperature> vec{6};
  std::vector<size_t> ans{0};

  ASSERT_EQ(DaysBeforeWarmingSillyLooping(vec), ans);
  ASSERT_EQ(DaysBeforeWarmingSmarterLooping(vec), ans);
  ASSERT_EQ(DaysBeforeWarmingStackLooping(vec), ans);
}

TEST(DaysBeforeWarming_test, Subtest_3) {
  std::vector<Temperature> vec{};
  std::vector<size_t> ans{};

  ASSERT_EQ(DaysBeforeWarmingSillyLooping(vec), ans);
  ASSERT_EQ(DaysBeforeWarmingSmarterLooping(vec), ans);
  ASSERT_EQ(DaysBeforeWarmingStackLooping(vec), ans);
}

TEST(DaysBeforeWarming_test, Subtest_4) {
  std::vector<Temperature> vec{-1, -1, 2, 2, -5, 3, 4, 1};
  std::vector<size_t> ans{2, 1, 3, 2, 1, 1, 0, 0};

  ASSERT_EQ(DaysBeforeWarmingSillyLooping(vec), ans);
  ASSERT_EQ(DaysBeforeWarmingSmarterLooping(vec), ans);
  ASSERT_EQ(DaysBeforeWarmingStackLooping(vec), ans);
}

TEST(DaysBeforeWarming_test, Subtest_5) {
  std::vector<Temperature> vec{6, 5, 4, 3, 2, 1};
  std::vector<size_t> ans{0, 0, 0, 0, 0, 0};

  ASSERT_EQ(DaysBeforeWarmingSillyLooping(vec), ans);
  ASSERT_EQ(DaysBeforeWarmingSmarterLooping(vec), ans);
  ASSERT_EQ(DaysBeforeWarmingStackLooping(vec), ans);
}

TEST(DaysBeforeWarming_test, Subtest_6) {
  std::vector<Temperature> vec{1,  2,  3, 4,  4,  3,  2,  1, 0,
                               -1, -5, 8, 31, -9, 58, 36, 5};
  std::vector<size_t> ans{1, 1, 1, 8, 7, 6, 5, 4, 3, 2, 1, 1, 2, 1, 0, 0, 0};

  ASSERT_EQ(DaysBeforeWarmingSillyLooping(vec), ans);
  ASSERT_EQ(DaysBeforeWarmingSmarterLooping(vec), ans);
  ASSERT_EQ(DaysBeforeWarmingStackLooping(vec), ans);
}
