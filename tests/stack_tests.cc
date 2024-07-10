#include "Stack.hpp"

#include <gtest/gtest.h>

TEST(StackTests, PeakEmpty) {
  martineausw::dsa::Stack<int> stack {};
  ASSERT_EQ(stack.peak(), nullptr);
}