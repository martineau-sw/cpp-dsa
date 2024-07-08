#ifndef _NODE_H_
#define _NODE_H_

#include <memory>

namespace martineausw {
namespace dsa {

template <class T>
class Node {
  public:
    Node(T, std::unique_ptr<Node<T>> = nullptr); 
    ~Node() = default;
    const T value;
    std::unique_ptr<Node<T>> next;
};

template <class T>
Node<T>::Node(T value, std::unique_ptr<Node<T>> next) 
  : value { value }, next { std::move(next) } {
}

} // namespace dsa
} // namespace martineausw

#endif