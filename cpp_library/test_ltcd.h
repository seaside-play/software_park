#pragma once

#include <vector>

namespace test {

class TestLtcd
{
 public:
  void Test();

 private:

  void TrapRainWaterTest_42();
  int TrapRainWater(std::vector<int>& height);
};

}  // namespace test


