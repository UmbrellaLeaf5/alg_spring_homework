#include <gtest/gtest.h>

#include "hash_table.hpp"

TEST(HashTableTest, InsertAndGetValue) {
  HashTable<int> ht(10);
  ht.Insert(1, 10);
  ht.Insert(2, 20);
  ht.Insert(3, 30);

  EXPECT_EQ(ht.GetValue(1), 10);
  EXPECT_EQ(ht.GetValue(2), 20);
  EXPECT_EQ(ht.GetValue(3), 30);
}

TEST(HashTableTest, GetValueForNonExistentKey) {
  HashTable<int> ht(10);
  EXPECT_THROW(ht.GetValue(1), std::out_of_range);
}

TEST(HashTableTest, RemoveByKey) {
  HashTable<int> ht(10);
  ht.Insert(1, 10);
  ht.Insert(2, 20);
  ht.Insert(3, 30);

  ht.RemoveByKey(2);
  EXPECT_THROW(ht.GetValue(2), std::out_of_range);
  EXPECT_EQ(ht.GetValue(1), 10);
  EXPECT_EQ(ht.GetValue(3), 30);
}

TEST(HashTableTest, RemoveNonExistentKey) {
  HashTable<int> ht(10);
  ht.Insert(1, 10);
  ht.Insert(2, 20);
  EXPECT_THROW(ht.RemoveByKey(3), std::out_of_range);
}

TEST(HashTableTest, HashFunction) {
  HashTable<int> ht(10);
  EXPECT_LT(ht.HashFunction(1, 10), 10);
  EXPECT_LT(ht.HashFunction(2, 10), 10);
  EXPECT_LT(ht.HashFunction(3, 10), 10);
}

TEST(HashTableTest, HashFunctionDistribution) {
  HashTable<int> ht(10);
  std::vector<int> bucketCounts(10, 0);

  for (int i = 0; i < 10000; i++) {
    size_t index = ht.HashFunction(i, 10);
    bucketCounts[index]++;
  }

  for (int count : bucketCounts) {
    EXPECT_GT(count, 500);
    EXPECT_LT(count, 1500);
  }
}

TEST(HashTableTest, CollisionHandling) {
  HashTable<int> ht(10);
  ht.Insert(1, 10);
  ht.Insert(11, 20);
  ht.Insert(21, 30);

  EXPECT_EQ(ht.GetValue(1), 10);
  EXPECT_EQ(ht.GetValue(11), 20);
  EXPECT_EQ(ht.GetValue(21), 30);
}

TEST(HashTableTest, ManyInsertionsAndDeletions) {
  HashTable<int> ht(10);
  for (int i = 0; i < 1000; i++) {
    ht.Insert(i, i * 10);
  }

  for (int i = 0; i < 1000; i++) {
    EXPECT_EQ(ht.GetValue(i), i * 10);
  }

  for (int i = 0; i < 1000; i += 2) {
    ht.RemoveByKey(i);
  }

  for (int i = 0; i < 1000; i++) {
    if (i % 2 == 0) {
      EXPECT_THROW(ht.GetValue(i), std::out_of_range);
    } else {
      EXPECT_EQ(ht.GetValue(i), i * 10);
    }
  }
}

TEST(HashTableTest, ResizeHashTable) {
  HashTable<int> ht(10);
  for (int i = 0; i < 100; i++) {
    ht.Insert(i, i * 10);
  }

  EXPECT_EQ(ht.Size(), 10);

  for (int i = 0; i < 100; i++) {
    EXPECT_EQ(ht.GetValue(i), i * 10);
  }
}
