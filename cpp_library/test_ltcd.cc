#include "test_ltcd.h"

#include <algorithm>
#include <deque>
#include <iostream>
#include <stack>
#include <vector>
#include <list>
#include <memory>

namespace test {

template <typename T> 
ListNodeBuilder::ListNodeBuilder(T t) : head_(nullptr) {
  head_ = new ListNode(-1);
  auto p = head_;
  for (const auto& item : t) {
    p->next = new ListNode(item);
    p = p->next;
  }
}

void ListNodeBuilder::Print(ListNode* head) {
  while (head != nullptr) {
    std::cout << head->val << " ";
    head = head->next;
  }
  std::cout << "\n";
}

ListNodeBuilder::~ListNodeBuilder() {
  while (head_ != nullptr) {
    auto temp = head_->next;
    delete head_;
    head_ = temp;
  }
}

void TestLtcd::Test()
{
  TrapRainWaterTest_42();

  // test list
  TestReverseBetween();

  TestHeap();

  // BM5
  TestMergeList();

  // BM6 
  TestHasCycle();

  // BM13
  TestDeleteDuplicates();
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

  std::make_heap(vi.begin(), vi.end(), Comp);
}

struct ValueNode {
  size_t value;
  ListNode* index;
  ValueNode(size_t v, ListNode* l) : value(v), index(l) {}
};

void TestLtcd::TestMergeList() {
  std::vector<ListNode*> list;
  auto l1 = new ListNodeBuilder(std::vector{1,4,7,9,19});
  auto l2 = new ListNodeBuilder(std::list{8,15,67,99,199});
  auto l3 = new ListNodeBuilder(std::deque{1,5,7,9,29});
  list.push_back(l1->GetFirstNode());
  list.push_back(l2->GetFirstNode());
  list.push_back(l3->GetFirstNode());

  auto ret = MergeLists(list);
} 

ListNode* TestLtcd::MergeLists(std::vector<ListNode*>& lists) {
  if (lists.empty())
    return nullptr;
  std::vector<ListNode*> data;
  auto Comp = [](const ListNode* lhs, const ListNode* rhs) {
    return lhs->val > rhs->val;
  };
  for (auto& item : lists) {
    if (item == nullptr)
      continue;
    data.push_back(item);
  }

  auto head = new ListNode(-1);
  auto p = head;
  std::make_heap(data.begin(), data.end(), Comp);
  while (!data.empty()) {
    std::pop_heap(data.begin(), data.end(), Comp);
    auto min_value = data.back();
    p->next = min_value;
    p = p->next;
    if (min_value->next == nullptr)
      data.pop_back();
    else
      data.back() = min_value->next;
    std::push_heap(data.begin(), data.end(), Comp);
  }

  auto ret = head->next;
  
  ListNodeBuilder::Print(ret);

  delete head;
  return ret;
}

void TestLtcd::TestHasCycle() {
  
}

bool TestLtcd::HasCycle(ListNode* head) {
  ListNode* slow = head;
  ListNode* fast = head;
  while (fast != nullptr && fast->next != nullptr) {
    slow = slow->next;
    fast = fast->next->next;
    if (slow == fast) {
      return true;
    }
  }
  return false;
}

void TestLtcd::TestDeleteDuplicates() {
  auto builder = ListNodeBuilder(std::vector<int>{1,2,2});
  auto head = builder.GetFirstNode();
  auto ret = DeleteDuplicates(head);
}

ListNode* TestLtcd::DeleteDuplicates(ListNode* head) {
  if (head == nullptr || head->next == nullptr) return head;
  auto virtual_head = new ListNode(-1);
  virtual_head->next = head;

  auto pre = virtual_head;
  auto cur = virtual_head->next;
  auto delete_cur = false;
  while (cur != nullptr && cur->next != nullptr) {
    if (cur->val == cur->next->val) {
      delete_cur = true;
      auto temp = cur->next;
      cur->next = temp->next; 
      delete temp;
    } else {
      if (delete_cur) {
        pre->next = cur->next;
        delete cur;
        cur = pre->next;
        delete_cur = false;
      } else {
        pre = cur;
        cur = cur->next;
      }
    }
  }

  if (delete_cur) {
    pre->next = cur->next;
    delete cur;
  }

  auto new_head = virtual_head->next;
  delete virtual_head;
  return new_head;
}

}  // namespace test