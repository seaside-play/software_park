#include "test_basic.h"

#pragma once

namespace test {
  
void TestBasic::Test() {
  TestBoolean();
}

void TestBasic::TestBoolean() {
  int a = 10;
  bool flag = !!a;

  int b = 0;
  bool flag2 = !!b;
  
}
}  // namespace test
