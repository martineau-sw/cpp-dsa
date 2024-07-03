#ifndef _LINKEDLIST_H_ 
#define _LINKEDLIST_H_

#include <memory>

#include "Node.h"

namespace martineausw {
namespace dsa {

template <class T>
class LinkedList {
  public: 
    LinkedList();
    LinkedList(T value);
    ~LinkedList() = default;

    T at(int);
    void prepend(T);
    void append(T);
    bool contains(T) const;
    void insert(T, int);

    std::shared_ptr<Node<T>> head;
    std::shared_ptr<Node<T>> tail;
    int length;
};

template <class T>
LinkedList<T>::LinkedList() 
  : head { nullptr }, tail { nullptr }, length { 0 } {
}

template <class T>
LinkedList<T>::LinkedList(T value) 
  : head { nullptr }, tail { nullptr }, length { 1 } {
  auto new_node { std::make_shared<Node<T>>(value) };
  this->head = new_node;
  this->tail = new_node;
}

template <class T>
T LinkedList<T>::at(int index) {
  if (index < 0 || index >= length) {
    std::cerr << "Invalid `at` index: " << index << '\n';
    std::cerr << "\tvalid range: [0, " << length << ")" << std::endl;
  }
  auto iterator { this->head };  
  for ( int i {}; i < index; ++i ) 
    iterator = iterator->next; 
  return iterator->value;
}

template <class T>
void LinkedList<T>::prepend(T value) {
  auto new_node { std::make_shared<Node<T>>(value) };
  this->length++;

  if (length == 0) {
    this->head = new_node;
    this->tail = new_node;
    return;
  }
  
  new_node->next = this->head;
  this->head = new_node;
}

template <class T>
void LinkedList<T>::append(T value) {
  auto new_node { std::make_shared<Node<T>>(value) };
  this->length++;

  if (length == 0) {
    this->head = new_node;
    this->tail = new_node;
    return;
  }

  this->tail->next = new_node;
  this->tail = new_node;
}

template <class T>
bool LinkedList<T>::contains(T value) const {
  auto iterator { this->head };

  if (iterator == this->head) return true;
  if (iterator == this->tail) return true;

  while (iterator != this->tail ) {
    if (iterator->value == value) break;
    iterator = iterator->next;
  }

  return true;
}

template <class T>
void LinkedList<T>::insert(T value, int index) {

  if (index < 0 || index > length) {
    std::cerr << "Invalid insertion index for linked list: " << index << '\n';
    std::cerr << "\tvalid range: [0, " << length << "]" << std::endl;
    return;
  }

  if (index == 0) {
    prepend(value);
    return;
  }

  if (index == length) { 
    append(value);
    return;
  }

  auto iterator { this->head };

  for (int i {}; i < index - 1; ++i) 
    iterator = iterator->next;
   
  auto new_node { std::make_shared<Node<T>>(value) };
  
  new_node->next = iterator->next->next;
  iterator->next = new_node;

  this->length++;
}

} // namespace dsa
} // namespace martineausw

#endif