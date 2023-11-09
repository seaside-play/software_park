#include "test_iterator.h"

#include <iostream>
#include <list>
#include <vector>

#include "base.h"


/*
 std::advance: 是改变当前迭代器本身，正数表示向x轴方向前进，负数表示向x轴负轴方向；
 std::prev：当前迭代器不变，而是获得一个新的迭代器，默认为向原先走过的方向前行，正值时。若是负值，容易有歧义，建议使用next，表示下一步。
 std::next:

*/

namespace test
{

	void TestIterator::Test()
	{
		TestAdvance();
		TestDistance();
		TestPrev();
		TestNext();
		TestBeginAndEnd();
		TestArrayIterator();
	}

	void TestIterator::TestAdvance() // 用于将迭代器前进（或者后退）指定长度的距离
	{
		test::Tip(__func__);
		std::vector<int> v{ 1,2,3,4 };
		auto it = v.cbegin();
		std::advance(it, 2);
		std::cout << "it + 2: " << *it << std::endl; // it + 2: 3
	}

	void TestIterator::TestDistance() // 用于计算两个迭代器表示的范围内包含元素的个数
	{
		std::vector<int> vi{ 1,2,3,4,5,6,7};
		auto diff = std::distance(vi.begin(), vi.end());
	}

	void TestIterator::TestPrev() // 用来获取一个距离指定迭代器 n 个元素的迭代器
	{
		Tip(__func__);
		//创建并初始化一个 list 容器
		std::list<int> mylist{ 1,2,3,4,5 };
		std::list<int>::iterator it = mylist.end();

		auto beg = mylist.cbegin();
		//获取一个距离 it 迭代器 2 个元素的迭代器，由于 2 为正数，newit 位于 it 左侧
		auto newit = prev(it, 2);

		std::cout << "prev(it, 2): " << *newit << std::endl;

		std::cout << "*pre(beg, -2): " << *std::prev(beg, -2) << std::endl;
	}

	void TestIterator::TestNext() // 用来获取一个距离指定迭代器 n 个元素的迭代器
	{

	}

	void TestIterator::TestBeginAndEnd()
	{

	}

	void TestIterator::TestArrayIterator()
	{
		int virtual_net_id[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
		int* virtual_net_id_result = virtual_net_id;
		int count = sizeof(virtual_net_id) / sizeof(int);

		std::vector<int> vi(count);

		for (auto i = 0; i < count; ++i)
		{
			vi.at(i) = *virtual_net_id_result++;
		}
	}


}