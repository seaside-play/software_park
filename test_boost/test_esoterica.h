#pragma once

class TestEsoterica {
 public:
  void Test();

 private:
  void TestBoostAny();
  void TestBoostVariant();
  void TestBoostVariant2();
  int TestOptional(); // 5:����һ��ֵ����û��ֵ�ĵط�����һ����־
  void TestArray();  // 6: �Ӻ�����������, C++11���ṩstd::array
  void TestTuple(); // 7: C++11���ṩstd::tuple
  void TestTie(); // 8: C++11���ṩstd::tie


};
