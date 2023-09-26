#include "test_stl_algorithm.h"

#include <algorithm>
#include <map>
#include <vector>
#include <set>
#include <string>

#include "coordinate.h"

// Test Performance

namespace test
{

	void TestStlAlgorithm::Test()
	{
		TestPermutation();
		TestSetCompAndIncludes();
		TestRangFor();
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

	void TestStlAlgorithm::TestSetCompAndIncludes()
	{
		auto OrderData = [](const Points<int>& points) -> std::set<Coordinate> {
			std::set< Coordinate> data;
			for (auto& point : points)
				data.insert(Coordinate(point.first, point.second));

			return data;
		};

		auto data1 = OrderData({ {1,3}, {2, 5}, {3, 4},{3, 6}, {3, 3} });
		auto data2 = OrderData({ {2, 5}, {3, 6}, {3, 3} });

		auto ret = std::includes(data1.cbegin(), data1.cend(), data2.cbegin(), data2.cend());
	}

	void TestStlAlgorithm::TestRangFor()
	{
		std::set<int> s1 {1, 3, 5, 7, 9, 11, 13, 15, 17};
		std::set<int> s2 {2, 4, 6, 8, 10, 12, 14, 16, 18};
		
		std::map<int, std::set<int>> list;
		list[11] = s1;
		list[12] = s2;

		for (const auto& list_item : list)
		{
			auto iter = list_item.second.begin();
			while (iter != list_item.second.end())
			{
				if (*iter == 11)
				{
					iter = list[list_item.first].erase(iter);
				}
				else
				{
					++iter;
				}
				
			}
		}
	}
}

