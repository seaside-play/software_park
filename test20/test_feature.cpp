#include "test_feature.h"

#include <iostream>
#include <coroutine>
#include <generator>

void TestFeature::Test() {
  TestCoroutine();
}

void TestFeature::TestCoroutine() {

  co_await std::suspend_always{};

  std::cout << "Hello from coroutine!" << std::endl;
}