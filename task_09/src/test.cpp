#include <gtest/gtest.h>

#include "coins_task.hpp"

TEST(MinCoinsNumber, Simple) {
  ASSERT_EQ(MinCoinsNumber(14, std::vector<size_t>{1, 2, 5, 10}), 3);
  ASSERT_EQ(MinCoinsNumber(21, std::vector<size_t>{1, 3, 6}), 4);
  ASSERT_EQ(MinCoinsNumber(25, std::vector<size_t>{1, 2, 3, 5}), 5);
  ASSERT_EQ(MinCoinsNumber(137, std::vector<size_t>{1, 3, 7, 19}), 9);
  ASSERT_EQ(MinCoinsNumber(137, std::vector<size_t>{1, 2, 5, 7, 10}), 14);
}
