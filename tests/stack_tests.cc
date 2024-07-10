#include "Stack.hpp"

#include <gtest/gtest.h>

TEST(StackTests, PeakEmpty) {
  martineausw::dsa::Stack<int> stack {};
  ASSERT_EQ(stack.peak(), nullptr);
}

TEST(StackTests, PushOne) {
  martineausw::dsa::Stack<int> stack {};
  EXPECT_EQ(stack.get_length(), 0);
  stack.push(0);
  EXPECT_EQ(*stack.peak(), 0);
  EXPECT_EQ(stack.get_length(), 1);
}

TEST(StackTest, PopEmpty) {
  martineausw::dsa::Stack<int> stack {};
  EXPECT_EQ(stack.pop(), nullptr);
  EXPECT_EQ(stack.get_length(), 0);
}

TEST(StackTests, PopOne) {
  martineausw::dsa::Stack<int> stack {};
  EXPECT_EQ(stack.get_length(), 0);
  stack.push(0);
  EXPECT_EQ(*stack.peak(), 0);
  EXPECT_EQ(stack.get_length(), 1);
  auto popped = stack.pop();
  EXPECT_EQ(*popped, 0);
  EXPECT_EQ(stack.get_length(), 0);
  EXPECT_EQ(stack.peak(), nullptr);
}