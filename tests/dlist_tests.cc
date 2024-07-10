#include "DLinkedList.hpp"

#include <iostream>
#include <memory>

#include <gtest/gtest.h>

TEST(DLinkedListTest, GetHeadEmpty) {
  martineausw::dsa::DLinkedList<int> list_empty {};
  ASSERT_FALSE(list_empty.get_head());
}

TEST(DLinkedListTest, GetHeadOne) {
  martineausw::dsa::DLinkedList<int> list { 1 };
  ASSERT_TRUE(list.get_head());
  EXPECT_EQ(list.get_length(), 1);
  ASSERT_EQ(list.get_head()->value, 1);
}

TEST(DLinkedListTest, GetHeadPrepend) {
  martineausw::dsa::DLinkedList<int> list {};
  ASSERT_FALSE(list.get_head());
  EXPECT_EQ(list.get_length(), 0);
  list.prepend(0);
  ASSERT_TRUE(list.get_head()); 
  EXPECT_EQ(list.get_length(), 1);
  ASSERT_EQ(list.get_head()->value, 0);
  list.prepend(1);
  ASSERT_TRUE(list.get_head());
  EXPECT_EQ(list.get_length(), 2);
  ASSERT_EQ(list.get_head()->value, 1);
}

TEST(DLinkedListTest, GetHeadAppend) {
  martineausw::dsa::DLinkedList<int> list {};
  ASSERT_FALSE(list.get_head());
  EXPECT_EQ(list.get_length(), 0);
  list.append(0);
  ASSERT_TRUE(list.get_head());
  EXPECT_EQ(list.get_length(), 1);
  ASSERT_EQ(list.get_head()->value, 0);
  list.append(1);
  EXPECT_EQ(list.get_length(), 2);
  ASSERT_TRUE(list.get_head());
  EXPECT_EQ(list.get_head()->value, 0);
}

TEST(DLinkedListTest, GetHeadAfterFirstRemove) {
  martineausw::dsa::DLinkedList<int> list {};

  ASSERT_FALSE(list.get_head());
  EXPECT_EQ(list.get_length(), 0);
  list.append(0); 
  EXPECT_EQ(list.get_length(), 1);
  list.append(1);
  EXPECT_EQ(list.get_length(), 2);
  ASSERT_TRUE(list.get_head());
  EXPECT_EQ(list.get_head()->value, 0);
  list.remove_first();
  EXPECT_EQ(list.get_length(), 1);
  ASSERT_TRUE(list.get_head());
  EXPECT_EQ(list.get_head()->value, 1);
  list.remove_first();
  EXPECT_EQ(list.get_length(), 0);
  EXPECT_FALSE(list.get_head());
}

TEST(DLinkedListTest, GetHeadAfterLastRemove) {
  martineausw::dsa::DLinkedList<int> list {};

  ASSERT_FALSE(list.get_head());
  EXPECT_EQ(list.get_length(), 0);
  list.append(0);
  EXPECT_EQ(list.get_length(), 1);
  list.append(1);
  EXPECT_EQ(list.get_length(), 2);
  ASSERT_TRUE(list.get_head());
  EXPECT_EQ(list.get_head()->value, 0);
  list.remove_last();
  EXPECT_EQ(list.get_length(), 1);
  ASSERT_TRUE(list.get_head());
  EXPECT_EQ(list.get_head()->value, 0);
  list.remove_last();
  EXPECT_EQ(list.get_length(), 0);
  ASSERT_FALSE(list.get_head());
}

TEST(DLinkedListTest, GetTailEmpty) {
  martineausw::dsa::DLinkedList<int> list_empty {};
  ASSERT_FALSE(list_empty.get_tail());
}

TEST(DLinkedListTest, GetTailOne) {
  martineausw::dsa::DLinkedList<int> list { 1 };
  ASSERT_TRUE(list.get_tail());
  EXPECT_EQ(list.get_length(), 1);
  ASSERT_EQ(list.get_tail()->value, 1);
}

TEST(DLinkedListTest, GetTailPrepend) {
  martineausw::dsa::DLinkedList<int> list {};
  ASSERT_FALSE(list.get_tail());
  EXPECT_EQ(list.get_length(), 0);
  list.prepend(0);
  ASSERT_TRUE(list.get_tail()); 
  EXPECT_EQ(list.get_length(), 1);
  ASSERT_EQ(list.get_tail()->value, 0);
  list.prepend(1);
  ASSERT_TRUE(list.get_tail());
  EXPECT_EQ(list.get_length(), 2);
  ASSERT_EQ(list.get_tail()->value, 0);
}

TEST(DLinkedListTest, GetTailAppend) {
  martineausw::dsa::DLinkedList<int> list {};
  ASSERT_FALSE(list.get_tail());
  EXPECT_EQ(list.get_length(), 0);
  list.append(0);
  ASSERT_TRUE(list.get_tail());
  EXPECT_EQ(list.get_length(), 1);
  ASSERT_EQ(list.get_tail()->value, 0);
  list.append(1);
  ASSERT_TRUE(list.get_tail());
  EXPECT_EQ(list.get_length(), 2);
  EXPECT_EQ(list.get_tail()->value, 1);
}

