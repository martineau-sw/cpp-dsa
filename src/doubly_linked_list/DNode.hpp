#ifndef DSA_DOUBLY_LINKED_LIST_DNODE_H_
#define DSA_DOUBLY_LINKED_LIST_DNODE_H_

#include <memory>

namespace martineausw {
namespace dsa {

template <class T>
class DNode {

  public:
    DNode(T value);
    ~DNode() = default;
    T value;
    DNode<T>* prev;
    std::unique_ptr<DNode<T>> next;
};

template <class T>
DNode<T>::DNode(T value) 
  : value { value }, prev { nullptr }, next { nullptr } {
}

} // namespace dsa
} // namespace martineausw

#endif // DSA_DOUBLY_LINKED_LIST_DNODE_H_