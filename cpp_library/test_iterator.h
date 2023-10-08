#pragma once


namespace test
{

	class TestIterator
	{
	public:
		void Test();

	private:
		void TestAdvance(); // 用于将迭代器前进（或者后退）指定长度的距离
		void TestDistance(); // 用于计算两个迭代器表示的范围内包含元素的个数
		void TestPrev(); // 用来获取一个距离指定迭代器 n 个元素的迭代器
		void TestNext(); // 用来获取一个距离指定迭代器 n 个元素的迭代器

		void TestBeginAndEnd(); //begin() / end()：得到某个序列的首、尾迭代器
	};

}

