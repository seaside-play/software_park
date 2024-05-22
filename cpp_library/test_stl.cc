#include "test_stl.h"

#include <array>
#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <bitset>

namespace test {

void TestStl::Test() {
  TestNthElement();
  TestDecimalTransfer();
  TestSort();
  TestNumeric();
  TestRemove();
  TestRotate();
  TestVector();
  TestSet();
  TestMap();
  TestUnorderMap();
  TestStringAssign();
  TestMap2();
  TestInsert();
  TestUnorderedMap();
  TestBitset();
  TestMoveVector();
}
 
void TestStl::TestNthElement() {
  std::cout << "TestNthElement: \n";
  std::vector<int> vi {4,2,1,2,3,42,35,76,111,21};
  auto iter = vi.begin();
  std::advance(iter, 3);
  std::cout << "raw iter data is: " << *iter << "\n";
  std::nth_element(vi.begin(), iter, vi.end());
  std::cout << "new iter data is: " << *iter << "\n";
};

void TestStl::TestDecimalTransfer() {
  std::string hex{"0xA0"};
  auto dec = std::stol(hex, nullptr, 16);
}

void TestStl::TestSort() {
  struct Student{
    Student(std::string&& name, std::string&& grade, int age) 
        : name_(std::move(name)), grade_(std::move(grade)), age_(age) {}
    std::string name_;
    std::string grade_;
    int age_;
  };

  std::vector<Student> students;
  students.emplace_back("wubz", "class 10", 28);
  students.emplace_back("wucj", "class 10", 1);
  students.emplace_back("zhangyw", "class 10", 58);

  std::sort(students.begin(), students.end(), [](const auto& lhs, const auto& rhs) {
    return lhs.age_ < rhs.age_;
  });
}

void TestStl::TestNumeric() {
  std::cout << "TestNumeric: \n";
  std::vector<int> vi{4, 2, 1, 2, 3, 42, 35, 76, 111, 21};

  auto i = 2;
  auto j = 4;
  auto sum0 = std::accumulate(vi.begin() + i, vi.begin() + 4 + 1, 0);
  auto sum = std::accumulate(vi.begin(), vi.end(), 0);

  std::vector<int> vi2(10, 0);
  std::iota(vi2.begin(), vi2.end(), 2);
}

void TestStl::TestRemove() {
  std::vector<int> vi{4, 2, 1, 2, 3, 42, 35, 76, 111, 21};
  auto end_it = std::remove(vi.begin(), vi.end(), 2);
}

void TestStl::TestRotate() {
  std::vector<int> vi(10, 0);
  std::iota(vi.begin(), vi.end(), 1);
  auto iter = vi.begin();
  std::advance(iter, 3);
  auto ret = std::rotate(vi.begin(), iter, vi.end());
}

void TestStl::TestVector() {
  std::vector<int> vi(5,1);
  vi.resize(20);
}

void TestStl::TestSet() {
  std::set<std::string> s = {"A", "C", "W", "z"};
}

void TestStl::TestMap() {
  struct rgb {
    int r;
    int g;
    int b;
    rgb(int r, int g, int b) {
      this->r = r;
      this->g = g;
      this->b = b;
    }
  };
  std::map<int, rgb> m = { {1,rgb(1,1,1)}, {2,rgb(1,1,1)} };
}

void TestStl::TestUnorderMap() {
  std::unordered_map<std::string, std::string> test = { {"name", "wucj"}, {"age", "18"} };
  std::string key = "name";
  auto ret = test.find(key.c_str());
}

void TestStl::TestStringAssign() {
  std::string str("Hello Worldsfffffffffffffffffffffffffffffffffffff");
  str.assign("wucj", 4);
}

void TestStl::TestMax() {
  int a = 0;
  int b = 1;
  auto c = std::max(a, b);
}

template <typename T = char, size_t N = 10>
using Arrays = std::array<T, N>;


void TestStl::TestArray() {
}

namespace mars{
namespace kicad{
using NetNames = std::map<size_t, std::string>;
}
}

namespace wise {
namespace layout {
using NetNs = std::map<size_t, std::string>;
using SpNetNs = std::shared_ptr<NetNs>;
}
}

void TestStl::TestMap2() {
  wise::layout::SpNetNs data;
  mars::kicad::NetNames net_names = {{1, "GND"},{2, "VSS"}};
  data = std::make_shared<wise::layout::NetNs>(net_names);
}

void TestStl::TestInsert() {
  std::unordered_set<size_t> hash_id;
  auto ret = hash_id.insert(1);
  auto ret2 = hash_id.insert(1);
  auto data = *ret2.first;

  size_t t = data;

}

struct Point {
  Point(int x, int y) {}
};

void TestStl::TestUnorderedMap() {
  std::vector<size_t> pt;
  std::unordered_map<size_t, size_t> indexs;
  auto ret = indexs.emplace(111, pt.size());
  if (ret.second) {
    pt.push_back(ret.first->first);
  }

  auto index = 0;
  auto ret2 = indexs.emplace(111, 1);
  if (!ret2.second) {
    index = ret2.first->second;
  }
 
  bool cancel = false;
  auto bcancel = !!cancel;
}

void TestStl::TestBitset() {
  std::bitset<64> a(std::string("0101"));
  std::bitset<64> b(std::string("0001"));
  a |= b;
  a &= b;

  std::bitset<64> c(std::string("0101"));

  for (int i = 0; i < 64; ++i) {
    if (c[i]) {
      std::cout << "i: " << i << std::endl;
    }
  }
}

void TestStl::TestMoveVector() {
  std::vector<std::string> source = {
      "Hello", "World", "I",     "love", "you",  "Do",    " you", "like", "it",
      "?",     "and",   "where", "are",  "from", "China", "or",   "USA"};

  // 定义要移动的区间
  auto first = source.begin() + 2;   // 第三个元素开始
  auto last = source.begin() + 7;    // 第八个元素结束
  auto first2 = source.begin() + 9;  // 第10个元素结束
  auto last2 = source.begin() + 12;  // 第13个元素结束

  std::vector<std::string> destination(std::make_move_iterator(first),
                                       std::make_move_iterator(last));
  destination.insert(destination.end(), std::make_move_iterator(first2),
                     std::make_move_iterator(last2));

  destination.swap(source);
}

}  // namespace test