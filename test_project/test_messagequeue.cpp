#include "test_messagequeue.h"
#include "MessageQueue.h"

namespace test {

TestMessageQueue::TestMessageQueue() : msg_queue_(std::make_shared<MessageQueue<int>>()) {}

void TestMessageQueue::Test() {
  
}

}
