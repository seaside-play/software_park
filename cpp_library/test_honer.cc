#include "test_honer.h"
#include <iostream>
#include <string>
#include <array>

namespace test {

void TestHoner::Test() {
  //TestDrink();
  //TestRandomNumber();
  //TestHexToDecimal();
  TestSudu();
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

/*
* 1.
��߷��Ƕ���
��ʦ��֪����ĳĳͬѧ���У�������ߵ��Ƕ��٣�����������ģ����ʦ��ѯ�ʡ���Ȼ����ʦ��ʱ����Ҫ����ĳλͬѧ�ĳɼ�.

����������
ÿ�������һ��������������N��M��0 < N <= 30000,0 < M < 5000��,�ֱ����ѧ������Ŀ�Ͳ�������Ŀ��
ѧ��ID��Ŵ�1�ൽN��
�ڶ��а���N��������������N��ѧ���ĳ�ʼ�ɼ������е�i��������IDΪi��ѧ���ĳɼ�
��������M�У�ÿһ����һ���ַ�C��ֻȡ��Q����U������������������A,B,��CΪ'Q'��ʱ��, ��ʾ����һ��ѯ�ʲ���������A

���������
����ÿһ��ѯ�ʲ�������һ�����������߳ɼ�.
ʾ��1
�������ӣ�
5 7
1 2 3 4 5
Q 1 5
U 3 6
Q 3 4
Q 4 5
U 4 5
U 2 9
Q 1 5
������ӣ�
5
6
5
9
ʾ��2
�������ӣ�
3 2
1 2 3
U 2 8
Q 3 1
������ӣ�
8
*/

void TestHoner::TestTopScore() {
  

}

void TestHoner::TestSudu() {
  

}

}  // namespace test

/*
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void method_1() {
  auto number_count = 0;
  const auto kThreshold = 3;
  while (cin >> number_count) { // ע�� while ������ case
    bool* arr = new bool [number_count];
    for (auto i = 0; i < number_count; ++i)
      arr[i] = true;

    auto step = 0;
    auto accum = 0;
    auto GoalAccumNumber = number_count - 1;

    for (auto i = 0; i < number_count; ++i, i = i % number_count) {
      if (arr[i]) {
        accum = 0;
        ++step;
      } else ++accum;

      if (step == kThreshold) {
        arr[i] = false;
        accum = 0;
        step = 0;
      }

      if (accum == GoalAccumNumber) {
        std::cout << (++i) % number_count << "\n";
        break;
      }
    }

    delete [] arr;
  }
}

#include <forward_list>
#include <list>
void method_2() {
  auto number_count = 0;
  const auto kThreshold = 3;
  while (cin >> number_count) { // ע�� while ������ case
    list<int> l;
    for (int i = 0; i < number_count; ++i)
      l.insert(l.end(), i);

    auto cur = l.begin();
    while (l.size() != 1) {
      if (cur == l.end())
        cur = l.begin();
      for (int i = 0; i < 2; ++i) {
        ++cur;
        if (cur == l.end())
          cur = l.begin();
      }
      cur = l.erase(cur);
    }

    cout << l.front() << "\n";
  }

}

int main() {
  method_2();
}
// 64 λ������� printf("%lld")
*/

/*
ÿ����������һ���ַ������ַ�����󳤶�Ϊ100����ֻ������ĸ��������Ϊ�մ������ִ�Сд��
���������
ÿ������һ�У����ַ���ԭ�е��ַ�˳������ַ����ϣ����ظ����ֲ��������ĸ�������
ʾ��1
�������ӣ�
abcqweracb
������ӣ�
abcqwer
ʾ��2
�������ӣ�
aaa
������ӣ�
a
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {

    std::string alphas;
    std::unordered_map<char, bool> flag;
    while (cin >> alphas) { // ע�� while ������ case
        for (const auto &c : alphas) {
          if (!flag[c]) {
            flag[c] = true;
            std::cout << c;
          }
        }
        std::cout << "\n";
    }
}
// 64 λ������� printf("%lld")s
*/

/*
3.
����
������һ�����Ƕ��ǳ���Ϥ�ľ�����Ϸ�����ü�������ǿ��Ժܿ�ؽ⿪�������⣬������һЩ�򵥵�������Ŀ�����дһ��������⡣
���ж�⣬���һ����

����9�У�ÿ��Ϊ�ո������9�����֣�Ϊ0�ĵط�������Ҫ����

������У�ÿ�оŸ��ո���������֣�Ϊ����Ĵ𰸡�
*/