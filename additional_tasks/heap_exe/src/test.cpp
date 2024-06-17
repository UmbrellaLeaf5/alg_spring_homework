
#include <gtest/gtest.h>

#include <vector>

#include "heap.hpp"

TEST(heap, Simple1) {
  ASSERT_EQ(Heap_exe(2, 1, {1, 2}),
            (std::pair<int, std::vector<int>>{3, {1, 1}}));
}

TEST(heap, Simple2) {
  ASSERT_EQ(Heap_exe(2, 1, {1, 2}),
            (std::pair<int, std::vector<int>>{3, {1, 1}}));
}

TEST(heap, Simple3) {
  ASSERT_EQ(Heap_exe(6, 3, {3, 8, 9, 1, 4, 1}),
            (std::pair<int, std::vector<int>>{12, {3, 0, 0, 3, 0, 0}}));
}
