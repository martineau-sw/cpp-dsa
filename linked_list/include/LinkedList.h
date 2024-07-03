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

    void append(T);
    Node<T> find(T);

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
  : head { nullptr }, tail { nullptr }, length { 0 } {
  auto new_node { std::make_shared<Node<T>>(value) };
  this->head = new_node;
  this->tail = new_node;
}

template <class T>
void LinkedList<T>::append(T value) {
  auto new_node { std::make_shared<Node<T>>(value) };
  if (!this->head) {
    this->head = new_node;
    this->tail = new_node;
  }

  this->tail->next = new_node;
  this->tail = new_node;
}

template <class T>
Node<T> LinkedList<T>::find(T value) {
  auto iterator { this->head };

  while (iterator != this->tail ) {
    if (iterator->value == value) break;
    iterator = iterator->next;
  }

  return *iterator;
}

} // namespace dsa
} // namespace martineausw

#endif