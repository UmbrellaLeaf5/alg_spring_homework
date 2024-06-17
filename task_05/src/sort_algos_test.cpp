// std libs:
#include <limits>
#include <random>
#include <string>

// test lib:
#include <gtest/gtest.h>

// sort algos:
#include "heap_sort.hpp"
#include "merge_sort.hpp"
#include "quick_sort.hpp"

// my libs:
#include <util.hpp>

TEST(SortAlgos, Simple) {
  std::vector<int> a{5, 3, 4, 1, 2};
  HeapSort(a);
  EXPECT_TRUE(std::is_sorted(a.begin(), a.end()));

  std::vector<int> b{5, 3, 4, 1, 2};
  MergeSort(b);
  EXPECT_TRUE(std::is_sorted(b.begin(), b.end()));

  std::vector<int> c{5, 3, 4, 1, 2};
  QuickSort(c);
  EXPECT_TRUE(std::is_sorted(c.begin(), c.end()));
}

TEST(SortAlgos, Empty) {
  std::vector<int> a;
  HeapSort(a);
  EXPECT_TRUE(a.empty());

  std::vector<int> b;
  MergeSort(b);
  EXPECT_TRUE(b.empty());

  std::vector<int> c;
  QuickSort(c);
  EXPECT_TRUE(c.empty());
}

TEST(SortAlgos, Sorted) {
  std::vector<int> a{1, 2, 3, 4, 5};
  HeapSort(a);
  EXPECT_TRUE(std::is_sorted(a.begin(), a.end()));

  std::vector<int> b{1, 2, 3, 4, 5};
  MergeSort(b);
  EXPECT_TRUE(std::is_sorted(b.begin(), b.end()));

  std::vector<int> c{1, 2, 3, 4, 5};
  QuickSort(c);
  EXPECT_TRUE(std::is_sorted(c.begin(), c.end()));
}

TEST(SortAlgos, Double) {
  std::vector<double> a{5.3, 3.1, 4.7, 1.2, 2.8};
  HeapSort(a);
  EXPECT_TRUE(std::is_sorted(a.begin(), a.end()));

  std::vector<double> b{5.3, 3.1, 4.7, 1.2, 2.8};
  MergeSort(b);
  EXPECT_TRUE(std::is_sorted(b.begin(), b.end()));

  std::vector<double> c{5.3, 3.1, 4.7, 1.2, 2.8};
  QuickSort(c);
  EXPECT_TRUE(std::is_sorted(c.begin(), c.end()));
}

TEST(SortAlgos, Strings) {
  std::vector<std::string> a{"apple", "banana", "cherry", "date", "elderberry"};
  HeapSort(a);
  EXPECT_TRUE(std::is_sorted(a.begin(), a.end()));

  std::vector<std::string> b{"apple", "banana", "cherry", "date", "elderberry"};
  MergeSort(b);
  EXPECT_TRUE(std::is_sorted(b.begin(), b.end()));

  std::vector<std::string> c{"apple", "banana", "cherry", "date", "elderberry"};
  QuickSort(c);
  EXPECT_TRUE(std::is_sorted(c.begin(), c.end()));
}

TEST(SortAlgos, Duplicates) {
  std::vector<int> a{5, 3, 4, 1, 2, 3, 1, 4};
  HeapSort(a);
  EXPECT_TRUE(std::is_sorted(a.begin(), a.end()));

  std::vector<int> b{5, 3, 4, 1, 2, 3, 1, 4};
  MergeSort(b);
  EXPECT_TRUE(std::is_sorted(b.begin(), b.end()));

  std::vector<int> c{5, 3, 4, 1, 2, 3, 1, 4};
  QuickSort(c);
  EXPECT_TRUE(std::is_sorted(c.begin(), c.end()));
}

TEST(SortAlgos, NegativeNumbers) {
  std::vector<int> a{-5, -3, -4, -1, -2};
  HeapSort(a);
  EXPECT_TRUE(std::is_sorted(a.begin(), a.end()));

  std::vector<int> b{-5, -3, -4, -1, -2};
  MergeSort(b);
  EXPECT_TRUE(std::is_sorted(b.begin(), b.end()));

  std::vector<int> c{-5, -3, -4, -1, -2};
  QuickSort(c);
  EXPECT_TRUE(std::is_sorted(c.begin(), c.end()));
}

