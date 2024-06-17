// test lib:
#include <gtest/gtest.h>

// my libs:
#include "binary_heap.hpp"
#include "util.hpp"

// std libs:
#include <iostream>

// std usings:
using std::cout, std::cin, std::endl;

TEST(BinaryMinHeap_test, Empty) {
  BinaryMinHeap<int> heap;
  ASSERT_EQ(heap.Empty(), true);
  ASSERT_EQ(heap.Size(), 0);
  heap.Add(1);
  ASSERT_EQ(heap.Empty(), false);
  ASSERT_EQ(heap.Size(), 1);
  ASSERT_EQ(heap.ExtractRoot(), 1);
  EXPECT_THROW(heap.GetRoot(), std::out_of_range);
  EXPECT_THROW(heap.ExtractRoot(), std::out_of_range);
}

TEST(BinaryMinHeap_test, WithoutDuplicates) {
  BinaryMinHeap<int> heap{};
  for (int value : {3, 1, 2, 4, 5}) heap.Add(value);
  ASSERT_EQ(heap.ExtractRoot(), 1);
  ASSERT_EQ(heap.ExtractRoot(), 2);
  ASSERT_EQ(heap.ExtractRoot(), 3);
  ASSERT_EQ(heap.ExtractRoot(), 4);
  ASSERT_EQ(heap.ExtractRoot(), 5);
}

TEST(BinaryMinHeap_test, WithDuplicates) {
  BinaryMinHeap<int> heap{};
  for (int value : {6, 7, 7, 3, 3, 3, 1, 2}) heap.Add(value);
  ASSERT_EQ(heap.ExtractRoot(), 1);
  ASSERT_EQ(heap.ExtractRoot(), 2);
  ASSERT_EQ(heap.ExtractRoot(), 3);
  ASSERT_EQ(heap.ExtractRoot(), 3);
  ASSERT_EQ(heap.ExtractRoot(), 3);
  ASSERT_EQ(heap.ExtractRoot(), 6);
  ASSERT_EQ(heap.ExtractRoot(), 7);
  ASSERT_EQ(heap.ExtractRoot(), 7);
}

TEST(BinaryMinHeap_test, InitListConstructor) {
  BinaryMinHeap<int> heap{1, 2, 3};
  ASSERT_EQ(heap.ExtractRoot(), 1);
  ASSERT_EQ(heap.ExtractRoot(), 2);
  ASSERT_EQ(heap.ExtractRoot(), 3);
}

TEST(BinaryMinHeap_test, EmptyHeapDataTest) {
  BinaryMinHeap<int> heap;
  EXPECT_TRUE(heap.Data().empty());
  ASSERT_EQ(heap.Data().empty(), heap.Empty());
}

TEST(BinaryMinHeap_test, AddElementTest) {
  BinaryMinHeap<int> heap;
  heap.Add(5);
  EXPECT_EQ(heap.Data().size(), 1);
  EXPECT_EQ(heap.GetMin(), 5);
}

TEST(BinaryMinHeap_test, ExtractMinTest) {
  BinaryMinHeap<int> heap;
  heap.Add(5);
  heap.Add(3);
  heap.Add(7);
  EXPECT_EQ(heap.ExtractMin(), 3);
  EXPECT_EQ(heap.Data().size(), 2);
}

TEST(BinaryMinHeap_test, GetMinTest) {
  BinaryMinHeap<int> heap;
  heap.Add(5);
  heap.Add(3);
  heap.Add(7);
  EXPECT_EQ(heap.GetMin(), 3);
}

TEST(BinaryMinHeap_test, MaintainHeapPropertyAfterAdd) {
  BinaryMinHeap<int> heap;
  heap.Add(5);
  heap.Add(3);
  heap.Add(7);
  heap.Add(2);
  heap.Add(6);
  EXPECT_EQ(heap.Data()[0], 2);  // Минимальный элемент должен быть 2
}

TEST(BinaryMinHeap_test, MaintainHeapPropertyAfterExtractMin) {
  BinaryMinHeap<int> heap;
  heap.Add(5);
  heap.Add(3);
  heap.Add(7);
  heap.Add(2);
  heap.Add(6);
  heap.ExtractMin();
  EXPECT_EQ(heap.GetMin(),
            3);  // После извлечения минимальный элемент должен быть 3
}

TEST(BinaryMinHeap_test, AddDuplicateElements) {
  BinaryMinHeap<int> heap;
  heap.Add(5);
  heap.Add(3);
  heap.Add(5);
  EXPECT_EQ(heap.GetMin(), 3);  // Минимальный элемент должен быть 3
}

