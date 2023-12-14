#include "test_stl_algorithm.h"

#include <cmath>

#include <algorithm>
#include <array>
#include <iterator>
#include <iostream>
#include <map>
#include <numeric>
#include <random>
#include <set>
#include <string>
#include <unordered_map>
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
		TestHashObject();
		TestUnorderedMap();
		TestKVTable();
		TestBinarySearch();
		TestTransform();
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
	}

	void TestStlAlgorithm::TestHashObject()
	{
		//struct st
		//{
		//	int i;
		//};

		//st st1 = { 1 };
		//st st2 = { 1 };
		//std::hash<st> hash_st1;
		//std::hash<st> hash_st2;
		//size_t hash_val_st1 = hash_st1(st1);
		//size_t hash_val_st2 = hash_st2(st1);
	}
	
	void TestStlAlgorithm::TestUnorderedMap()
	{
		std::unordered_map<long long , int> index;

		int a = 1;
		int b = 2;
		long long c = (static_cast<long long>(a) << 32) + b;
		if (index.end() == index.find(c))
		{
			index.emplace_hint(index.end(), c, index.size());
		}

		auto value = index[1];
	}

	class mycomp2 {
	public:
		bool operator()(const Coordinate& point, const int& j) {
			return point.x_ > j;
		}
	};

	void TestStlAlgorithm::TestKVTable()
	{
		//std::vector<Coordinate> coordinates;
		//coordinates.reserve(10);
		//for (auto i = 0; i < 20; i+= 2)
		//{
		//	coordinates.emplace_back(i, i + 1);
		//}

		////bool ret = std::binary_search(coordinates.begin(), coordinates.end(), 10, [](decltype(*coordinates.begin()) coordinate, int base) {
		////		return coordinate.x_ > base; 
		////	});

		//bool ret = std::binary_search(coordinates.begin(), coordinates.end(), 10, mycomp2());

		// test 1 pass
		//std::vector<int> vi{1, 3, 5, 7, 9};
		//bool ret = std::binary_search(vi.begin(), vi.end(), 5, [](int a, int b) { return a > b; });

		// test2 
		std::vector<int> vi2{ 4,6, 19,14, 7,5,3,1,2 };
		bool ret = std::binary_search(vi2.begin(), vi2.end(), 3, [](int a, int b) { return a > b; }); // ����aΪ3����bΪ����element����
	}

	void TestStlAlgorithm::TestEqualRange()
	{
		std::vector<int> vi{1,2,3,4,6,8,9,10};
		auto iter = std::equal_range(std::begin(vi), std::end(vi), 2);
	}

	void TestStlAlgorithm::TestBinarySearch()
	{
		std::vector<int> vi{ 1,5,8,10,17,29,54,123, 1114, 5432, 8904, 10000 };
		auto ret = std::lower_bound(vi.cbegin(), vi.cend(), 29); // ���Ҳ��������ص�ȷ��54��
		std::cout << "ret: " << *ret << std::endl;

		std::map<int, int> m{ {1,1000}, {5, 2135}, {27, 30000}, {61, 45000} };
		//auto m_ret = std::lower_bound(m.cbegin(), m.cend(), std::make_pair<int, int>(5, 2135));

		auto lower_ret = m.lower_bound(8);

		auto ret1 = std::lower_bound(vi.cbegin(), vi.cend(), 30);
		std::cout << "ret1: " << *ret1 << std::endl;

		auto ret2 = std::upper_bound(vi.cbegin(), vi.cend(), 51);
		std::cout << "ret2: " << *ret2 << std::endl;

		auto ret3 = std::equal_range(vi.cbegin(), vi.cend(), 30); // ��ͬ˵��û���Ҽ���Ԫ��
		if (ret3.first == ret3.second)
			std::cout << "There are no 30 in vector" << std::endl;
		else
			std::cout << "Found 30 in vector" << std::endl;
	}

	void TestStlAlgorithm::TestTransform()
	{
		std::vector<int> vi{ 11, 12, 13, 14 };
		std::set<Coordinate> points{ {1,2}, {3,4}, {5,6}, {7,8} };

		std::unordered_map<size_t, size_t> m{ {1,1}, {2,2} };

		auto ret = m.emplace(1, 2);


		std::vector<int> vi2(vi.size());
		std::transform(vi.cbegin(), vi.cend(), vi2.begin(), [](int i) { return i * i; });
		
		std::string hello{ "Hello World!" };
		std::string hello_lower(hello.size(), ' ');
		std::transform(hello.cbegin(), hello.cend(), hello_lower.begin(), std::tolower);

	}
}