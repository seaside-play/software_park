#include "test_thread.h"

#include <atomic>
#include <condition_variable>
#include <thread>
#include <mutex>
#include <chrono>
#include <iostream>

using namespace std;

namespace test {

std::atomic_flag flag;
int a = 0;

void foo() {
  for(int i = 0; i < 1000000; ++i) {
    while (flag.test_and_set()) {}
    a += 1;
    flag.clear();
  }
}

void TestThread::Test() {
  TestAtomicFlag();
  TestConditionVariable();
}

void TestThread::TestAtomicFlag() {
  flag.clear();

  std::clock_t start, end;

  start = clock();

  std::thread t1(foo);
  std::thread t2(foo);
  t1.join();
  t2.join();

  end = clock();

  std::cout << a << std::endl;
  std::cout << end - start << std::endl;
}

std::condition_variable cond;
std::mutex mtx;
auto b = 0;
std::atomic<int> atomic_count(0);

void first() {
  while (atomic_count.fetch_sub(1) >= 0) {
    unique_lock<mutex> lck(mtx);
  
    while (b % 3 != 0)
      cond.wait(lck); // 若不符合条件，则继续等待

    b++;
    
    cout << b % 3 << endl;
    cond.notify_all();
  }
}

void second() {
  while (atomic_count.fetch_sub(1) >= 0) {
    unique_lock<mutex> lck(mtx);
  
    while (b % 3 != 1)
      cond.wait(lck); // 若不符合条件，则继续等待

    b++;
    
    cout << b % 3 << endl;
    cond.notify_all();
  }
}


void third() {
  while (atomic_count.fetch_sub(1) >= 0) {
    unique_lock<mutex> lck(mtx);
  
    while (b % 3 != 2)
      cond.wait(lck); // 若不符合条件，则继续等待

    b++;
    
    cout << b % 3 << endl;
    cond.notify_all();
  }
}

// 现在我们使用C++11的条件变量完成三个线程顺序打印0，1，2：
void TestThread::TestConditionVariable() {
  atomic_count.store(42);
  thread t1(first);
  thread t2(second);
  thread t3(third);
  t1.join();
  t2.join();
  t3.join();

  this_thread::sleep_for(chrono::seconds(1));
}

}  // namespace test
