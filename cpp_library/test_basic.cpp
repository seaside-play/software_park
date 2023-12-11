#include "test_basic.h"

#include <cmath>

namespace test {

void TestBasic::Test() {
  TestBoolean();
  TestPow();
  TestSin();
  TestRegister();
  TestBit();
  TestStruct();
}

void TestBasic::TestBoolean() {
  int a = 10;
  bool flag = !!a;

  int b = 0;
  bool flag2 = !!b;
}

void TestBasic::TestPow() {
  auto num = 25;
  auto square_root = std::pow(num, 0.5);
}

void TestBasic::TestSin() {
  double pi = std::acos(-1);

  auto degree_30 = pi / 6;
  auto sin_value = std::sin(degree_30);
  auto arc_sin_value = std::asin(sin_value);
}

void TestBasic::TestRegister() {
  auto BoolRetureValue = []() {
    static bool flag = true;
    flag = !flag;
    return flag;
  };

  auto ret = BoolRetureValue();
  ret = BoolRetureValue();

  auto StrReturn = []() { return "HelloWorld!"; };

  auto str = StrReturn();

  auto curline = 1;
  curline = std::sin(1);
}

void TestBasic::TestBit() {
  auto nIncrement = 2048;
  auto nAvailableSize = 5000;
  auto nCurSize = 4996;
  auto nCurNewSize = nCurSize + 10;
  if (nCurNewSize >= nAvailableSize) {
    nAvailableSize = (nCurNewSize & ~(nIncrement - 1)) + nIncrement;
  }
}

void TestBasic::TestStruct() {
  struct stu1 {
    int i;
    char c;
    int j;
  };

  struct stu2 {
    char c;
    int i;
    short d;
  };

  struct stu3 {
    bool c;
    int i;
    short d;
  };

  auto size = sizeof(stu1);
  auto size2 = sizeof(stu2);
  auto size3 = sizeof(stu3);

  struct st1 {
    bool flag;
    char c;
    int i;
  };

  struct Base {
    virtual void f() {}
  };
  struct Deriver : Base {
    int i;
    bool flag;
    int j;
    virtual void f() {}
  };

  auto len = sizeof(st1);
  auto len1 = sizeof(Deriver);
}

}  // namespace test
