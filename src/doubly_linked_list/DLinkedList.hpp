#ifndef DS_DOUBLY_LINKED_LIST_DLINKED_LIST_H_
#define DS_DOUBLY_LINKED_LIST_DLINKED_LIST_H_

#include <iostream>
#include <memory>

#include "DNode.hpp"

namespace martineausw {
namespace dsa {

template <class T>
class DLinkedList {
  public:
    DLinkedList();
    DLinkedList(T);
    ~DLinkedList() = default;

    const T& at(int) const;
    bool contains(T) const;
    void prepend(T);
    void append(T);
    void insert(int, T);
    T remove_first();
    T remove_last();
    T remove(int);
    
    const std::unique_ptr<DNode<T>> &get_head() const;
    const DNode<T>* get_tail() const;
    int get_length() const;
  private:
    std::unique_ptr<DNode<T>> head;
    DNode<T>* tail;
    int length;
};

template <class T>
DLinkedList<T>::DLinkedList() 
  : head { nullptr }, tail { nullptr }, length { 0 } {
}

template <class T>
DLinkedList<T>::DLinkedList(T value) 
  : head { nullptr }, tail { nullptr }, length { 1 } {
}

template <class T>
const std::unique_ptr<DNode<T>> &DLinkedList<T>::get_head() const {
  return head;
}

template <class T>
const DNode<T>* DLinkedList<T>::get_tail() const {
  return tail;
}

template <class T>
int DLinkedList<T>::get_length() const {
  return length;
}

template <class T>
const T &DLinkedList<T>::at(int index) const {
  if (index < 0 || index >= length) {
    std::cerr << "Index out of range\n";
  }

  if (index < length / 2) {
    auto iterator = head.get();
    for (int i { 0 }; i < index; ++i) 
      iterator = iterator->next.get();
    return iterator->value;
  }

  auto iterator = tail;
  for (int i { length }; i >= index; --i) 
    iterator = iterator->prev;
  return iterator->value; 
}

template <class T>
void DLinkedList<T>::prepend(T value) {
  length++;

  if (!head) {
    head = std::make_unique<DNode<T>>(value);
    tail = head.get();
  }

  auto new_node { std::make_unique<DNode<T>>(value) };
  new_node->next = std::move(head);
  head = std::move(new_node);
  new_node->next->prev = head.get();
}

template <class T>
void DLinkedList<T>::append(T value) {

  if (!head) {
    prepend(value);
    return;
  }

  length++;

  tail->next = std::make_unique<DNode<T>>(value);
  tail->next->prev = tail;
  tail = tail->next.get();
}

template <class T>
void DLinkedList<T>::insert(int index, T value) {
  if (index < 0 || index > length) {
    std::cerr << "Index out of range\n";
  }

  if (index == 0) {
    prepend(value);
    return;
  }

  if (index == length) {
    append(value);
    return;
  }

  length++;
  auto iterator { head.get() };
  for (int i { 0 }; i < index - 1; ++i) 
    iterator = iterator->next.get(); 
  
  auto next = std::move(iterator->next);
  iterator->next = std::make_unique<DNode<T>>(value);
  iterator->next->prev = iterator;
  iterator->next->next = std::move(next);
  iterator->next->next->prev = iterator->next.get();
}


} // namespace dsa
} // namespace martineausw

#endif // DS_DOUBLY_LINKED_LIST_DLINKED_LIST_H_