#include "LinkedList.hpp"

#include <iostream>
#include <memory>

#include <gtest/gtest.h>

TEST(LinkedListTest, GetHeadEmpty) {
  martineausw::dsa::LinkedList<int> list_empty {};
  ASSERT_FALSE(list_empty.head());
}

TEST(LinkedListTest, GetHeadOne) {
  martineausw::dsa::LinkedList<int> list { 1 };
  ASSERT_TRUE(list.head());
  EXPECT_EQ(list.length(), 1);
  ASSERT_EQ(list.head()->value(), 1);
}

TEST(LinkedListTest, GetHeadPrepend) {
  martineausw::dsa::LinkedList<int> list {};
  ASSERT_FALSE(list.head());
  EXPECT_EQ(list.length(), 0);
  list.prepend(0);
  ASSERT_TRUE(list.head()); 
  EXPECT_EQ(list.length(), 1);
  ASSERT_EQ(list.head()->value(), 0);
  list.prepend(1);
  ASSERT_TRUE(list.head());
  EXPECT_EQ(list.length(), 2);
  ASSERT_EQ(list.head()->value(), 1);
}

TEST(LinkedListTest, GetHeadAppend) {
  martineausw::dsa::LinkedList<int> list {};
  ASSERT_FALSE(list.head());
  EXPECT_EQ(list.length(), 0);
  list + 0;
  ASSERT_TRUE(list.head());
  EXPECT_EQ(list.length(), 1);
  ASSERT_EQ(list.head()->value(), 0);
  list + 1;
  EXPECT_EQ(list.length(), 2);
  ASSERT_TRUE(list.head());
  EXPECT_EQ(list.head()->value(), 0);
}

TEST(LinkedListTest, GetHeadAfterFirstRemove) {
  martineausw::dsa::LinkedList<int> list { 0, 1 };

  EXPECT_EQ(list.length(), 2);
  ASSERT_TRUE(list.head());
  EXPECT_EQ(list.head()->value(), 0);
  list.remove_first();
  EXPECT_EQ(list.length(), 1);
  ASSERT_TRUE(list.head());
  EXPECT_EQ(list.head()->value(), 1);
  list.remove_first();
  EXPECT_EQ(list.length(), 0);
  EXPECT_FALSE(list.head());
}

TEST(LinkedListTest, GetHeadAfterLastRemove) {
  martineausw::dsa::LinkedList<int> list { 0, 1 };

  EXPECT_EQ(list.length(), 2);
  ASSERT_TRUE(list.head());
  EXPECT_EQ(list.head()->value(), 0);
  list.remove_last();
  EXPECT_EQ(list.length(), 1);
  ASSERT_TRUE(list.head());
  EXPECT_EQ(list.head()->value(), 0);
  list.remove_last();
  EXPECT_EQ(list.length(), 0);
  ASSERT_FALSE(list.head());
}

TEST(LinkedListTest, GetTailEmpty) {
  martineausw::dsa::LinkedList<int> list_empty {};
  ASSERT_FALSE(list_empty.tail());
}

TEST(LinkedListTest, GetTailOne) {
  martineausw::dsa::LinkedList<int> list { 1 };
  ASSERT_TRUE(list.tail());
  EXPECT_EQ(list.length(), 1);
  ASSERT_EQ(list.tail()->value(), 1);
}

TEST(LinkedListTest, GetTailPrepend) {
  martineausw::dsa::LinkedList<int> list {};
  ASSERT_FALSE(list.tail());
  EXPECT_EQ(list.length(), 0);
  list.prepend(0);
  ASSERT_TRUE(list.tail()); 
  EXPECT_EQ(list.length(), 1);
  ASSERT_EQ(list.tail()->value(), 0);
  list.prepend(1);
  ASSERT_TRUE(list.tail());
  EXPECT_EQ(list.length(), 2);
  ASSERT_EQ(list.tail()->value(), 0);
}

