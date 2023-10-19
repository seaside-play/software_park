#include "test_container.h"

#include <algorithm>
#include <functional>
#include <iostream>
#include <map>
#include <memory>
#include <string>
#include <unordered_map>
#include <vector>
#include <type_traits>

#include "coordinate.h"

namespace test
{
	void TestContainer::Test()
	{
		TestUnorderMap();
		TestVector();
		TestCompressibleMatrixWithVectorInVector();
		TestCompressibleMatrixWithLinearVector();
		TestUnordermapHash();
		TestUnorderedMapSort();
		TestContainerRef();
	}

	void TestContainer::TestUnorderMap()
	{
		// 在
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

		std::vector<int> vi2;
		vi2.reserve(35);
		vi2.push_back(1);
		vi2.shrink_to_fit();


		std::vector<Coordinate> coordinate_points;
		coordinate_points.reserve(50);
		for (int i = 0; i < 10; i += 2)
		{
			coordinate_points.emplace_back(Coordinate(i, i + 1));
		}
		coordinate_points.shrink_to_fit();

		auto iter = coordinate_points.begin();
		int* data = &iter->x_;


		//auto is_pod = std::is_pod<Coordinate>::value; // in C++20 deprecated
	}

	void TestContainer::TestCompressibleMatrixWithVectorInVector()
	{
		// 4 1 2 3 4 3 6 1 2 3 4 5 6 1
		struct Polygon
		{
			int count;
			std::vector<int> indexs;
			int layer_id;
		};

		std::vector<Polygon> polygons;

		Polygon polygon1;
		polygon1.count = 4;
		polygon1.indexs = { 1, 2,3,4 };
		polygon1.layer_id = 3;
		polygons.emplace_back(std::move(polygon1));

		Polygon polygon2;
		polygon2.count = 6;
		polygon2.indexs = { 11, 12, 13, 14, 15, 16};
		polygon2.layer_id = 1;
		polygons.emplace_back(std::move(polygon2));


		using LinearArray = std::vector<int>;
		using CompressArray = std::vector<LinearArray>;

		CompressArray compress_array;
		compress_array.reserve(polygons.size());

		for (const auto& polygon : polygons)
		{
			LinearArray linear_array;
			
			linear_array.reserve(polygon.count + 2);
			linear_array.push_back(polygon.count);
			for (auto index : polygon.indexs)
				linear_array.push_back(index);

			linear_array.push_back(polygon.layer_id);

			compress_array.emplace_back(std::move(linear_array));
		}

		auto pol1 = &compress_array[0][0];
		auto pol2 = &compress_array[1][0];

		// 验证结果：使用vector来表示二维数据，空间是不连续的，不能作为一维数据使用。
	}

	void TestContainer::TestCompressibleMatrixWithLinearVector()
	{
		std::string net(4, ' ');
	}

	// 方法一：std::function， custom hash function
	class Person {
	public:
		std::string name;
		int age;

		Person(std::string n, int a) {
			name = n;
			age = a;
		}
		bool operator==(const Person& p) const
		{
			return name == p.name && age == p.age;
		}
	};

	size_t person_hash(const Person& p)
	{
		return std::hash<std::string>()(p.name) ^ std::hash<int>()(p.age);
	}

	void TestContainer::TestUnordermapHash()
	{
		/*
		对于unordered_map而言，当我们插入<key, value>的时候，需要哈希函数的函数对象对key进行hash，又要利用等比函数的函数对象确保插入的键值对没有重复。
		然而，当我们自定义类型时，c++标准库并没有对应的哈希函数和等比函数的函数对象。因此需要分别对它们进行定义。

　　		因为都是函数对象，它们两个的实际定义方法并没有很大差别。
		不过后者比前者多了一个方法。因为等比函数的函数对象默认值std::equal_to<key>内部是通过调用操作符"=="进行等值判断，
		因此我们可以直接在自定义类里面进行operator==()重载（成员和友元都可以）。

		首先简要介绍一下函数对象 (在一、二部分已介绍) 的概念：
		在《C++ Primer Plus》里面，函数对象是可以以函数方式与()结合使用的任意对象。
		这包括函数名、指向函数的指针和重载了“operator()”操作符的类对象。基于此，我们提出以上3个方法。
		*/

		std::unordered_map<Person, int, std::function<size_t(const Person& p)>> ids(100, person_hash); //需要把person_hash传入构造函数
		ids[Person("Mark", 17)] = 40561;
		ids[Person("Andrew", 16)] = 40562;
		for (auto ii = ids.begin(); ii != ids.end(); ii++)
			std::cout << ii->first.name;
	}

	void TestContainer::TestUnorderedMapSort()
	{
		std::multimap<int, std::string> employee{ {2, "wu"}, {2, "chaojiang"}, {1, "Chris"}, {6, "Andrew Koenig"} };

		auto iter = employee.equal_range(2);
		while (iter.first != iter.second)
		{
			std::cout << "name : " << iter.first->first << " : " << iter.first->second << std::endl;
			iter.first++;
		}

		// #TODO Have problem
		//auto iter2 = std::equal_range(std::begin(employee), std::end(employee), 2);
	}

	// Test结果，vector中不能使用引用，vector需要满足赋值和复制，而引用不具有该特性， 编译报错。
	void TestContainer::TestContainerRef()
	{
		std::vector<std::string> vst{"Hello", "World"};


		//std::vector<std::string&> vstr_ref;
		//for (const auto& item : vst)
		//{
		//	//vstr_ref.emplace_back(item);
		//}

		//vst.front().append(" Chris");

		//std::cout << "vstr_ref front data: " << vstr_ref.front() << std::endl;
	}

} 