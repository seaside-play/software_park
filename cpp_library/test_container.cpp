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
		// ��
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

		// ��֤�����ʹ��vector����ʾ��ά���ݣ��ռ��ǲ������ģ�������Ϊһά����ʹ�á�
	}

	void TestContainer::TestCompressibleMatrixWithLinearVector()
	{
		std::string net(4, ' ');
	}

	// ����һ��std::function�� custom hash function
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
		����unordered_map���ԣ������ǲ���<key, value>��ʱ����Ҫ��ϣ�����ĺ��������key����hash����Ҫ���õȱȺ����ĺ�������ȷ������ļ�ֵ��û���ظ���
		Ȼ�����������Զ�������ʱ��c++��׼�Ⲣû�ж�Ӧ�Ĺ�ϣ�����͵ȱȺ����ĺ������������Ҫ�ֱ�����ǽ��ж��塣

����		��Ϊ���Ǻ�����������������ʵ�ʶ��巽����û�кܴ���
		�������߱�ǰ�߶���һ����������Ϊ�ȱȺ����ĺ�������Ĭ��ֵstd::equal_to<key>�ڲ���ͨ�����ò�����"=="���е�ֵ�жϣ�
		������ǿ���ֱ�����Զ������������operator==()���أ���Ա����Ԫ�����ԣ���

		���ȼ�Ҫ����һ�º������� (��һ���������ѽ���) �ĸ��
		�ڡ�C++ Primer Plus�����棬���������ǿ����Ժ�����ʽ��()���ʹ�õ��������
		�������������ָ������ָ��������ˡ�operator()��������������󡣻��ڴˣ������������3��������
		*/

		std::unordered_map<Person, int, std::function<size_t(const Person& p)>> ids(100, person_hash); //��Ҫ��person_hash���빹�캯��
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

	// Test�����vector�в���ʹ�����ã�vector��Ҫ���㸳ֵ�͸��ƣ������ò����и����ԣ� ���뱨��
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