TEST(SortAlgos, Characters) {
  std::vector<char> a{'e', 'a', 'c', 'b', 'd'};
  HeapSort(a);
  EXPECT_TRUE(std::is_sorted(a.begin(), a.end()));

  std::vector<char> b{'e', 'a', 'c', 'b', 'd'};
  MergeSort(b);
  EXPECT_TRUE(std::is_sorted(b.begin(), b.end()));

  std::vector<char> c{'e', 'a', 'c', 'b', 'd'};
  QuickSort(c);
  EXPECT_TRUE(std::is_sorted(c.begin(), c.end()));
}

struct TestType {
  int value;
  auto operator<=>(const TestType& other) const = default;
};

TEST(SortAlgos, CustomTestType) {
  std::vector<TestType> a{{5}, {3}, {4}, {1}, {2}};
  HeapSort(a);
  EXPECT_TRUE(std::is_sorted(a.begin(), a.end()));

  std::vector<TestType> b{{5}, {3}, {4}, {1}, {2}};
  MergeSort(b);
  EXPECT_TRUE(std::is_sorted(b.begin(), b.end()));

  std::vector<TestType> c{{5}, {3}, {4}, {1}, {2}};
  QuickSort(c);
  EXPECT_TRUE(std::is_sorted(c.begin(), c.end()));
}

struct NegativeTestType {
  int value;
  auto operator<=>(const NegativeTestType& other) const = default;
};

TEST(SortAlgos, CustomNegativeTestType) {
  std::vector<NegativeTestType> a{{-5}, {-3}, {-4}, {-1}, {-2}};
  HeapSort(a);
  EXPECT_TRUE(std::is_sorted(a.begin(), a.end()));

  std::vector<NegativeTestType> b{{-5}, {-3}, {-4}, {-1}, {-2}};
  MergeSort(b);
  EXPECT_TRUE(std::is_sorted(b.begin(), b.end()));

  std::vector<NegativeTestType> c{{-5}, {-3}, {-4}, {-1}, {-2}};
  QuickSort(c);
  EXPECT_TRUE(std::is_sorted(c.begin(), c.end()));
}

struct FloatTestType {
  float value;
  auto operator<=>(const FloatTestType& other) const = default;
};

TEST(SortAlgos, CustomFloatTestType) {
  std::vector<FloatTestType> a{{5.3f}, {3.1f}, {4.7f}, {1.2f}, {2.8f}};
  HeapSort(a);
  EXPECT_TRUE(std::is_sorted(a.begin(), a.end()));

  std::vector<FloatTestType> b{{5.3f}, {3.1f}, {4.7f}, {1.2f}, {2.8f}};
  MergeSort(b);
  EXPECT_TRUE(std::is_sorted(b.begin(), b.end()));

  std::vector<FloatTestType> c{{5.3f}, {3.1f}, {4.7f}, {1.2f}, {2.8f}};
  QuickSort(c);
  EXPECT_TRUE(std::is_sorted(c.begin(), c.end()));
}

struct PairTestType {
  int first;
  double second;
  auto operator<=>(const PairTestType& other) const = default;
};

TEST(SortAlgos, CustomPairTestType) {
  std::vector<PairTestType> a{
      {5, 3.14}, {3, 2.71}, {4, 1.62}, {1, 0.57}, {2, 6.28}};
  HeapSort(a);
  EXPECT_TRUE(std::is_sorted(a.begin(), a.end()));

  std::vector<PairTestType> b{
      {5, 3.14}, {3, 2.71}, {4, 1.62}, {1, 0.57}, {2, 6.28}};
  MergeSort(b);
  EXPECT_TRUE(std::is_sorted(b.begin(), b.end()));

  std::vector<PairTestType> c{
      {5, 3.14}, {3, 2.71}, {4, 1.62}, {1, 0.57}, {2, 6.28}};
  QuickSort(c);
  EXPECT_TRUE(std::is_sorted(c.begin(), c.end()));
}

struct BoolTestType {
  bool value;
  auto operator<=>(const BoolTestType& other) const = default;
};

