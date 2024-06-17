// std libs:
#include <deque>
#include <initializer_list>
#include <list>
#include <stack>
#include <stdexcept>
#include <string>

// test lib:
#include <gtest/gtest.h>

// my lib:
#include "list_stack.hpp"

using namespace std;

TEST(ListStack_test, Simple) {
  ListStack<int> stack;
  // в стандартной реализации у стека pop() имеет void
  stack.Push(1);              // ListStack [1]
  ASSERT_EQ(stack.Top(), 1);  // ListStack [1]
  stack.Pop();                // ListStack []
  stack.Push(1);              // ListStack [1]
  stack.Push(2);              // ListStack [1, 2]
  ASSERT_EQ(stack.Top(), 2);  // ListStack [1, 2]
  stack.Pop();                // ListStack [1]
  ASSERT_EQ(stack.Top(), 1);  // ListStack [1]
  stack.Pop();                // ListStack []
  stack.Push(1);              // ListStack [1]
  stack.Push(2);              // ListStack [1, 2]
  ASSERT_EQ(stack.Top(), 2);  // ListStack [1, 2]
  stack.Pop();                // ListStack [1]
  stack.Push(3);              // ListStack [1, 3]
  ASSERT_EQ(stack.Top(), 3);  // ListStack [1, 3]
  stack.Pop();                // ListStack [1]
  ASSERT_EQ(stack.Top(), 1);  // ListStack [1]
  stack.Pop();
}

TEST(ListStack_test, Size_test) {
  auto stack = ListStack<float>();
  ASSERT_EQ(stack.Size(), 0);
}

TEST(ListStack_test, PushTop_test) {
  auto stack = ListStack<int>();
  stack.Push(6);
  ASSERT_EQ(stack.Top(), 6);
}

TEST(ListStack_test, PushTopPop_test_1) {
  auto stack = ListStack<string>();
  stack.Push();
  stack.Push();
  stack.Pop();
  stack.Pop();
  EXPECT_THROW(stack.Top(), logic_error);
}

TEST(ListStack_test, PushTopPop_test_2) {
  auto stack = ListStack<string>();
  stack.Push("I want to write a random text, but");
  stack.Push("since I have to check for the correctness of words, I need");
  stack.Push(
      "to make sure there are no errors in it, so I am writing this strange "
      "sentence through a translator");
  stack.Push("the translators are very cool, you knew about this,");
  stack.Push(
      "I assume that they have been using neural networks for a long time");
  ASSERT_EQ(
      stack.Top(),
      "I assume that they have been using neural networks for a long time");
  stack.Pop();
  stack.Pop();
  stack.Pop();
  ASSERT_EQ(stack.Top(),
            "since I have to check for the correctness of words, I need");
}

TEST(ListStack_test, PushSize_test_1) {
  auto stack = ListStack<int>();
  stack.Push();
  stack.Push();
  ASSERT_EQ(stack.Size(), 2);
}

TEST(ListStack_test, PushSize_test_2) {
  auto stack = ListStack<double>();
  stack.Push();
  stack.Push();
  stack.Push();
  stack.Push();
  stack.Push();
  ASSERT_EQ(stack.Size(), 5);
}

TEST(ListStack_test, PushSize_test_3) {
  struct A {
    double a;
    string s;
    vector<A> b;
    list<vector<deque<A>>> c;
    A() = default;
  };

  auto stack = ListStack<A>();
  stack.Push();
  stack.Push();
  stack.Push();
  stack.Push();
  stack.Push();
  ASSERT_EQ(stack.Size(), 5);
}

TEST(ListStack_test, PushPop_test_1) {
  auto stack = ListStack<double>();
  stack.Push();
  stack.Push();
  stack.Push();
  stack.Pop();
  stack.Pop();
  ASSERT_EQ(stack.Size(), 1);
}

TEST(ListStack_test, PushPop_test_2) {
  auto stack = ListStack<double>();
  stack.Push();
  stack.Push();
  stack.Pop();
  stack.Pop();
  EXPECT_THROW(stack.Pop(), logic_error);
}

TEST(ListStack_test, PushRange_initializer_list_SizePopTop_test) {
  auto stack = ListStack<int>();
  stack.PushRange({4, 3, 2, 1});
  ASSERT_EQ(stack.Size(), 4);
  ASSERT_EQ(stack.Top(), 1);
  stack.Pop();
  ASSERT_EQ(stack.Size(), 3);
  ASSERT_EQ(stack.Top(), 2);
  stack.Pop();
  ASSERT_EQ(stack.Size(), 2);
  ASSERT_EQ(stack.Top(), 3);
  stack.Pop();
  ASSERT_EQ(stack.Size(), 1);
  ASSERT_EQ(stack.Top(), 4);
  stack.Pop();
  EXPECT_THROW(stack.Pop(), logic_error);
  EXPECT_THROW(stack.Top(), logic_error);
}

