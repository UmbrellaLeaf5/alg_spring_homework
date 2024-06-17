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
#include "min_singly_list_stack.hpp"

using namespace std;

TEST(MinSinglyListStack_test, Simple) {
  MinSinglyListStack<int> stack;
  // в стандартной реализации у стека pop() имеет void
  stack.Push(1);              // MinSinglyListStack [1]
  ASSERT_EQ(stack.Top(), 1);  // MinSinglyListStack [1]
  stack.Pop();                // MinSinglyListStack []
  stack.Push(1);              // MinSinglyListStack [1]
  stack.Push(2);              // MinSinglyListStack [1, 2]
  ASSERT_EQ(stack.Top(), 2);  // MinSinglyListStack [1, 2]
  stack.Pop();                // MinSinglyListStack [1]
  ASSERT_EQ(stack.Top(), 1);  // MinSinglyListStack [1]
  stack.Pop();                // MinSinglyListStack []
  stack.Push(1);              // MinSinglyListStack [1]
  stack.Push(2);              // MinSinglyListStack [1, 2]
  ASSERT_EQ(stack.Top(), 2);  // MinSinglyListStack [1, 2]
  stack.Pop();                // MinSinglyListStack [1]
  stack.Push(3);              // MinSinglyListStack [1, 3]
  ASSERT_EQ(stack.Top(), 3);  // MinSinglyListStack [1, 3]
  stack.Pop();                // MinSinglyListStack [1]
  ASSERT_EQ(stack.Top(), 1);  // MinSinglyListStack [1]
  stack.Pop();
}

TEST(MinSinglyListStack_test, Size_test) {
  auto stack = MinSinglyListStack<float>();
  ASSERT_EQ(stack.Size(), 0);
}

TEST(MinSinglyListStack_test, PushTop_test) {
  auto stack = MinSinglyListStack<int>();
  stack.Push(6);
  ASSERT_EQ(stack.Top(), 6);
}

TEST(MinSinglyListStack_test, PushTopPop_test_1) {
  auto stack = MinSinglyListStack<string>();
  stack.Push();
  stack.Push();
  stack.Pop();
  stack.Pop();
  EXPECT_THROW(stack.Top(), logic_error);
}

TEST(MinSinglyListStack_test, PushTopPop_test_2) {
  auto stack = MinSinglyListStack<string>();
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

TEST(MinSinglyListStack_test, PushSize_test_1) {
  auto stack = MinSinglyListStack<int>();
  stack.Push();
  stack.Push();
  ASSERT_EQ(stack.Size(), 2);
}

TEST(MinSinglyListStack_test, PushSize_test_2) {
  auto stack = MinSinglyListStack<double>();
  stack.Push();
  stack.Push();
  stack.Push();
  stack.Push();
  stack.Push();
  ASSERT_EQ(stack.Size(), 5);
}

TEST(MinSinglyListStack_test, PushPop_test_1) {
  auto stack = MinSinglyListStack<double>();
  stack.Push();
  stack.Push();
  stack.Push();
  stack.Pop();
  stack.Pop();
  ASSERT_EQ(stack.Size(), 1);
}

TEST(MinSinglyListStack_test, PushPop_test_2) {
  auto stack = MinSinglyListStack<double>();
  stack.Push();
  stack.Push();
  stack.Pop();
  stack.Pop();
  EXPECT_THROW(stack.Pop(), logic_error);
}

TEST(MinSinglyListStack_test, PushRange_initializer_list_SizePopTop_test) {
  auto stack = MinSinglyListStack<int>();
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

TEST(MinSinglyListStack_test, PushRange_vector_SizePopTop_test_1) {
  auto stack = MinSinglyListStack<int>();
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

TEST(MinSinglyListStack_test, PushRange_vector_SizePopTop_test_2) {
  auto stack = MinSinglyListStack<int>();
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

TEST(MinSinglyListStack_test, PushRange_std_stack_SizePopTop_test) {
  auto stack = MinSinglyListStack<int>();
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

TEST(MinSinglyListStack_test, PushRange_Stack_SizePopTop_test) {
  auto stack = MinSinglyListStack<int>();
  MinSinglyListStack<int> my_stack;
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

TEST(MinSinglyListStack_test, GetMin_PushPop_test_1) {
  MinSinglyListStack<int> stack;
  // в стандартной реализации у стека pop() имеет void
  stack.Push(1);                 // MinSinglyListStack [1]
  ASSERT_EQ(stack.GetMin(), 1);  // MinSinglyListStack [1]
  stack.Pop();                   // MinSinglyListStack []
  stack.Push(1);                 // MinSinglyListStack [1]
  stack.Push(2);                 // MinSinglyListStack [1, 2]
  ASSERT_EQ(stack.GetMin(), 1);  // MinSinglyListStack [1, 2]
  stack.Pop();                   // MinSinglyListStack [1]
  ASSERT_EQ(stack.GetMin(), 1);  // MinSinglyListStack [1]
  stack.Pop();                   // MinSinglyListStack []
  stack.Push(1);                 // MinSinglyListStack [1]
  stack.Push(2);                 // MinSinglyListStack [1, 2]
  ASSERT_EQ(stack.GetMin(), 1);  // MinSinglyListStack [1, 2]
  stack.Pop();                   // MinSinglyListStack [1]
  stack.Push(3);                 // MinSinglyListStack [1, 3]
  ASSERT_EQ(stack.GetMin(), 1);  // MinSinglyListStack [1, 3]
  stack.Pop();                   // MinSinglyListStack [1]
  ASSERT_EQ(stack.GetMin(), 1);  // MinSinglyListStack [1]
  stack.Pop();
}

TEST(MinSinglyListStack_test, GetMin_PushPop_test_2) {
  MinSinglyListStack<double> stack;
  stack.Push(0.1);
  ASSERT_EQ(stack.GetMin(), 0.1);
  stack.Pop();
  stack.Push(0.11);
  stack.Push(0.12);
  ASSERT_EQ(stack.GetMin(), 0.11);
  stack.Pop();
  ASSERT_EQ(stack.GetMin(), 0.11);
  stack.Pop();
  stack.Push(0);
  stack.Push(0.123123);
  ASSERT_EQ(stack.GetMin(), 0);
  stack.Pop();
  stack.Push(-3123);
  ASSERT_EQ(stack.GetMin(), -3123);
  stack.Pop();
  ASSERT_EQ(stack.GetMin(), 0);
  stack.Pop();
}

TEST(MinSinglyListStack_test, SwapWithDifferentSizes) {
  MinSinglyListStack<int> stack1, stack2;

  stack1.Push(1);
  stack1.Push(2);

  stack2.Push(3);
  stack2.Push(4);
  stack2.Push(5);

  EXPECT_THROW(stack1.Swap(stack2), std::invalid_argument);
}