TEST(SortAlgos, CustomBoolTestType) {
  std::vector<BoolTestType> a{{true}, {false}, {true}, {false}, {true}};
  HeapSort(a);
  EXPECT_TRUE(std::is_sorted(a.begin(), a.end()));

  std::vector<BoolTestType> b{{true}, {false}, {true}, {false}, {true}};
  MergeSort(b);
  EXPECT_TRUE(std::is_sorted(b.begin(), b.end()));

  std::vector<BoolTestType> c{{true}, {false}, {true}, {false}, {true}};
  QuickSort(c);
  EXPECT_TRUE(std::is_sorted(c.begin(), c.end()));
}

struct CharTestType {
  char value;
  auto operator<=>(const CharTestType& other) const = default;
};

TEST(SortAlgos, CustomCharTestType) {
  std::vector<CharTestType> a{{'e'}, {'a'}, {'c'}, {'b'}, {'d'}};
  HeapSort(a);
  EXPECT_TRUE(std::is_sorted(a.begin(), a.end()));

  std::vector<CharTestType> b{{'e'}, {'a'}, {'c'}, {'b'}, {'d'}};
  MergeSort(b);
  EXPECT_TRUE(std::is_sorted(b.begin(), b.end()));

  std::vector<CharTestType> c{{'e'}, {'a'}, {'c'}, {'b'}, {'d'}};
  QuickSort(c);
  EXPECT_TRUE(std::is_sorted(c.begin(), c.end()));
}

TEST(SortAlgos, VeryLargeNumbers_HeapSort) {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<int64_t> dis(
      std::numeric_limits<int64_t>::min(), std::numeric_limits<int64_t>::max());

  std::vector<int64_t> a;

  for (int i = 0; i < 1000000; ++i) {
    int64_t num = dis(gen);
    a.push_back(num);
  }

  HeapSort(a);
  EXPECT_TRUE(std::is_sorted(a.begin(), a.end()));
}

TEST(SortAlgos, VeryLargeNumbers_MergeSort) {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<int64_t> dis(
      std::numeric_limits<int64_t>::min(), std::numeric_limits<int64_t>::max());

  std::vector<int64_t> a;

  for (int i = 0; i < 1000000; ++i) {
    int64_t num = dis(gen);
    a.push_back(num);
  }

  MergeSort(a);
  EXPECT_TRUE(std::is_sorted(a.begin(), a.end()));
}

TEST(SortAlgos, VeryLargeNumbers_QuickSort) {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<int64_t> dis(
      std::numeric_limits<int64_t>::min(), std::numeric_limits<int64_t>::max());

  std::vector<int64_t> a;

  for (int i = 0; i < 1000000; ++i) {
    int64_t num = dis(gen);
    a.push_back(num);
  }

  QuickSort(a);
  EXPECT_TRUE(std::is_sorted(a.begin(), a.end()));
}

TEST(SortAlgos, VeryLongStrings_HeapSort) {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<char> dis('a', 'z');

  std::vector<std::string> a;

  for (int i = 0; i < 10000; ++i) {
    std::string str(1000, 'a');
    for (char& c : str) {
      c = dis(gen);
    }
    a.push_back(str);
  }

  HeapSort(a);
  EXPECT_TRUE(std::is_sorted(a.begin(), a.end()));
}

TEST(SortAlgos, VeryLongStrings_MergeSort) {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<char> dis('a', 'z');

  std::vector<std::string> a;

  for (int i = 0; i < 10000; ++i) {
    std::string str(1000, 'a');
    for (char& c : str) {
      c = dis(gen);
    }
    a.push_back(str);
  }

  MergeSort(a);
  EXPECT_TRUE(std::is_sorted(a.begin(), a.end()));
}

TEST(SortAlgos, VeryLongStrings_QuickSort) {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<char> dis('a', 'z');

  std::vector<std::string> a;

  for (int i = 0; i < 10000; ++i) {
    std::string str(1000, 'a');
    for (char& c : str) {
      c = dis(gen);
    }
    a.push_back(str);
  }

  QuickSort(a);
  EXPECT_TRUE(std::is_sorted(a.begin(), a.end()));
}
