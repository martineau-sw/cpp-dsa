#ifndef _LINKEDLIST_H_ 
#define _LINKEDLIST_H_

#include <iostream>
#include <memory>
#include <initializer_list>

#include "Node.hpp"

namespace martineausw {
namespace dsa {

template <class T>
class LinkedList {
  public: 
    LinkedList();
    LinkedList(LinkedList<T> &&);
    LinkedList(T value);
    LinkedList(std::initializer_list<T> values);
    ~LinkedList() = default;

    LinkedList<T> &operator=(const LinkedList<T> &);
    LinkedList<T> &operator=(LinkedList<T> &&);
    LinkedList<T> &operator+(T);
    LinkedList<T> &operator+(std::initializer_list<T>);
    LinkedList<T> &operator+(LinkedList<T> &);

    friend LinkedList<T> &operator+(std::initializer_list<T>, LinkedList<T> &);
    friend LinkedList<T> &operator+(T, LinkedList<T> &);
    friend std::ostream &operator<<(std::ostream &, const LinkedList<T> &);
    
    const T& at(int) const;
    bool contains(T) const;

    void prepend(T);
    void append(T);
    void insert(int, T);
    T remove_first();
    T remove_last();
    T remove(int);

    class Node {

    friend class LinkedList;
    
    public:
      Node(T, std::unique_ptr<LinkedList<T>::Node> = nullptr); 
      Node(LinkedList<T>::Node &&);
      ~Node() = default;

      const T &value() const;
      const LinkedList<T>::Node* next() const;
    
    private:
      const T _value;
      std::unique_ptr<LinkedList<T>::Node> _next;
    }; // class Node
    
    const LinkedList<T>::Node* head() const;
    const LinkedList<T>::Node* tail() const;
    int length() const;

