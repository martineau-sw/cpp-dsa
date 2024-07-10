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
    T pop();
    const T &peak() const;
    int get_length() const;
  private:
    std::unique_ptr<T> top;
    int length;
    class Node {
      public: 
        T value;
        std::unique_ptr<T> next; 
    }; // class Node
}; // class Stack



} // dsa 
} // martineausw

#endif