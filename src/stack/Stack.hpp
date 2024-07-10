#ifndef DSA_STACK_H_
#define DSA_STACK_H_

#include <iostream>
#include <memory>

namespace martineausw {
namespace dsa {

template <class T>
class Stack {
  public:
    Stack();
    ~Stack() = default;

    void push(T);
    std::unique_ptr<T> pop();
    const T* peak() const;
    int get_length() const;
  private:
    int length;
    class Node {
      public: 
        Node(T);
        ~Node() = default;
        T value;
        std::unique_ptr<Stack<T>::Node> next; 
    }; // class Node
    std::unique_ptr<Stack<T>::Node> top;
}; // class Stack

template <class T>
Stack<T>::Stack() 
  : top { nullptr }, length { 0 } {
}

template <class T>
void Stack<T>::push(T value) {
  length++;
  if (length == 0) {
    top = std::make_unique<Stack<T>::Node>(value);
    return;
  }

  auto new_node { std::make_unique<Stack<T>::Node>(value) };
  new_node->next = std::move(top);
  top = std::move(new_node);
}

template <class T>
std::unique_ptr<T> Stack<T>::pop() {
  if (length == 0) {
    return nullptr;
  }

  length--;

  auto value { std::make_unique<T>(top->value) };
  top = std::move(top->next);
  return std::move(value);
}

template <class T>
const T* Stack<T>::peak() const {
  return top ? &(top->value) : nullptr;
}

template <class T>
int Stack<T>::get_length() const {
  return length;
}

template <class T>
Stack<T>::Node::Node(T value) 
  : value { value }, next { nullptr } {
}

} // dsa 
} // martineausw

#endif