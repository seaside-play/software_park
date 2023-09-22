#include "test_stl_algorithm.h"
#include <algorithm>
#include <vector>
#include <string>


// Test Performance

namespace test
{

	void TestStlAlgorithm::Test()
	{
		TestPermutation();
	}

	void TestStlAlgorithm::TestPermutation()
	{
		std::vector<int> vi{1, 2, 3, 5, 6, 7};
		std::vector<int> vi2{3, 1, 2, 6, 5, 7};
		std::vector<int> vi3{ 2, 4, 6, 10, 12, 14 };
		std::vector<int> vi4{5, 7, 13, 15,16, 17};

		auto ret = std::is_permutation(vi.cbegin(), vi.cend(), vi2.cbegin());
		auto ret2 = std::is_permutation(vi.cbegin(), vi.cend(), vi3.cbegin(), [](auto lhs, auto rhs) {
			return lhs * 2 == rhs;
			});
	}

}

