#include "Queue.hpp"

#include <gtest/gtest.h>

TEST(QueueTests, PeakEmpty) {
  martineausw::dsa::Queue<int> queue {};
  ASSERT_EQ(queue.peak_front(), nullptr);
}

TEST(QueueTests, PushOne) {
  martineausw::dsa::Queue<int> queue {};
  EXPECT_EQ(queue.get_length(), 0);
  queue.enqueue(0);
  EXPECT_EQ(*queue.peak_front(), 0);
  EXPECT_EQ(*queue.peak_back(), 0);
  EXPECT_EQ(queue.get_length(), 1);
}

TEST(QueueTests, PopEmpty) {
  martineausw::dsa::Queue<int> queue {};
  EXPECT_EQ(queue.dequeue(), nullptr);
  EXPECT_EQ(queue.get_length(), 0);
}

TEST(QueueTests, PopOne) {
  martineausw::dsa::Queue<int> queue {};
  EXPECT_EQ(queue.get_length(), 0);
  queue.enqueue(0);
  EXPECT_EQ(*queue.peak_front(), 0);
  EXPECT_EQ(*queue.peak_back(), 0);
  EXPECT_EQ(queue.get_length(), 1);
  auto popped = queue.dequeue();
  EXPECT_EQ(*popped, 0);
  EXPECT_EQ(queue.get_length(), 0);
  EXPECT_EQ(queue.peak_front(), nullptr);
  EXPECT_EQ(queue.peak_back(), nullptr);
}