TEST(DLinkedListTest, GetTailAfterFirstRemove) {
  martineausw::dsa::DLinkedList<int> list {};

  ASSERT_FALSE(list.get_tail());
  EXPECT_EQ(list.get_length(), 0);
  list.append(0); 
  EXPECT_EQ(list.get_length(), 1);
  list.append(1);
  ASSERT_TRUE(list.get_tail());
  EXPECT_EQ(list.get_length(), 2);
  EXPECT_EQ(list.get_tail()->value, 1);
  list.remove_first();
  ASSERT_TRUE(list.get_tail());
  EXPECT_EQ(list.get_length(), 1);
  EXPECT_EQ(list.get_tail()->value, 1);
  list.remove_first();
  EXPECT_FALSE(list.get_tail());
  EXPECT_EQ(list.get_length(), 0);
}

TEST(DLinkedListTest, GetTailAfterLastRemove) {
  martineausw::dsa::DLinkedList<int> list {};

  ASSERT_FALSE(list.get_tail());
  EXPECT_EQ(list.get_length(), 0);
  list.append(0);
  EXPECT_EQ(list.get_length(), 1);
  list.append(1);
  ASSERT_TRUE(list.get_tail());
  EXPECT_EQ(list.get_length(), 2);
  EXPECT_EQ(list.get_tail()->value, 1);
  list.remove_last();
  ASSERT_TRUE(list.get_tail());
  EXPECT_EQ(list.get_length(), 1);
  EXPECT_EQ(list.get_tail()->value, 0);
  list.remove_last();
  ASSERT_FALSE(list.get_tail());
  EXPECT_EQ(list.get_length(), 0);
}

TEST(DLinkedListTest, ArbitraryInsert) {
  martineausw::dsa::DLinkedList<int> list {};

  ASSERT_FALSE(list.get_head());
  ASSERT_FALSE(list.get_tail());
  EXPECT_EQ(list.get_length(), 0);
  list.insert(0, 0);
  EXPECT_EQ(list.get_length(), 1);
  list.insert(1, 2);
  EXPECT_EQ(list.get_length(), 2);
  list.insert(2, 4);
  EXPECT_EQ(list.get_length(), 3);

  list.insert(1, 1);
  EXPECT_EQ(list.get_length(), 4);
  list.insert(3, 3);
  EXPECT_EQ(list.get_length(), 5);
  list.insert(5, 5);
  EXPECT_EQ(list.get_length(), 6);
  
  int i { 0 };
  auto iterator { list.get_head().get() };
  while(iterator) {
    EXPECT_EQ(iterator->value, i++);
    iterator = iterator->next.get();
  }

  while(iterator) {
    EXPECT_EQ(iterator->value, i--);
    iterator = iterator->prev;
  }
}

TEST(DLinkedListTest, ArbitraryRemove) {
  martineausw::dsa::DLinkedList<int> list {};

  ASSERT_FALSE(list.get_head());
  ASSERT_FALSE(list.get_tail());
  list.insert(0, 0);
  list.insert(1, 1);
  list.insert(2, 2);
  list.insert(3, 3);
  list.insert(4, 4);
  list.insert(5, 5);
  
  // [0, 1, 2, 3, 4, 5]
  EXPECT_EQ(list.get_length(), 6);
  int removed { list.remove(3) };
  // [0, 1, 2, 4, 5]
  EXPECT_EQ(removed, 3);
  EXPECT_EQ(list.get_length(), 5);
  EXPECT_EQ(list.at(3), 4);
  removed = list.remove(0);
  // [1, 2, 4, 5]
  EXPECT_EQ(removed, 0);
  EXPECT_EQ(list.get_length(), 4);
  EXPECT_EQ(list.get_head()->value, 1);
  removed = list.remove(3);
  // [1, 2, 4]
  EXPECT_EQ(removed, 5);
  EXPECT_EQ(list.get_length(), 3);
  EXPECT_EQ(list.get_tail()->value, 4);

  auto iterator { list.get_head().get() };
  EXPECT_EQ(iterator->value, 1);
  iterator = iterator->next.get();
  EXPECT_EQ(iterator->value, 2);
  iterator = iterator->next.get();
  EXPECT_EQ(iterator->value, 4);
  iterator = iterator->prev;
  EXPECT_EQ(iterator->value, 2);
  iterator = iterator->prev;
  EXPECT_EQ(iterator->value, 1);
}
/*
TEST(DLinkedListTest, InsertIndexAtZero) {

  martineausw::dsa::DLinkedList<int> list {};

  const int LENGTH { 1000 };

  for (int i {0}; i < LENGTH; ++i) 
    list.insert(0, i);
    
  for (int i {0}; i < list.get_length(); ++i) 
    EXPECT_EQ(list.at(list.get_length() - 1 - i), i);

}

TEST(DLinkedListTest, InsertIndexAtLength) {

  martineausw::dsa::DLinkedList<int> list {};

  for (int i {0}; i < 1000; ++i) 
    list.insert(list.get_length(), i);
  
  for (int i {0}; i < list.get_length(); ++i)
    EXPECT_EQ(list.at(i), i);
}
*/
