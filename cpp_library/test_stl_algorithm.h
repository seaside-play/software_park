#pragma once

#include <memory>
#include <vector>

namespace test
{

	class TestStlAlgorithm
	{
	public:
		template<typename T>
		using Points = std::vector<std::pair<T, T>>;

		void Test();

	private:
		void TestPermutation();
		void TestSetCompAndIncludes();
		void TestRangFor();

	};

}

