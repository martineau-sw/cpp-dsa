#ifndef _NODE_H_
#define _NODE_H_

#include <memory>

namespace martineausw {
namespace dsa {

template <class T>
class Node {
  public:
    Node(T value); 
    ~Node() = default;
    const T value;
    std::shared_ptr<Node<T>> next;
};

template <class T>
Node<T>::Node(T value) 
  : value { value }, next { nullptr } {
}

} // namespace dsa
} // namespace martineausw

#endif