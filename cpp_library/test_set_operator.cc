#include "test_set_operator.h"

#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

#include "base.h"

namespace test
{
	void TestSetOperator::Test()
	{
		utils::Tip(__func__);
		TestInclude();
	}

	void TestSetOperator::TestInclude()
	{
		utils::Tip(__func__);
		std::vector<int> vi{ 1, 5, 7, 8, 10, 43, 97 };
		std::vector<int> vi2{ 7, 8, 97 };

		auto ret = std::includes(vi.cbegin(), vi.cend(), vi2.cbegin(), vi2.cend());
		if (ret)
			std::cout << "vi includes vi2" << std::endl;
		else
			std::cout << "vi not includes vi2" << std::endl;
	}
}