  private:
    std::unique_ptr<LinkedList<T>::Node> _head;
    LinkedList<T>::Node* _tail;
    int _length;
}; // class LinkedList<T>

template <class T>
LinkedList<T>::LinkedList() 
  : _head   { nullptr }
  , _tail   { nullptr }
  , _length { 0 } {
}

template <class T>
LinkedList<T>::LinkedList(LinkedList<T> &&rhs) 
  : _head   { std::move(rhs._head) }
  , _tail   { _tail }
  , _length { rhs._length } {
}

template <class T>
LinkedList<T>::LinkedList(T value) 
  : _head   { std::make_unique<LinkedList<T>::Node>(value) }
  , _tail   { _head.get() }
  , _length { 1 } {
}

template <class T>
LinkedList<T>::LinkedList(std::initializer_list<T> values) 
  : _head   { nullptr }
  , _tail   { nullptr }
  , _length { 0 } {
  for ( T value : values ) {
    append(value);
  }
}

template <class T>
const typename LinkedList<T>::Node* LinkedList<T>::head() const {
  return _head.get();
}

template <class T>
const typename LinkedList<T>::Node* LinkedList<T>::tail() const {
  return _tail;
}

template <class T>
int LinkedList<T>::length() const {
  return _length;
}

template <class T>
const T &LinkedList<T>::at(int index) const {
  if (index < 0 || index >= _length) {
    std::cerr << "Invalid `at` index: " << index << '\n';
    std::cerr << "\tvalid range: [0, " << _length << ")" << std::endl;
  }

  auto node = _head.get();
  for ( int i {}; i < index; ++i ) 
    node = node->_next.get();
  return node->_value;
}

template <class T>
void LinkedList<T>::prepend(T value) {
  _length++;
  if (!_head) {
    _head = std::make_unique<LinkedList<T>::Node>(value);
    _tail = _head.get();
    return;
  }
  auto new_node { std::make_unique<LinkedList<T>::Node>(value) };
  new_node->_next = std::move(_head);
  _head = std::move(new_node);
}

template <class T>
void LinkedList<T>::append(T value) {
  if (!_head) {
    prepend(value);
    return;
  }

  _length++;
  _tail->_next = std::make_unique<LinkedList<T>::Node>(value);
  _tail = _tail->_next.get();
}

template <class T> 
void LinkedList<T>::insert(int index, T value) {
  if (index < 0 || index > _length) {
    std::cerr << "Invalid index on insert\n";
  }

  if (index == 0) {
    prepend(value);
    return;
  }

  if (index == _length) {
    append(value);
    return;
  }

  _length++;

  auto iterator { _head.get() };
  for (int i { 0 }; i < index - 1; ++i)
    iterator = iterator->_next.get();

  auto next = std::move(iterator->_next);
  iterator->_next = std::make_unique<LinkedList<T>::Node>(value);
  iterator->_next->_next = std::move(next);
}

template <class T>
T LinkedList<T>::remove_first() {
  if (_length == 1) {
    _length--;
    T value { _head->value() };
    _head = nullptr;
    _tail = nullptr;
    return value;
  }
  T value { _head->value() };
  _head = std::move( _head->_next );
  _length--;
  return value;
}

template <class T>
T LinkedList<T>::remove_last() {
  if (_length == 1) {
    _length--;
    T value { _head->value() };
    _head = nullptr;
    _tail = nullptr;
    return value;
  }

  auto iterator { _head.get() };
  T value { _tail->value() };
  while (iterator->next() != _tail) 
    iterator = iterator->_next.get();
  
  iterator->_next = nullptr;
  _tail = iterator;
  _length--;
  return value;
}

template <class T>
T LinkedList<T>::remove(int index) {
  if (index < 0 || index >= _length) {
    std::cerr << "Index out of range\n";
  }

  if (index == 0) {
    return remove_first();
  }

  if (index == _length - 1) {
    return remove_last();
  }

  int i { 0 };
  auto iterator { _head.get() };
  for (int i { 0 }; i < index - 1; ++i) 
    iterator = iterator->_next.get();
  

  T value = iterator->next()->value();
  iterator->_next = std::move(iterator->_next->_next);
  _length--;
  return value;
}

template <class T>
bool LinkedList<T>::contains(T value) const {
  if(_head && _head->value == value) {
    return true;
  }

  auto iterator = _head.get();
  while (iterator != _tail) {
    iterator = iterator->next.get();
    if (iterator->value == value) 
      return true;
  }
  return false;
}

template <class T>
LinkedList<T> &LinkedList<T>::operator=(const LinkedList<T> &rhs) {
  for (int i { 0 }; i < _length; ++i) 
    remove_first();
  
  auto iterator { _head.get() };
  while(iterator) {
    append(iterator->value);
    iterator = iterator->next.get();
  }
  return *this;
}

template <class T>
LinkedList<T> &LinkedList<T>::operator=(LinkedList<T> &&rhs) {
  _head = std::move(rhs._head);
  _tail = rhs._tail;
  _length = rhs._length;
  return *this;
}

template <class T>
LinkedList<T> &LinkedList<T>::operator+(std::initializer_list<T> values) {
  for (T value : values) {
    append(value);
  }
  return *this;
}

template <class T>
LinkedList<T> &LinkedList<T>::operator+(T value) {
  append(value);
  return *this;
}

template <class T>
LinkedList<T> &LinkedList<T>::operator+(LinkedList<T> &other) {
  auto iterator { other._head.get() };
  while (iterator) {
    append(iterator->value);
    iterator = iterator->next.get();
  }
  return *this;
}

template <class T>
LinkedList<T> &operator+(T value, LinkedList<T> &list) {
  list.prepend(value);
  return list;
}

template <class T>
LinkedList<T> &operator+(std::initializer_list<T> values, LinkedList<T> &list) {
  for (auto value { values.rbegin() }; values != values.rend(); ++value) {
    list.prepend(value);
  }
  return list;
}

template <class T>
std::ostream &operator<<(std::ostream &out, const LinkedList<T> &list) {
  out << "[ ";
  auto iterator { list._head.get() };
  while (iterator) {
    out << iterator->value << " ";
    iterator = iterator->next.get();
  }
  out << "]";
  return out;
}

template <class T>
LinkedList<T>::Node::Node(T value, std::unique_ptr<LinkedList<T>::Node> next) 
  : _value  { value }
  , _next   { next ? std::move(next) : nullptr } {
}

template <class T>
LinkedList<T>::Node::Node(LinkedList<T>::Node &&rhs) 
  : _value  { rhs.value } 
  , _next   { std::move(rhs.next) } {
}

template <class T>
const T &LinkedList<T>::Node::value() const {
  return _value;
}

template <class T>
const typename LinkedList<T>::Node* LinkedList<T>::Node::next() const {
  return _next.get();
}

} // namespace dsa
} // namespace martineausw

#endif