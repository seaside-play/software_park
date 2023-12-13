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
����������
�����ļ�������10��������ݣ�ÿ������ռһ�У�������һ�������� n�� 1<=n<=100 ������ʾС�����ϵĿ���ˮƿ����n=0 ��ʾ�����������ĳ���Ӧ��������һ�С�

���������
����ÿ��������ݣ����һ�У���ʾ�����Ժȵ���ˮƿ�������һƿҲ�Ȳ��������0��

�쳣����������Ĺؼ��쳣������������ݿ���Ϊ���������ʱ�򣬾Ͳ����뵱Ȼ����Ϊ��������Ϊ��Ч��������������Ҫ���з������жϡ�


*/


void TestHoner::TestDrink() {
    std::string number;
    while (std::cin >> number && number != "0") { // ע�� while ������ case
      if (number.size() > 3)
        continue;
      auto cur_num = std::stoi(number);
      std::cout << cur_num/2 << "\n";
    }
};


/*
����������N��1��500֮����������������ɾȥ�����ظ������֣�����ͬ������ֻ����һ������������ͬ����ȥ����Ȼ���ٰ���Щ����С�������򣬰����źõ�˳�������

���ݷ�Χ�� 

 
1��n��1000  ����������ִ�С���� 
1��n��500�� ������ݴ�С
 
����������
��һ����������������ĸ��� N ��
�������� N ��ÿ������һ�������������������ɵ��������
�����ʽ���Բο������"ʾ��"��
���������
������У���ʾ�������ݴ����Ľ��
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
         std::cin >> cur_num) {  // ע�� while ������ case
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