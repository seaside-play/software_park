#ifndef TEST_QUESTION_MESSAGE_QUEUE_H_
#define TEST_QUESTION_MESSAGE_QUEUE_H_

#pragma once

#include <condition_variable>
#include <mutex>
#include <queue>

namespace test {

// 初级版消息队列，没有考虑消息队列的数据容量

template <typename T>
class MessageQueue {
 public:
  MessageQueue() : queue_(), mutex_(), condition_() {}

  void Push(T msg);
  T Pop();
  bool Pop(T& msg, bool is_blocked = true);
  size_t Size();
  bool Empty();

  MessageQueue(const MessageQueue&) = delete;
  MessageQueue& operator=(const MessageQueue&) = delete;
 
 private:
  std::condition_variable condition_;
  std::queue<T> queue_;
  mutable std::mutex mutex_;
};

}  // namespace test

#endif  // TEST_QUESTION_MESSAGE_QUEUE_H_
