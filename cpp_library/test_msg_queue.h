#pragma once

#include <atomic>
#include <memory>

// refer:https://blog.csdn.net/u012372584/article/details/129882538

namespace test {

template <typename T>
class LockFreeQueue {
 public:
  LockFreeQueue()
      : head(new Node), tail(head.load()) {}
  LockFreeQueue(const LockFreeQueue&) = delete;
  LockFreeQueue& operator=(const LockFreeQueue&) = delete;
  ~LockFreeQueue() {
    while (Node* old_head = head.load()) {
      head.store(old_head->next);
      delete old_head;
    }
  }

  std::shared_ptr<T> pop() {
    Node* old_head = pop_head();
    if (!old_head) return std::shared_ptr<T>();
    auto res(old_head->data);
    delete old_head;
    return res;
  }

  void push(T new_value) {
    std::shared_ptr<T> new_data(std::make_shared<T>(std::move(new_value)));
    Node* p = new Node();
    Node* const old_tail = tail.load();
    old_tail->data.swap(new_data);
    old_tail->next = p;
    tail.store(p);
  }

 private:
  struct Node {
    Node() : next(nullptr) {}
    Node* next;
    std::shared_ptr<T> data;
  };

  std::atomic<Node*> head;
  std::atomic<Node*> tail;

  Node* pop_head() {
    Node* old_head = head.load();
    if (old_head == tail.load()) {
      return nullptr;
    }
    head.store(old_head->next);
    return old_head;
  }
};

class TestMsgQueue {
 public:
  void Test();

 private:
  void TestLockFreeQueue1();
  void TestAtomic();
};

}  // namespace

