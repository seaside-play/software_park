#include "test_question.h"

#include <iostream>
#include <stack>
#include <vector>

namespace test {

void TestQuestion::Test() {
  EvenNumber();
  TestDrink();
}

bool TestQuestion::IsPopStackReasonable(int* order_list,
                                        int* pop_list,
                                        int count) {
  if (order_list == nullptr || pop_list == nullptr || count < 1)
    return false;

  auto order_list_end = order_list + count;
  auto pop_list_end = pop_list + count;

  std::stack<int> stack;
  stack.push(*order_list);
  ++order_list;

  while (!stack.empty()) {
    if (stack.top() != *pop_list) {
      if (order_list ==
          order_list_end)  // 表示已经找完了顺序序列，没有数据可压栈了，不能匹配
        break;

      stack.push(*order_list);
      ++order_list;
    } else {
      stack.pop();
      ++pop_list;
    }
  }

  return stack.empty() ? true : false;
}

void TestQuestion::PrintBinaryTreeByOrder() {}

void TestQuestion::PrintBinaryTreeByLine() {}

void TestQuestion::PrintBinaryTreeByZ() {}

void TestQuestion::EvenNumber() {
  std::vector<int> single_number{1, 2, 3, 4, 5, 6, 7, 6, 5, 4, 3, 2, 1};
  int xor_number = 0;
  for (const auto& iter : single_number) {
    xor_number ^= iter;
  }

  std::cout << "single number is: " << xor_number;
}

class DrinkCalculater {
 public:
  explicit DrinkCalculater(int empty_bootle_number)
      : empty_bootle_number_(empty_bootle_number), drink_counts_(0) {}

  void CalculateMaxDrinkCount() {
    drink_counts_ = empty_bootle_number_;
    std::cout << drink_counts_ << std::endl;
  }

 private:
  int empty_bootle_number_;
  int drink_counts_;
};

void TestQuestion::TestDrink() {
  auto empty_bottle_number = 0;
  
  while (std::cin >> empty_bottle_number && empty_bottle_number != 0) {
    if (empty_bottle_number < 1 || empty_bottle_number > 100) {
      std::cout << "empty bootle number exception, read next number\n";
      continue;
    }
    

    DrinkCalculater drink_calcluater(empty_bottle_number);
    drink_calcluater.CalculateMaxDrinkCount();
  }
}

}  // namespace test