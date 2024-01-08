#include "test_ltcd.h"

#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
#include <memory>

namespace test {

void TestLtcd::Test()
{
  TrapRainWaterTest_42();

  // test list
  TestReverseBetween();

  TestHeap();
}

void TestLtcd::TrapRainWaterTest_42()
{
  std::vector<int> vi{0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
  auto trap_sum = TrapRainWater(vi);
}

int TestLtcd::TrapRainWater(std::vector<int>& height)
{
  if (height.size() < 3)
    return 0;

  auto Subtrahead = [&height](int start, int end) { 
    auto interval = end - start - 1;
    auto high = std::min(height[start], height[end]);
    auto substrahead = 0;
    for (auto i = start + 1; i < end; ++i)
      substrahead += height[i];
    return interval * high - substrahead;
  };
  
  auto index = 0;
  auto start = 0;
  auto end = start;
  auto length = height.size() -1;

  for(; index < length - 1; ++index) {
    if (height[index] <= height[index + 1])
      continue;
     break;
  }
      
  start = index;
  
  index++;
  auto trap_sum = 0;
  for (; index < length - 1; ++index) {
    if (height[index] <= height[index + 1] || height[index] < start) 
      continue;
    end = index;
    trap_sum += Subtrahead(start, end);
    start = end;
  }

  return trap_sum;
}

void TestLtcd::TestReverseBetween() {
  auto head = new ListNode(1);
  auto p = head;
  for (auto i = 2; i < 6; ++i) {
    auto cur = new ListNode(i);
    p->next = cur;
    p = cur;
  }
  auto ret = ReverseBetween(head, 2, 4);

  auto q = head;
  while (head != nullptr) {
    q = head->next;
    delete head;
    head = q;
  }
}

ListNode* TestLtcd::ReverseBetween(ListNode* head, int m, int n) {
    auto cur_temp = new ListNode(-1);
    auto pre = cur_temp;
    pre->next = head;
    auto start = head;
    for (auto i = 1; i < m; ++i) {
      pre = pre->next;
      start = start->next;
    }

    for (auto i = 0; i < n - m; ++i) {
      auto temp = start->next;
      start->next = temp->next;
      temp->next = pre->next;
      pre->next = temp;
    }
    
    auto ret = cur_temp->next;
    delete cur_temp;

    return ret;
  }

void TestLtcd::TestHeap() {
  std::vector<int> vi = {29,23,20,22,17,15,26,51,19,12,35,40};
  std::make_heap(vi.begin(), vi.end());

  auto Comp = [](int a, int b){ return a > b; };
}

}  // namespace test