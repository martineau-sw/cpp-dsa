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

template <class T>
Queue<T>::Queue() 
  : front { nullptr }, back { nullptr }, length { 0 } {
}

template <class T>
void Queue<T>::enqueue(T value) {

}

template <class T>
std::unique_ptr<T> Queue<T>::dequeue() {
  return nullptr;
}

template <class T>
const T* Queue<T>::peak_front() const {
  return front;
}

template <class T>
const T* Queue<T>::peak_back() const {
  return back;
}

template <class T>
int Queue<T>::get_length() const {
  return length;
} 

} // namespace martineausw
} // namespace dsa

#endif