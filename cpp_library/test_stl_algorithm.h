#pragma once

#include <cmath>
#include <memory>
#include <vector>

#include "coordinate.h"

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
		void TestMultiSetCompAndIncludes();
		void TestRangFor();

		void TestMyIncludes();

		template<class Iter1, class Iter2, class Pre>
		bool Includes(Iter1 first1, Iter1 last1, Iter2 first2, Iter2 last2, Pre pre);

		void TestAdjacentDifference();

	};

	template<class Iter1, class Iter2, class Pre>
	bool TestStlAlgorithm::Includes(Iter1 first1, Iter1 last1, Iter2 first2, Iter2 last2, Pre pre)
	{
		while (first1 != last1 && first2 != last2)
		{
			if (!pre(*first1, *first2))
				++first1;
			else
				++first2;
		}

		return first2 == last2;
	}


}

