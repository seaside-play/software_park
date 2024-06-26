#include "test_msg_queue.h"

#include <cstdio>
#include <string>
#include <thread>
#include <iostream>

#include "base.h"

namespace test {

typedef struct Value {
  char s[20];
  std::string str;
  int i;
};

void TestMsgQueue::Test() {
  TestLockFreeQueue1();
  //TestAtomic();
}

void TestMsgQueue::TestLockFreeQueue1() {
  Tip(__func__);

  LockFreeQueue<Value> queue;
  std::thread th1([&]() {
    for (int i = 0; i < 10; i++) {
      Value value;
      sprintf_s(value.s, "第%d组数据", i + 1);
      value.str = "您好，世界!";
      value.i = i + 1;

      queue.push(value);
    }
  });

  std::thread th2([&](){
    for (int i = 0; i < 10; ++i) {
      std::shared_ptr<Value> node = queue.pop();
      if (node)
        std::cout << node->s << ":" << node->str << ":" << node->i << std::endl;
    }
  });

  th1.join();
  th2.join();
}

void TestMsgQueue::TestAtomic() {
  std::atomic<int> atomic_int;
  auto is_lock_free = atomic_int.is_lock_free();

}

}  // namespace