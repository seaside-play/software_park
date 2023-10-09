#include "test_stl_algorithm.h"

#include <cmath>

#include <algorithm>
#include <iterator>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <string>
#include <unordered_set>
#include <vector>

#include "base.h"
#include "coordinate.h"

// Test Performance

namespace test
{

	void TestStlAlgorithm::Test()
	{
		TestPermutation();
		TestSetCompAndIncludes();
		TestRangFor();
		TestMyIncludes();
		TestAdjacentDifference();
		TestHashid();
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

		auto data1 = OrderData({ {1,31}, {2, 15}, {3, 14},{3, 16}, {3, 13} });
		auto data2 = OrderData({ {2, 15}, {3, 15}, {3, 13} });

		auto ret = std::includes(data1.cbegin(), data1.cend(), data2.cbegin(), data2.cend());
	}

	void TestStlAlgorithm::TestMultiSetCompAndIncludes()
	{
	}

	void TestStlAlgorithm::TestMyIncludes()
	{
		//auto OrderData = [](const Points<int>& points) -> std::set<Coordinate> {
		//	std::set< Coordinate> data;
		//	for (auto& point : points)
		//		data.insert(Coordinate(point.first, point.second));

		//	return data;
		//};

		//auto data1 = OrderData({ {1, 31}, {2, 15}, {3, 13} });
		//auto data2 = OrderData({ {2, 17} });

		std::vector<int> data1 = {1,3,7,19,81,113};
		std::vector<int> data2 = {4,8};

		auto ret = std::includes(data1.begin(), data1.end(), data2.begin(), data2.end());
	
		auto ret1 = Includes(data1.begin(), data1.end(), data2.begin(), data2.end(), 
			                 [](const int& lhs, const int& rhs) -> bool {
								auto dif = std::abs(lhs - rhs);
								auto ret = dif <= 1;
								return ret;
							 });
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

	void TestStlAlgorithm::TestAdjacentDifference()
	{
		std::vector<int> v1{ 1,37, 48, 78, 79,102, 245 };
		std::vector<int> dst;

		std::adjacent_difference(v1.begin(), v1.end(), std::inserter(dst, dst.begin()), [](int lhs, int rhs) {
			return lhs - rhs;
			});
	}

	void TestStlAlgorithm::TestHashid()
	{
		Tip(__func__);

		std::hash<double> hash1;
		std::hash<double> hash2;

		double d1 = 1.1;
		double d2 = 1.100;

		size_t hash_val1 = hash1(d1);
		size_t hash_val2 = hash2(d2);
		if (hash_val1 == hash_val2)
			std::cout << "hash id is same." << std::endl;
		else
			std::cout << "hash id is not same." << std::endl;

		//////////

		struct st
		{
			int i;
		};

		st st1 = { 1 };
		st st2 = { 1 };
		std::hash<st> hash_st1;
		std::hash<st> hash_st2;
		size_t hash_val_st1 = hash_st1(st1);
		size_t hash_val_st2 = hash_st2(st1);

	}
}