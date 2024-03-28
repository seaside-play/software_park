#include "test_overflow.h"

#include <vector>

void TestOverflow::Test() {
  TestVectorOverflow();
}

void TestOverflow::TestVectorOverflow() {
  std::vector<int> vi{1, 2, 3, 4};
  std::vector<int> vi2{5, 6, 7, 8, 9};

  for (auto i = 0; i < vi2.size(); ++i)
    vi[i] = vi2[i];
}