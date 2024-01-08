#include "MessageQueue.h"

namespace test 
{

template <typename T>
void MessageQueue<T>::Push(T msg) {
  std::lock_guard<std::mutex> lock(mutex_);
  queue_.push(msg);
  condition_.notify_one();
}

template <typename T>
T MessageQueue<T>::Pop() {
  std::unique_lock<std::mutex> lock(mutex_);
  condition_.wait(lock, []() { return !queue_.empty(); });
  T msg = std::move(queue_.front());
  queue_.pop();
  return msg;
}

template <typename T>
bool MessageQueue<T>::Pop(T& msg, bool is_blocked /*= true*/) {
  if (!is_blocked) {
    std::lock_guard<std::mutex> lock(mutex_);
    if (queue_.empty())
      return false;
  }

  msg = Pop();
  return true;
}

template <typename T>
size_t MessageQueue<T>::Size() {
  std::lock_guard<std::mutex> lock(mutex_);
  return queue_.size();
}

template <typename T>
bool MessageQueue<T>::Empty() {
  std::lock_guard<std::mutex> lock(mutex_);
  return queue_.empty();
}

}
