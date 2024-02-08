#include "test_ltcd.h"

#include <algorithm>
#include <deque>
#include <iostream>
#include <list>
#include <memory>
#include <stack>
#include <vector>

#include "binary_tree.h"

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

TestLtcd::TestLtcd()
    : binary_tree_(std::make_shared<BinaryTree>()) {}

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

  // BM20
  TestInversePairs();

  // BM31
  TestSymmetrical();
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

void TestLtcd::TestFindPeakElement() {
  std::vector<int> vi = {2, 4, 1, 2, 7, 8, 4};
  FindPeakElement(vi);
}

int TestLtcd::FindPeakElement(std::vector<int>& nums) {
  // write code here
  return FindPeakElement(nums, 0, static_cast<int>(nums.size()) - 1);
}

int TestLtcd::FindPeakElement(std::vector<int>& nums, int i, int j) {
  auto mid = i + ((j - i) >> 1);

  if (IsPeakElement(nums, mid)) {  // 先进行目标判断
    return mid;
  } else if (nums[mid + 1] > nums[mid]) {
    return FindPeakElement(nums, mid + 1, j);
  } else {
    return FindPeakElement(nums, i, mid - 1);
  }
}
bool TestLtcd::IsPeakElement(std::vector<int>& nums, int mid) {
  if (nums[mid] > nums[mid - 1] && nums[mid] < nums[mid + 1])
    return true;
  else
    return false;
}

// BM20 数组中的逆序对
void TestLtcd::TestInversePairs() {
  std::vector<int> vec {1,2,3,4,5,6,7,0};
  auto count = InversePairs(vec);
}

int TestLtcd::InversePairs(std::vector<int>& nums) {
  if (nums.empty() || nums.size() == 1)
    return 0;

  std::vector<int> dst(nums.size(), -1);
  return InversePairs(nums, dst, 0, static_cast<int>(nums.size()) - 1);
}

int TestLtcd::InversePairs(std::vector<int>& nums,
                         std::vector<int>& dst,
                         int left,
                         int right) {
  if (left >= right) {
    return 0;
  }

  auto mid = left + ((right - left) >> 1);
  auto ret = InversePairs(nums, dst, left, mid) +
             InversePairs(nums, dst, mid + 1, right);
  int mod = 1000000007;
  ret %= mod;

  for (auto i = left; i <= right; ++i) {
    nums[i] = dst[i];
  }

  auto i = mid, j = right;
  auto k = right;
  auto count = 0;
  while (i >= left && j >= mid + 1) {
    if (nums[i] > nums[j]) {
      count += j - mid;      // 累加逆序对个数
      dst[k--] = nums[i--];  // 排序，将当前最大放入到dst中
    } else {
      dst[k--] = nums[j--];  // 排序，将当前最大放入到dst中
    }
  }

  while (i >= left)  // 如果右边的数组已无数据，就需要将左边的数据放入dst数组中
    dst[k--] = nums[i--];

  while (j >=
         mid + 1)  // 如果左边的数组已无数据，就需要将右边的数据放入到dst数组中
    dst[k--] = nums[j--];

  return ret + count;
}

void TestLtcd::TestSymmetrical() {
  
}

bool TestLtcd::IsSymmetrical(TreeNode* pRoot) {
  if (pRoot == nullptr)
    return true;

  return IsSymmetricalCore(pRoot, pRoot);
}

bool TestLtcd::IsSymmetricalCore(TreeNode* pRoot1, TreeNode* pRoot2) {
  if (pRoot1 == nullptr)
    return true;

  
  return false;
}

}  // namespace test