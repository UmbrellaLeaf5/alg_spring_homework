// std libs:
#include <iostream>
#include <stdexcept>
#include <utility>
#include <vector>

// test lib:
#include <gtest/gtest.h>

// my libs:
#include "two_sum.hpp"

using namespace std;

TEST(TwoElemsGivingSum, Subtest_1) {
  EXPECT_THROW(TwoElemsGivingSum(vector<int>{}, 10), invalid_argument);
}

TEST(TwoElemsGivingSum, Subtest_2) {
  EXPECT_THROW(TwoElemsGivingSum(vector<int>{1}, 10), logic_error);
}

TEST(TwoElemsGivingSum, Subtest_3) {
  ASSERT_EQ(
      TwoElemsGivingSum(vector<long>{80000075932, 500000572938502,
                                     5000005238023000, 6000293805968347500,
                                     7530021468000003245, 9000568723653790000},
                        9000568803653865932),
      (pair<long, long>{80000075932, 9000568723653790000}));
}

TEST(TwoElemsGivingSum, Subtest_4) {
  EXPECT_THROW(
      TwoElemsGivingSum(
          vector<long>{2223523523222, 2222225252353222, 65236534764666666,
                       111850923850111111, 4454897708978644444},
          4954897708978944494),
      logic_error);
}

TEST(TwoElemsGivingSum, Subtest_5) {
  EXPECT_THROW(
      TwoElemsGivingSum(
          vector<long>{111850923850111111, 2222225252353222, 2223523523222,
                       4454897708978644444, 65236534764666666},
          4954897708978944494),
      invalid_argument);
}

TEST(TwoElemsGivingSum, Subtest_6) {
  ASSERT_EQ(TwoElemsGivingSum(vector<int>{2, 3, 4, 7, 12}, 10),
            (pair<int, int>{3, 7}));
}

TEST(TwoElemsGivingSum, Subtest_7) {
  ASSERT_EQ(TwoElemsGivingSum(vector<int>{4, 7, 8, 9, 10}, 12),
            (pair<int, int>{4, 8}));
}

TEST(TwoElemsGivingSum, Subtest_8) {
  ASSERT_EQ(TwoElemsGivingSum(vector<int>{-3, -2, 0, 1, 2}, 0),
            (pair<int, int>{-2, 2}));
}

TEST(TwoElemsGivingSum, Subtest_9) {
  ASSERT_EQ(TwoElemsGivingSum(
                vector<int>{1, 2, 4, 5, 8, 10, 13, 17, 20, 21, 22, 25}, 27),
            (pair<int, int>{2, 25}));
}

TEST(TwoElemsGivingSum, Subtest_10) {
  ASSERT_EQ(TwoElemsGivingSum(vector<int>{1, 5, 13, 21, 22}, 6),
            (pair<int, int>{1, 5}));
}

TEST(TwoElemsGivingSum, Subtest_11) {
  EXPECT_THROW(TwoElemsGivingSum(vector<int>{1, 5, 13, 21, 22}, 7),
               logic_error);
}

TEST(TwoElemsGivingSum, Subtest_12) {
  EXPECT_THROW(TwoElemsGivingSum(vector<int>{2, 3, 4, 7, 12}, 57), logic_error);
}

TEST(TwoElemsGivingSum, Subtest_13) {
  EXPECT_THROW(TwoElemsGivingSum(
                   vector<int>{1, 2, 4, 5, 8, 10, 13, 17, 20, 21, 22, 25}, -3),
               logic_error);
}

TEST(TwoElemsGivingSum, Subtest_14) {
  EXPECT_THROW(TwoElemsGivingSum(
                   vector<int>{1, 5, 4, 5, 8, -10, 13, 17, 20, 21, 22, 25}, -3),
               invalid_argument);
}

TEST(TwoElemsGivingSum, Subtest_15) {
  EXPECT_THROW(TwoElemsGivingSum(vector<int>{1, -5, 13, -21, 22}, 6),
               invalid_argument);
}

TEST(TwoElemsGivingSum, Subtest_16) {
  ASSERT_EQ(
      TwoElemsGivingSum(vector<int>{10, 20, 40, 50, 60, 87, 100, 1278}, 1338),
      (pair<int, int>{60, 1278}));
}

TEST(TwoElemsGivingSum, Subtest_17) {
  ASSERT_EQ(TwoElemsGivingSum(
                vector<long>{50000000000000, 50000000000000, 60000000000000,
                             70000000000000, 80000000000000, 90000000000000},
                100000000000000),
            (pair<long, long>{50000000000000, 50000000000000}));
}

TEST(TwoElemsGivingSum, Subtest_18) {
  ASSERT_EQ(TwoElemsGivingSum(
                vector<long>{1000000000000, 2000000000000, 3000000000000,
                             4000000000000, 7000000000000},
                10000000000000),
            (pair<long, long>{3000000000000, 7000000000000}));
}

TEST(TwoElemsGivingSum, Subtest_19) {
  EXPECT_THROW(TwoElemsGivingSum(
                   vector<long>{11111111111111, 22222222222222, 22222222222222,
                                44444444444444, 66666666666666},
                   99999999999999),
               logic_error);
}

TEST(TwoElemsGivingSum, Subtest_20) {
  EXPECT_THROW(TwoElemsGivingSum(
                   vector<long>{50000000000000, -50000000000000, 60000000000000,
                                70000000000000, 80000000000000, 90000000000000},
                   100000000000000),
               invalid_argument);
}
