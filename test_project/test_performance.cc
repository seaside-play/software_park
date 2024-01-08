#include "test_performance.h"

#include <algorithm>
#include <functional>
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
		//TestMapKey();
		TestLoop();
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
	}

	void TestPerformance::TestShift(const Points<int>& points)
	{
		test::TestChrono test_chrono(__func__);

		std::set<long long> data;
		for (auto& point : points)
		{
			data.insert(test::GetHashId(point.first, point.second));
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

	void TestPerformance::TestLoop()
	{
		auto loop_count = 1000000;
		auto count = 0;


		test::TestChrono test_chrono(__func__);
		for (auto i = 0; i < loop_count; ++i)
		{
			++count;
		}

		for (auto i = 0; i < loop_count; ++i)
		{
			++count;
		}
		
	}
	
}