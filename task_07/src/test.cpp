#include <gtest/gtest.h>

#include "avl_tree.hpp"

TEST(AVLTreeTest, Simple) {
  AVLTree<short> tree;
  ASSERT_EQ(tree.Contains(10), false);
  ASSERT_EQ(tree.Contains(5), false);
  ASSERT_EQ(tree.Contains(15), false);
  tree.Push(10);
  tree.Push(5);
  tree.Push(15);
  ASSERT_EQ(tree.Contains(10), true);
  ASSERT_EQ(tree.Contains(5), true);
  ASSERT_EQ(tree.Contains(15), true);
  tree.Push(12);
  tree.Pop(5);
  ASSERT_EQ(tree.Contains(5), false);
  tree.Pop(15);
  ASSERT_EQ(tree.Contains(15), false);
}

TEST(AVLTreeTest, ConstructionFromVector) {
  std::vector<int> v = {1, 2, 3, 4, 5};
  AVLTree<int> tree(v);
  ASSERT_TRUE(tree.Contains(1));
  ASSERT_TRUE(tree.Contains(2));
  ASSERT_TRUE(tree.Contains(3));
  ASSERT_TRUE(tree.Contains(4));
  ASSERT_TRUE(tree.Contains(5));
}

TEST(AVLTreeTest, ConstructionFromInitializerList) {
  AVLTree<int> tree{1, 2, 3, 4, 5};
  ASSERT_TRUE(tree.Contains(1));
  ASSERT_TRUE(tree.Contains(2));
  ASSERT_TRUE(tree.Contains(3));
  ASSERT_TRUE(tree.Contains(4));
  ASSERT_TRUE(tree.Contains(5));
}

TEST(AVLTreeTest, ConstructionFromList) {
  std::list<int> l = {1, 2, 3, 4, 5};
  AVLTree<int> tree(l);
  ASSERT_TRUE(tree.Contains(1));
  ASSERT_TRUE(tree.Contains(2));
  ASSERT_TRUE(tree.Contains(3));
  ASSERT_TRUE(tree.Contains(4));
  ASSERT_TRUE(tree.Contains(5));
}

TEST(AVLTreeTest, PushAndContains) {
  AVLTree<int> tree;
  ASSERT_FALSE(tree.Contains(1));
  tree.Push(1);
  ASSERT_TRUE(tree.Contains(1));
}

TEST(AVLTreeTest, PopAndContains) {
  AVLTree<int> tree{1, 2, 3, 4, 5};
  ASSERT_TRUE(tree.Contains(3));
  tree.Pop(3);
  ASSERT_FALSE(tree.Contains(3));
}

TEST(AVLTreeTest, CanStoreStrings) {
  AVLTree<std::string> tree;
  tree.Push("apple");
  tree.Push("banana");
  tree.Push("cherry");
  ASSERT_TRUE(tree.Contains("apple"));
  ASSERT_TRUE(tree.Contains("banana"));
  ASSERT_TRUE(tree.Contains("cherry"));
}

TEST(AVLTreeTest, CanStoreFloats) {
  AVLTree<float> tree;
  tree.Push(3.14f);
  tree.Push(2.71f);
  tree.Push(1.41f);
  ASSERT_TRUE(tree.Contains(3.14f));
  ASSERT_TRUE(tree.Contains(2.71f));
  ASSERT_TRUE(tree.Contains(1.41f));
}

TEST(AVLTreeTest, CanStoreLargeKeys) {
  AVLTree<long long> tree;
  tree.Push(123456789LL);
  tree.Push(987654321LL);
  tree.Push(456789123LL);
  ASSERT_TRUE(tree.Contains(123456789LL));
  ASSERT_TRUE(tree.Contains(987654321LL));
  ASSERT_TRUE(tree.Contains(456789123LL));
}

TEST(AVLTreeTest, CanStoreNegativeKeys) {
  AVLTree<int> tree;
  tree.Push(-10);
  tree.Push(-5);
  tree.Push(0);
  ASSERT_TRUE(tree.Contains(-10));
  ASSERT_TRUE(tree.Contains(-5));
  ASSERT_TRUE(tree.Contains(0));
}
