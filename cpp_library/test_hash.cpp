#include "test_hash.h"
#include <functional>
#include <tuple>
#include <type_traits>
#include <iostream>
#include <unordered_map>

namespace test
{

	void TestHash::Test()
	{
		TupleHash();
	}

	void TestHash::TupleHash()
	{
		int a = 10, b = 20, c = 30;
		//std::unordered_map<std::tuple<int, int, int>, int> my_map;
		//my_map.insert(std::make_tuple(a, b, c), 1);
		std::cout << "The hash value of (a, b, c) is: " << std::hash<int>()(1) << std::endl;
	}

	
}