TEST(BinaryMinHeap_test, AddAndRemoveNegativeElements) {
  BinaryMinHeap<int> heap;
  heap.Add(-5);
  heap.Add(3);
  heap.Add(-7);
  heap.ExtractMin();
  EXPECT_EQ(heap.GetMin(), -5);  // Минимальный элемент должен быть -5
}

TEST(BinaryMinHeap_test, ExtractMinFromEmptyHeap) {
  BinaryMinHeap<int> heap;
  ASSERT_THROW(heap.ExtractMin(), std::out_of_range);
}

TEST(BinaryMinHeap_test, AddAndExtractMinLargeData) {
  BinaryMinHeap<int> heap;
  for (int i = 1000; i > 0; --i) {
    heap.Add(i);
  }
  for (int i = 1; i <= 500; ++i) {
    EXPECT_EQ(heap.ExtractMin(), i);
  }
}

TEST(BinaryMinHeap_test, ExtractMinWithDuplicates) {
  BinaryMinHeap<int> heap;
  heap.Add(5);
  heap.Add(3);
  heap.Add(3);
  heap.Add(7);
  heap.Add(2);
  EXPECT_EQ(heap.ExtractMin(), 2);
  EXPECT_EQ(heap.ExtractMin(), 3);
  EXPECT_EQ(heap.ExtractMin(), 3);
}

TEST(BinaryMinHeap_test, ExtractMinAfterInitializationWithVector) {
  std::vector<int> data = {8, 2, 10, 3, 5};
  BinaryMinHeap<int> heap(data);
  EXPECT_EQ(heap.ExtractMin(), 2);
}

TEST(BinaryMinHeap_test, ExtractMinAfterInitializationWithInitializerList) {
  BinaryMinHeap<int> heap = {15, 7, 9, 4, 11};
  EXPECT_EQ(heap.ExtractMin(), 4);
}

TEST(BinaryMinHeap_test, ExtractMinAfterInitializationAndAdd) {
  std::vector<int> data = {8, 2, 10, 3, 5};
  BinaryMinHeap<int> heap(data);
  heap.Add(4);
  heap.Add(1);
  EXPECT_EQ(heap.ExtractMin(), 1);
}

TEST(BinaryMaxHeap_test, Empty) {
  BinaryMaxHeap<int> heap;
  ASSERT_EQ(heap.Empty(), true);
  ASSERT_EQ(heap.Size(), 0);
  heap.Add(1);
  ASSERT_EQ(heap.Empty(), false);
  ASSERT_EQ(heap.Size(), 1);
  ASSERT_EQ(heap.ExtractRoot(), 1);
  EXPECT_THROW(heap.GetRoot(), std::out_of_range);
  EXPECT_THROW(heap.ExtractRoot(), std::out_of_range);
}

TEST(BinaryMaxHeap_test, WithoutDuplicates) {
  BinaryMaxHeap<int> heap{};
  for (int value : {3, 1, 2, 4, 5}) heap.Add(value);
  ASSERT_EQ(heap.ExtractRoot(), 5);
  ASSERT_EQ(heap.ExtractRoot(), 4);
  ASSERT_EQ(heap.ExtractRoot(), 3);
  ASSERT_EQ(heap.ExtractRoot(), 2);
  ASSERT_EQ(heap.ExtractRoot(), 1);
}

TEST(BinaryMaxHeap_test, WithDuplicates) {
  BinaryMaxHeap<int> heap{};
  for (int value : {6, 7, 7, 3, 3, 3, 1, 2}) heap.Add(value);
  ASSERT_EQ(heap.ExtractRoot(), 7);
  ASSERT_EQ(heap.ExtractRoot(), 7);
  ASSERT_EQ(heap.ExtractRoot(), 6);
  ASSERT_EQ(heap.ExtractRoot(), 3);
  ASSERT_EQ(heap.ExtractRoot(), 3);
  ASSERT_EQ(heap.ExtractRoot(), 3);
  ASSERT_EQ(heap.ExtractRoot(), 2);
  ASSERT_EQ(heap.ExtractRoot(), 1);
}

TEST(BinaryMaxHeap_test, InitListConstructor) {
  BinaryMaxHeap<int> heap{1, 2, 3};
  ASSERT_EQ(heap.ExtractRoot(), 3);
  ASSERT_EQ(heap.ExtractRoot(), 2);
  ASSERT_EQ(heap.ExtractRoot(), 1);
}

