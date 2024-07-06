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

    const T& at(int) const;
    bool contains(T) const;
    void prepend(T);
    void append(T);
    void insert(int, T);
    T remove_first();
    T remove_last();
    T remove(int);
    
    const std::unique_ptr<Node<T>> &get_head() const;
    const Node<T>* get_tail() const;
    int get_length() const;

  private:
    std::unique_ptr<Node<T>> head;
    Node<T>* tail;
    int length;
};

template <class T>
LinkedList<T>::LinkedList() 
  : head { nullptr }, tail { nullptr }, length { 0 } {
}

template <class T>
LinkedList<T>::LinkedList(T value) 
  : head { nullptr }, tail { nullptr }, length { 1 } {
  head = std::make_unique<Node<T>>(value);
  tail = head.get();
}

template <class T>
const std::unique_ptr<Node<T>> &LinkedList<T>::get_head() const {
  return head;
}

template <class T>
const Node<T>* LinkedList<T>::get_tail() const {
  return tail;
}

template <class T>
int LinkedList<T>::get_length() const {
  return length;
}

template <class T>
const T &LinkedList<T>::at(int index) const {
  if (index < 0 || index >= length) {
    std::cerr << "Invalid `at` index: " << index << '\n';
    std::cerr << "\tvalid range: [0, " << length << ")" << std::endl;
  }

  auto node = get_head().get();
  for ( int i {}; i < index; ++i ) 
    node = node->next.get();
  return node->value;
}

template <class T>
void LinkedList<T>::prepend(T value) {
  length++;

  if (!head) {
    head = std::make_unique<Node<T>>(value);
    tail = head.get();
    return;
  }

  auto new_node { std::make_unique<Node<T>>(value) };
  new_node->next = std::move(head);
  head = std::move(new_node);
}

template <class T>
void LinkedList<T>::append(T value) {
  if (!head) {
    prepend(value);
    return;
  }

  length++;

  auto iterator = head.get();
  while(iterator != tail) {
    iterator = iterator->next.get(); 
  }
  iterator->next = std::make_unique<Node<T>>(value);
  tail = iterator->next.get();
}

template <class T> 
void LinkedList<T>::insert(int index, T value) {
  if (index < 0 || index > length) {
    std::cerr << "Invalid index on insert\n";
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

  int i { 0 };
  auto iterator { head.get() };
  while (i < index) {
    iterator = head->next.get(); 
    i++;
  }

  auto next = std::move(iterator->next);
  iterator->next = std::make_unique<Node<T>>(value);
  iterator->next->next = std::move(next);
}

template <class T>
T LinkedList<T>::remove_first() {
  T value { head->value };
  auto next = std::move(head->next);
  head = std::move(next);
  length--;
  return value;
}

template <class T>
T LinkedList<T>::remove_last() {
  auto iterator { head.get() };
  while (iterator->next.get() != tail) {
    iterator = iterator->next.get();
  }
  T value = iterator->next->value;
  iterator->next = nullptr;
  tail = iterator;
  length--;
  return value;
}

template <class T>
T LinkedList<T>::remove(int index) {
  if (index < 0 || index >= length) {
    std::cerr << "Invalid index on remove\n";
  }

  if (index == 0) {
    return remove_first();
  }

  if (index == length - 1) {
    return remove_last();
  }

  int i { 0 };
  auto iterator { head.get() };

  while (i < index - 1) {
    iterator = iterator->next.get();
    i++;
  }

  T value = iterator->next->value;
  iterator->next = std::move(iterator->next->next);
  length--;
  return value;
}

template <class T>
bool LinkedList<T>::contains(T value) const {
  if(head && head->value == value) {
    return true;
  }

  auto iterator = head.get();
  while (iterator != tail) {
    iterator = iterator->next.get();
    if (iterator->value == value) 
      return true;
  }
  return false;
}

} // namespace dsa
} // namespace martineausw

#endif