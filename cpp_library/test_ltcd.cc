#include "test_ltcd.h"

#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

namespace test {

void TestLtcd::Test()
{
  TrapRainWaterTest_42();
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

}  // namespace test