TEST(ListStack_test, PushRange_vector_SizePopTop_test_1) {
  auto stack = ListStack<int>();
  stack.PushRange(std::vector(4, 0));
  ASSERT_EQ(stack.Size(), 4);
  ASSERT_EQ(stack.Top(), 0);
  stack.Pop();
  ASSERT_EQ(stack.Size(), 3);
  ASSERT_EQ(stack.Top(), 0);
  stack.Pop();
  ASSERT_EQ(stack.Size(), 2);
  ASSERT_EQ(stack.Top(), 0);
  stack.Pop();
  ASSERT_EQ(stack.Size(), 1);
  ASSERT_EQ(stack.Top(), 0);
  stack.Pop();
  EXPECT_THROW(stack.Pop(), logic_error);
  EXPECT_THROW(stack.Top(), logic_error);
}

TEST(ListStack_test, PushRange_vector_SizePopTop_test_2) {
  auto stack = ListStack<int>();
  stack.PushRange(std::vector({4, 3, 2, 1}));
  ASSERT_EQ(stack.Size(), 4);
  ASSERT_EQ(stack.Top(), 1);
  stack.Pop();
  ASSERT_EQ(stack.Size(), 3);
  ASSERT_EQ(stack.Top(), 2);
  stack.Pop();
  ASSERT_EQ(stack.Size(), 2);
  ASSERT_EQ(stack.Top(), 3);
  stack.Pop();
  ASSERT_EQ(stack.Size(), 1);
  ASSERT_EQ(stack.Top(), 4);
  stack.Pop();
  EXPECT_THROW(stack.Pop(), logic_error);
  EXPECT_THROW(stack.Top(), logic_error);
}

TEST(ListStack_test, PushRange_std_stack_SizePopTop_test) {
  auto stack = ListStack<int>();
  std::stack<int> std_stack;
  std_stack.push(4);
  std_stack.push(3);
  std_stack.push(2);
  std_stack.push(1);
  stack.PushRange(std_stack);
  ASSERT_EQ(stack.Size(), 4);
  ASSERT_EQ(stack.Top(), 1);
  stack.Pop();
  ASSERT_EQ(stack.Size(), 3);
  ASSERT_EQ(stack.Top(), 2);
  stack.Pop();
  ASSERT_EQ(stack.Size(), 2);
  ASSERT_EQ(stack.Top(), 3);
  stack.Pop();
  ASSERT_EQ(stack.Size(), 1);
  ASSERT_EQ(stack.Top(), 4);
  stack.Pop();
  EXPECT_THROW(stack.Pop(), logic_error);
  EXPECT_THROW(stack.Top(), logic_error);
}

TEST(ListStack_test, PushRange_Stack_SizePopTop_test) {
  auto stack = ListStack<int>();
  ListStack<int> my_stack;
  my_stack.Push(4);
  my_stack.Push(3);
  my_stack.Push(2);
  my_stack.Push(1);
  stack.PushRange(my_stack);
  ASSERT_EQ(stack.Size(), 4);
  ASSERT_EQ(stack.Top(), 1);
  stack.Pop();
  ASSERT_EQ(stack.Size(), 3);
  ASSERT_EQ(stack.Top(), 2);
  stack.Pop();
  ASSERT_EQ(stack.Size(), 2);
  ASSERT_EQ(stack.Top(), 3);
  stack.Pop();
  ASSERT_EQ(stack.Size(), 1);
  ASSERT_EQ(stack.Top(), 4);
  stack.Pop();
  EXPECT_THROW(stack.Pop(), logic_error);
  EXPECT_THROW(stack.Top(), logic_error);
}

TEST(ListStack_test, Swap) {
  ListStack<int> stack1, stack2;

  stack1.Push(1);
  stack1.Push(2);
  stack1.Push(3);

  stack2.Push(4);
  stack2.Push(5);
  stack2.Push(6);

  auto stack1_original = stack1;
  auto stack2_original = stack2;

  stack1.Swap(stack2);

  ASSERT_EQ(stack1, stack2_original);
  ASSERT_EQ(stack2, stack1_original);
}

TEST(ListStack_test, SwapWithDifferentSizes) {
  ListStack<int> stack1, stack2;

  stack1.Push(1);
  stack1.Push(2);

  stack2.Push(3);
  stack2.Push(4);
  stack2.Push(5);

  EXPECT_THROW(stack1.Swap(stack2), std::invalid_argument);
}
