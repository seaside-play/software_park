#pragma once

namespace test
{
class TestThread {
public:
  void Test();

private:
  void TestAtomicFlag();
  void TestConditionVariable();
};
}

