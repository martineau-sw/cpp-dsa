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

    const std::unique_ptr<T> peak_front() const;
    const std::unique_ptr<T> peak_back() const;
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

    std::unique_ptr<Queue<T>::Node> back;
    Queue<T>::Node* front;
    int length;
}; // class Queue

template <class T>
Queue<T>::Queue() 
  : front { nullptr }, back { nullptr }, length { 0 } {
}

template <class T>
void Queue<T>::enqueue(T value) {
  if (length == 0) {
    length++;
    back = std::make_unique<Queue<T>::Node>(value);
    front = back.get();
    return;
  }

  length++;
  front->next = std::make_unique<Queue<T>::Node>(value);
  front = front->next.get();
}

template <class T>
std::unique_ptr<T> Queue<T>::dequeue() {
  if (length == 0) {
    return nullptr;
  }

  if (length == 1) {
    length--;
    auto value { std::make_unique<T>(front->value) };
    front = nullptr;
    back = nullptr;
    return value;
  }
  length--;
  auto value { std::make_unique<T>(front->value) };
  back = std::move(back->next); 
  return value;
}

template <class T>
const std::unique_ptr<T> Queue<T>::peak_front() const {
  return front ? std::make_unique<T>(front->value) : nullptr;
}

template <class T>
const std::unique_ptr<T> Queue<T>::peak_back() const {
  return back ? std::make_unique<T>(back->value) : nullptr;
}

template <class T>
int Queue<T>::get_length() const {
  return length;
} 

template <class T>
Queue<T>::Node::Node(T value) 
  : value { value }, next { nullptr } {
}

} // namespace martineausw
} // namespace dsa

#endif