#pragma once

class TestEsoterica {
 public:
  void Test();

 private:
  void TestBoostAny();
  void TestBoostVariant();
  void TestBoostVariant2();
  int TestOptional(); // 5:返回一个值或在没有值的地方返回一个标志
  void TestArray();  // 6: 从函数返回数组, C++11已提供std::array
  void TestTuple(); // 7: C++11已提供std::tuple
  void TestTie(); // 8: C++11已提供std::tie


};
