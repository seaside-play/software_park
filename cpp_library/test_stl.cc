#include "test_stl.h"

#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <unordered_map>

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

}  // namespace test