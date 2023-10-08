#include "test_iterator.h"

#include <iostream>
#include <list>
#include <vector>

#include "base.h"


/*
 std::advance: �Ǹı䵱ǰ����������������ʾ��x�᷽��ǰ����������ʾ��x�Ḻ�᷽��
 std::prev����ǰ���������䣬���ǻ��һ���µĵ�������Ĭ��Ϊ��ԭ���߹��ķ���ǰ�У���ֵʱ�����Ǹ�ֵ�����������壬����ʹ��next����ʾ��һ����
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
	}

	void TestIterator::TestAdvance() // ���ڽ�������ǰ�������ߺ��ˣ�ָ�����ȵľ���
	{
		test::Tip(__func__);
		std::vector<int> v{ 1,2,3,4 };
		auto it = v.cbegin();
		std::advance(it, 2);
		std::cout << "it + 2: " << *it << std::endl; // it + 2: 3
	}

	void TestIterator::TestDistance() // ���ڼ���������������ʾ�ķ�Χ�ڰ���Ԫ�صĸ���
	{
	}

	void TestIterator::TestPrev() // ������ȡһ������ָ�������� n ��Ԫ�صĵ�����
	{
		Tip(__func__);
		//��������ʼ��һ�� list ����
		std::list<int> mylist{ 1,2,3,4,5 };
		std::list<int>::iterator it = mylist.end();

		auto beg = mylist.cbegin();
		//��ȡһ������ it ������ 2 ��Ԫ�صĵ����������� 2 Ϊ������newit λ�� it ���
		auto newit = prev(it, 2);

		std::cout << "prev(it, 2): " << *newit << std::endl;

		std::cout << "*pre(beg, -2): " << *std::prev(beg, -2) << std::endl;
	}

	void TestIterator::TestNext() // ������ȡһ������ָ�������� n ��Ԫ�صĵ�����
	{

	}

	void TestIterator::TestBeginAndEnd()
	{

	}

}