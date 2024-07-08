#include "DLinkedList.hpp"

#include <iostream>
#include <memory>

#include <gtest/gtest.h>

TEST(DLinkedListTest, AppendMany) {
  martineausw::dsa::DLinkedList<int> list {};

  const int LENGTH { 1000 };

  for (int i { 0 }; i < LENGTH; ++i ) 
    list.append(i);

  EXPECT_EQ(list.at(-1), NULL);

  for (int i { 0 }; i < LENGTH; ++i ) 
    EXPECT_EQ(list.at(i), i);
  
  EXPECT_EQ(list.at(LENGTH), NULL);
}

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
