#include <gtest/gtest.h>

#include <vector>

#include "CanReachNonDecreasingSegment.hpp"

TEST(CanReachNonDecreasingSegment, 1) {
  ASSERT_EQ(CanReachNonDecreasingSegment(
                5, 4, 6,
                std::vector<std::vector<int>>{{1, 2, 3, 5},
                                              {3, 1, 3, 2},
                                              {4, 5, 2, 3},
                                              {5, 5, 3, 2},
                                              {4, 4, 3, 4}},
                std::vector<std::pair<int, int>>{
                    {1, 1}, {2, 5}, {4, 5}, {3, 5}, {1, 3}, {1, 5}}),
            (std::vector<std::string>{"Yes", "No", "Yes", "Yes", "Yes", "No"}));
}

TEST(CanReachNonDecreasingSegment, 2) {
  ASSERT_EQ(CanReachNonDecreasingSegment(
                1, 1, 1, std::vector<std::vector<int>>{{1, 1}},
                std::vector<std::pair<int, int>>{{1, 1}}),
            (std::vector<std::string>{"Yes"}));
}
