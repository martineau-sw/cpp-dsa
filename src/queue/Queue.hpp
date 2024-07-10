#ifndef DSA_QUEUE_H_
#define DSA_QUEUE_H_

#include <memory>

namespace martineausw {
namespace dsa {

template <class T>
class Queue {
  public:
    Queue();
    ~Queue() = default;

    void enqueue(T);
    std::unique_ptr<T> dequeue();

    const T* peak_front() const;
    const T* peak_back() const;
    int get_length() const;
  private:
    class Node {
      public:
        Node(T);
        ~Node() = default;
        T value;
        std::unique_ptr<Queue<T>::Node> next;
      private:
    }; // class Node

    std::unique_ptr<Queue<T>::Node> front;
    Queue<T>::Node* back;
    int length;
}; // class Queue

} // namespace martineausw
} // namespace dsa

#endif