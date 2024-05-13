#include <iostream>
#include <limits>
#include <cmath>
#include <numeric>
#include <vector>


class A {
 public:
  int n{0};
};

int main(int argc, char** argv) {
  std::cout << "Hello World!\n";
  auto epsilon = std::numeric_limits<double>::epsilon();
  std::cout << "epsilon: " << epsilon << std::endl;

  double d1 = 0.000000001;
  double d2 = 0.0000000011;
  if (std::fabs(d1 - d2) < epsilon) {
    std::cout << "less epsilon\n";
  } else {
    std::cout << "great epsilon\n";
  }

  std::vector<int> numbers{1, 2, 3, 4};
  double avg = std::reduce(numbers.begin(), numbers.end(), 0.0, std::plus<double>()) / numbers.size();
  std::cout << "Average: " << avg << std::endl;

  const A* a = new A;
  A* b = new A;
  a = b;

  return 0;
}