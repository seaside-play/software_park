#pragma once

#include <vector>
#include <string>


namespace test
{


	class TestPerformance
	{
	public:
		template<typename T>
		using Points = std::vector<std::pair<T, T>>;
		void Test();

	private:
		void TestMapKey();

		void TestShift(const Points<int>& points);
		void TestStringConnect(const Points<std::string>& points);

		void TestLoop();

	};

}