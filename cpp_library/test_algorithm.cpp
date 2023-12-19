#include "test_algorithm.h"

#include <algorithm>
#include <vector>

#include "coordinate.h"

namespace test {

void TestAlgorithm::Test() {
  TestUnique();
}

void TestAlgorithm::TestUnique() {
  std::vector<Coordinate> coordinates = {{1,2}, {2,3}, {2,3}, {3,4}, {3,4}, {5, 6}};

  auto iter_end = std::unique(coordinates.begin(), coordinates.end());

  coordinates.erase(iter_end, coordinates.end());
  coordinates.shrink_to_fit();


};

}  // namespace test
