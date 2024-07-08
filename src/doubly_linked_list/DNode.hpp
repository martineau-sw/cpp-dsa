#ifndef DSA_DOUBLY_LINKED_LIST_DNODE_H_
#define DSA_DOUBLY_LINKED_LIST_DNODE_H_

#include <memory>

namespace martineausw {
namespace dsa {

template <class T>
class DNode {

  friend class DLinkedList;

  public:
    DNode();
    ~DNode() = default
    const T get_value() const;
    const std::weak_ptr<DNode<T>> get_prev() const;
    const std::weak_ptr<DNode<T>> get_next() const;
  private:
    T value;
    std::shared_ptr<DNode<T>> prev;
    std::shared_ptr<DNode<T>> next;
};

} // namespace dsa
} // namespace martineausw

#endif // DSA_DOUBLY_LINKED_LIST_DNODE_H_