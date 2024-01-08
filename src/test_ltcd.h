#pragma once

#include <vector>

namespace test {

struct ListNode {
  int val;
  struct ListNode* next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class TestLtcd {
 public:
  void Test();

 private:
  void TrapRainWaterTest_42(); 
  int TrapRainWater(std::vector<int>& height);


  // test list
  void TestReverseBetween(); // 2024/1/4 
  ListNode* ReverseBetween(ListNode* head, int m, int n); // 反转指定区域

  // test heap
  void TestHeap();
};

}  // namespace test