TEST(BinaryMaxHeap_test, EmptyHeapDataTest) {
  BinaryMaxHeap<int> heap;
  EXPECT_TRUE(heap.Data().empty());
  ASSERT_EQ(heap.Data().empty(), heap.Empty());
}

TEST(BinaryMaxHeap_test, AddElementTest) {
  BinaryMaxHeap<int> heap;
  heap.Add(5);
  EXPECT_EQ(heap.Data().size(), 1);
  EXPECT_EQ(heap.GetMax(), 5);
}

TEST(BinaryMaxHeap_test, ExtractMaxTest) {
  BinaryMaxHeap<int> heap;
  heap.Add(5);
  heap.Add(3);
  heap.Add(7);
  EXPECT_EQ(heap.ExtractMax(), 7);
  EXPECT_EQ(heap.Data().size(), 2);
}

TEST(BinaryMaxHeap_test, GetMaxTest) {
  BinaryMaxHeap<int> heap;
  heap.Add(5);
  heap.Add(3);
  heap.Add(7);
  EXPECT_EQ(heap.GetMax(), 7);
}

TEST(BinaryMaxHeap_test, MaintainHeapPropertyAfterAdd) {
  BinaryMaxHeap<int> heap;
  heap.Add(5);
  heap.Add(3);
  heap.Add(7);
  heap.Add(2);
  heap.Add(6);
  EXPECT_EQ(heap.Data()[0], 7);  // Минимальный элемент должен быть 2
}

TEST(BinaryMaxHeap_test, MaintainHeapPropertyAfterExtractMax) {
  BinaryMaxHeap<int> heap;
  heap.Add(5);
  heap.Add(3);
  heap.Add(7);
  heap.Add(2);
  heap.Add(6);
  heap.ExtractMax();
  EXPECT_EQ(heap.GetMax(),
            6);  // После извлечения минимальный элемент должен быть 3
}

TEST(BinaryMaxHeap_test, AddDuplicateElements) {
  BinaryMaxHeap<int> heap;
  heap.Add(5);
  heap.Add(3);
  heap.Add(5);
  EXPECT_EQ(heap.GetMax(), 5);  // Минимальный элемент должен быть 3
}

TEST(BinaryMaxHeap_test, AddAndRemoveNegativeElements) {
  BinaryMaxHeap<int> heap;
  heap.Add(-5);
  heap.Add(3);
  heap.Add(-7);
  heap.ExtractMax();
  EXPECT_EQ(heap.GetMax(), -5);  // Минимальный элемент должен быть -5
}

TEST(BinaryMaxHeap_test, ExtractMaxFromEmptyHeap) {
  BinaryMaxHeap<int> heap;
  ASSERT_THROW(heap.ExtractMax(), std::out_of_range);
}

TEST(BinaryMaxHeap_test, AddAndExtractMaxLargeData) {
  BinaryMaxHeap<int> heap;
  for (int i = 1000; i > 0; --i) {
    heap.Add(i);
  }
  for (int i = 1; i <= 500; ++i) {
    EXPECT_EQ(heap.ExtractMax(), 1000 - i + 1);
  }
}

TEST(BinaryMaxHeap_test, ExtractMaxWithDuplicates) {
  BinaryMaxHeap<int> heap;
  heap.Add(5);
  heap.Add(3);
  heap.Add(3);
  heap.Add(7);
  heap.Add(2);
  EXPECT_EQ(heap.ExtractMax(), 7);
  EXPECT_EQ(heap.ExtractMax(), 5);
  EXPECT_EQ(heap.ExtractMax(), 3);
}

TEST(BinaryMaxHeap_test, ExtractMaxAfterInitializationWithVector) {
  std::vector<int> data = {8, 2, 10, 3, 5};
  BinaryMaxHeap<int> heap(data);
  EXPECT_EQ(heap.ExtractMax(), 10);
}

TEST(BinaryMaxHeap_test, ExtractMaxAfterInitializationWithInitializerList) {
  BinaryMaxHeap<int> heap = {15, 7, 9, 4, 11};
  EXPECT_EQ(heap.ExtractMax(), 15);
}

TEST(BinaryMaxHeap_test, ExtractMaxAfterInitializationAndAdd) {
  std::vector<int> data = {8, 2, 10, 3, 5};
  BinaryMaxHeap<int> heap(data);
  heap.Add(4);
  heap.Add(1);
  EXPECT_EQ(heap.ExtractMax(), 10);
}
