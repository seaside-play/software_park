#pragma once

#include <vector>
#include <utility>
#include <memory>

namespace test {

struct ListNode {
  int val;
  struct ListNode* next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class ListNodeBuilder {
 public:
  template<typename T>
  ListNodeBuilder(T t);

  ListNode* GetFirstNode() { return head_ != nullptr ? head_->next : nullptr;}

  ~ListNodeBuilder();

  static void Print(ListNode* head);

 private:
  ListNode* head_;
};

class BinaryTree;
class TestLtcd {
 public:
  TestLtcd();
  void Test();

 private:
  void TrapRainWaterTest_42(); 
  int TrapRainWater(std::vector<int>& height);


  // test list
  void TestReverseBetween(); // 2024/1/4 
  ListNode* ReverseBetween(ListNode* head, int m, int n); // 反转指定区域

  // test heap
  void TestHeap();

  // BM5
  void TestMergeList();
  ListNode* MergeLists(std::vector<ListNode*>& list);

  // BM6
  void TestHasCycle();
  bool HasCycle(ListNode* head);

  // BM16
  void TestDeleteDuplicates();
  ListNode* DeleteDuplicates(ListNode* head);
  
  // BM19
  void TestFindPeakElement(); 
  int FindPeakElement(std::vector<int>& nums);
  int FindPeakElement(std::vector<int>& nums, int i, int j);
  bool IsPeakElement(std::vector<int>& nums, int mid);

  // BM20 数组中的逆序对
  void TestInversePairs();
  int InversePairs(std::vector<int>& nums);
  int InversePairs(std::vector<int>& nums,
                   std::vector<int>& dst,
                   int left,
                   int right);
  
 private:
  std::shared_ptr<BinaryTree> binary_tree_;
};

}  // namespace test
