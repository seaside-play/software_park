#pragma once

#include <vector>

namespace test {

class TestQuestion {
 public:
  void Test();

  bool IsPopStackReasonable(int* order_list, int* pop_list, int count);
  void PrintBinaryTreeByOrder();
  void PrintBinaryTreeByLine();
  void PrintBinaryTreeByZ();

  void EvenNumber();

  void TestQuickSort();

  void TestDrink();
  void TestRandom();

  void TestHexToDec();


 private:
  void QuickSort(std::vector<int>& data, size_t left, size_t right);
  size_t Partition(std::vector<int>& data, size_t left, size_t right);

};


}  // namespace test
