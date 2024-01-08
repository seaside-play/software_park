#include "test_algorithm.h"

#include <algorithm>
#include <vector>

#include "coordinate.h"

namespace test {

void TestAlgorithm::Test() {
  TestUnique();
  TestMove();
}

void TestAlgorithm::TestUnique() {
  std::vector<Coordinate> coordinates = {{1,2}, {2,3}, {2,3}, {3,4}, {3,4}, {5, 6}};

  auto iter_end = std::unique(coordinates.begin(), coordinates.end());

  coordinates.erase(iter_end, coordinates.end());
  coordinates.shrink_to_fit();
};

void TestAlgorithm::TestMove() {
  std::vector<int> vi {1,2,3};
  std::vector<int> vi2 {4,5,6,7};
  std::vector<int> ret(vi.size() + vi2.size() + 1, 0);

  std::move(vi.begin(), vi.end(), ret.begin()+1);
  std::move(vi2.begin(), vi2.end(), ret.begin()+(1+vi.size()));
  
}

}  // namespace test