TEST(LinkedListTest, GetTailAppend) {
  martineausw::dsa::LinkedList<int> list {};
  ASSERT_FALSE(list.tail());
  EXPECT_EQ(list.length(), 0);
  list.append(0);
  ASSERT_TRUE(list.tail());
  EXPECT_EQ(list.length(), 1);
  ASSERT_EQ(list.tail()->value(), 0);
  list.append(1);
  ASSERT_TRUE(list.tail());
  EXPECT_EQ(list.length(), 2);
  EXPECT_EQ(list.tail()->value(), 1);
}

TEST(LinkedListTest, GetTailAfterFirstRemove) {
  martineausw::dsa::LinkedList<int> list { 0, 1 };

  ASSERT_TRUE(list.tail());
  EXPECT_EQ(list.length(), 2);
  EXPECT_EQ(list.tail()->value(), 1);
  list.remove_first();
  ASSERT_TRUE(list.tail());
  EXPECT_EQ(list.length(), 1);
  EXPECT_EQ(list.tail()->value(), 1);
  list.remove_first();
  EXPECT_FALSE(list.tail());
  EXPECT_EQ(list.length(), 0);
}

TEST(LinkedListTest, GetTailAfterLastRemove) {
  martineausw::dsa::LinkedList<int> list { 0, 1 };

  ASSERT_TRUE(list.tail());
  EXPECT_EQ(list.length(), 2);
  EXPECT_EQ(list.tail()->value(), 1);
  list.remove_last();
  ASSERT_TRUE(list.tail());
  EXPECT_EQ(list.length(), 1);
  EXPECT_EQ(list.tail()->value(), 0);
  list.remove_last();
  ASSERT_FALSE(list.tail());
  EXPECT_EQ(list.length(), 0);
}

TEST(LinkedListTest, ArbitraryInsert) {
  martineausw::dsa::LinkedList<int> list {};

  ASSERT_FALSE(list.head());
  ASSERT_FALSE(list.tail());
  EXPECT_EQ(list.length(), 0);
  list.insert(0, 0);
  EXPECT_EQ(list.length(), 1);
  list.insert(1, 2);
  EXPECT_EQ(list.length(), 2);
  list.insert(2, 4);
  EXPECT_EQ(list.length(), 3);

  list.insert(1, 1);
  EXPECT_EQ(list.length(), 4);
  list.insert(3, 3);
  EXPECT_EQ(list.length(), 5);
  list.insert(5, 5);
  EXPECT_EQ(list.length(), 6);
  
  int i { 0 };
  auto iterator { list.head() };
  while(iterator) {
    EXPECT_EQ(iterator->value(), i++);
    iterator = iterator->next();
  }

}

TEST(LinkedListTest, ArbitraryRemove) {
  martineausw::dsa::LinkedList<int> list { 0, 1, 2, 3, 4, 5 };

  // [0, 1, 2, 3, 4, 5]
  EXPECT_EQ(list.length(), 6);
  int removed { list.remove(3) };
  // [0, 1, 2, 4, 5]
  EXPECT_EQ(removed, 3);
  EXPECT_EQ(list.length(), 5);
  EXPECT_EQ(list.at(3), 4);
  removed = list.remove(0);
  // [1, 2, 4, 5]
  EXPECT_EQ(removed, 0);
  EXPECT_EQ(list.length(), 4);
  EXPECT_EQ(list.head()->value(), 1);
  removed = list.remove(3);
  // [1, 2, 4]
  EXPECT_EQ(removed, 5);
  EXPECT_EQ(list.length(), 3);
  EXPECT_EQ(list.tail()->value(), 4);

  auto iterator { list.head() };
  EXPECT_EQ(iterator->value(), 1);
  iterator = iterator->next();
  EXPECT_EQ(iterator->value(), 2);
  iterator = iterator->next();
  EXPECT_EQ(iterator->value(), 4);

}
