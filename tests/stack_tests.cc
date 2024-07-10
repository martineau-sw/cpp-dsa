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