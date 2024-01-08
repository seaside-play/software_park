#pragma once

#include <memory>
#include "MessageQueue.h"

namespace test
{


class TestMessageQueue {
 public:
  TestMessageQueue();
  void Test();

 private:
  std::shared_ptr<MessageQueue<int>> msg_queue_;
};
}


