#include "LinkedList.hpp"

#include <iostream>
#include <memory>

#include <gtest/gtest.h>

TEST(LinkedListTest, AppendMany) {
  martineausw::dsa::LinkedList<int> list {};

  const int LENGTH { 1000 };

  for (int i { 0 }; i < LENGTH; ++i ) 
    list.append(i);

  for (int i { 0 }; i < LENGTH; ++i ) 
    EXPECT_EQ(list.at(i), i);
  
}

TEST(InsertTest, InsertIndexAtZero) {

  martineausw::dsa::LinkedList<int> list {};

  const int LENGTH { 1000 };

  for (int i {0}; i < LENGTH; ++i) 
    list.insert(0, i);
    
  for (int i {0}; i < list.get_length(); ++i) 
    EXPECT_EQ(list.at(list.get_length() - 1 - i), i);

}

TEST(LinkedListTest, InsertIndexAtLength) {

  martineausw::dsa::LinkedList<int> list {};

  for (int i {0}; i < 1000; ++i) 
    list.insert(list.get_length(), i);
  
  for (int i {0}; i < list.get_length(); ++i)
    EXPECT_EQ(list.at(i), i);
}
