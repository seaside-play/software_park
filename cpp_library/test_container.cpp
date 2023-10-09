#include "test_container.h"

#include <iostream>
#include <memory>
#include <unordered_map>

namespace test
{
	void TestContainer::Test()
	{
		TestUnorderMap();
		TestVector();
	}

	void TestContainer::TestUnorderMap()
	{
		// дк
		using Vi = std::vector<int>;
		Vi v1{1,2,3,4,5,6};

		std::unordered_map<int, Vi> um;
		um[1] = v1;

		for (const auto& item : um)
		{
			auto first = item.first;
			auto second = item.second;
			for (const auto& i : second)
			{
				std::cout << "i: " << i << std::endl;
			}
		}
	}

	void TestContainer::TestVector()
	{
		std::vector<int> vi(8);
		auto outline_points = std::make_shared<std::vector<int>>(9);
	}
}