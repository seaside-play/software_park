#pragma once


namespace test
{

	class TestIterator
	{
	public:
		void Test();

	private:
		void TestAdvance(); // ���ڽ�������ǰ�������ߺ��ˣ�ָ�����ȵľ���
		void TestDistance(); // ���ڼ���������������ʾ�ķ�Χ�ڰ���Ԫ�صĸ���
		void TestPrev(); // ������ȡһ������ָ�������� n ��Ԫ�صĵ�����
		void TestNext(); // ������ȡһ������ָ�������� n ��Ԫ�صĵ�����

		void TestBeginAndEnd(); //begin() / end()���õ�ĳ�����е��ס�β������
	};

}

