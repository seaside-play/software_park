#include "test_performance.h"

#include <algorithm>
#include <iterator>
#include <iostream>
#include <memory>
#include <random>
#include <set>
#include <vector>

#include "test_chrono.h"
#include "base.h"


namespace test
{

	void TestPerformance::Test()
	{
		TestMapKey();
	}

	// 生成100万个坐标点
	void TestPerformance::TestMapKey()
	{
		std::default_random_engine dre;
		std::uniform_int_distribution<int> uid(10, 10000000);
		
		auto max_point_count = 1000000;
		Points<int> points(max_point_count);
		Points<std::string> str_points(max_point_count);
		for (auto i = 0; i < max_point_count; ++i)
		{
			auto x = uid(dre);
			auto y = uid(dre);
			points.at(i) = std::move(std::pair<int, int>(x, y));
			str_points.at(i) = std::move(std::make_pair<std::string, std::string>(std::to_string(x), std::to_string(y)));
		}

		TestShift(points);
		TestStringConnect(str_points);

		Points<int> test{ {1,3}, {2, 5}, {3, 4},{3, 6}, {3, 3} };
		TestSetComp(test);
	}

	void TestPerformance::TestShift(const Points<int>& points)
	{
		test::TestChrono test_chrono(__func__);

		std::set<long long> data;
		for (auto& point : points)
		{
			data.insert(utils::GetHashId(point.first, point.second));
		}
	}
		
	void TestPerformance::TestStringConnect(const Points<std::string>& points)
	{
		test::TestChrono test_chrono(__func__);

		std::set<std::string> data;
		for (auto& point : points)
		{
			data.insert(point.first + point.second);
		}
	}

	void TestPerformance::TestSetComp(const Points<int>& points)
	{
		struct Comp
		{
			constexpr bool operator()(const Coordinate& lhs, const Coordinate& rhs) const
			{
				if (lhs.x_ < rhs.x_)
					return true;
				else if (lhs.x_ == rhs.x_ && lhs.y_ < rhs.y_)
					return true;
				else
					return false;
			}
		};


		test::TestChrono test_chrono(__func__);

		std::set< Coordinate, Comp > data;
		for (auto& point : points)
			data.insert(Coordinate(point.first, point.second));
	}
	
}