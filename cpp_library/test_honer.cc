#include "test_honer.h"
#include <iostream>
#include <string>
#include <array>

namespace test {

void TestHoner::Test() {
  //TestDrink();
  //TestRandomNumber();
  TestHexToDecimal();
}

/*
输入描述：
输入文件最多包含10组测试数据，每个数据占一行，仅包含一个正整数 n（ 1<=n<=100 ），表示小张手上的空汽水瓶数。n=0 表示输入结束，你的程序不应当处理这一行。

输出描述：
对于每组测试数据，输出一行，表示最多可以喝的汽水瓶数。如果一瓶也喝不到，输出0。

异常分析：该题的关键异常点是输入的数据可能为大数，这个时候，就不能想当然的认为输入数据为有效的整数。所有需要进行防御性判断。


*/


void TestHoner::TestDrink() {
    std::string number;
    while (std::cin >> number && number != "0") { // 注意 while 处理多个 case
      if (number.size() > 3)
        continue;
      auto cur_num = std::stoi(number);
      std::cout << cur_num/2 << "\n";
    }
};


/*
明明生成了N个1到500之间的随机整数。请你删去其中重复的数字，即相同的数字只保留一个，把其余相同的数去掉，然后再把这些数从小到大排序，按照排好的顺序输出。

数据范围： 

 
1≤n≤1000  ，输入的数字大小满足 
1≤n≤500， 随机数据大小
 
输入描述：
第一行先输入随机整数的个数 N 。
接下来的 N 行每行输入一个整数，代表明明生成的随机数。
具体格式可以参考下面的"示例"。
输出描述：
输出多行，表示输入数据处理后的结果
*/

#include <exception>
#include <stdexcept>

void TestHoner::TestRandomNumber() {
  int remain_count;
  std::cin >> remain_count;

  std::array<bool, 501> arr;
  arr.fill(false);
  int cur_num;
  while (remain_count != 0 &&
         std::cin >> cur_num) {  // 注意 while 处理多个 case
    --remain_count;
    arr[cur_num] = true;
  }
  for (int i = 1; i < 501; ++i) {
    if (arr[i])
      std::cout << i << "\n";
  }
}


class HexTransfer {
 public:
  HexTransfer(std::string hex) : hex_(std::move(hex)) {}

  bool IsValid() {
    if (hex_.size() > 10 || hex_.size() <= 2)
      return false;

    if (hex_[0] != '0' || !((hex_[1] == 'x') || (hex_[1] == 'X')))
      return false;

    for (auto i = 2; i < hex_.size(); ++i) {
      if (!IsCurCharValid(hex_[i]))
        return false;
    }

    return true;
  }

  unsigned ToDecimal() {
    if (!IsValid())
      return 0;
      
    auto cur_valid_count = hex_.size() - 2 - 1;
    auto range = hex_.size() - 1;
    for (int i = 2; i < hex_.size(); ++i) {
      unsigned cur_number = GetNumberByChar(hex_[i]);
      decimal_result_ += cur_number * GetPowBase16(range - i);
    }

    return decimal_result_;
  }

 private:
  bool IsCurCharValid(char c) {
    return ('0' <= c && c <= '9') || ('a' <= c && c <= 'f') ||
           ('A' <= c && c <= 'F');
  }

  unsigned int GetPowBase16(int times) {
    unsigned int result = 1;
    if (times == 0)
      return result;

    for (int i = 0; i < times; ++i) {
      result *= kBase_;
    }

    return result;
  }

  unsigned GetNumberByChar(char c) {
    if ('0' <= c && c <= '9')
      return c - '0';
    else if ('a' <= c && c <= 'f')
      return c - 'a' + 10;
    else
      return c - 'A' + 10;
  }

 private:
  unsigned decimal_result_{0};
  std::string hex_;
  const unsigned kBase_ {16};
};

void TestHoner::TestHexToDecimal() {
  std::string hex_number;
  while (std::cin >> hex_number) {
    HexTransfer hex_transfer(hex_number);
    auto result = hex_transfer.ToDecimal();
    std::cout << std::to_string(result) << "\n";
  }
}

}  // namespace test