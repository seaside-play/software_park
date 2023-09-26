#include "test_question.h"

#include <stack>

namespace test
{

	void TestQuestion::Test()
	{

	}

	bool TestQuestion::IsPopStackReasonable(int* order_list, int* pop_list, int count)
	{
		if (order_list == nullptr || pop_list == nullptr || count < 1)
			return false;

		auto order_list_end = order_list + count;
		auto pop_list_end = pop_list + count;

		std::stack<int> stack;
		stack.push(*order_list);
		++order_list;

		while (!stack.empty())
		{
			if (stack.top() != *pop_list)
			{
				if (order_list == order_list_end) // 表示已经找完了顺序序列，没有数据可压栈了，不能匹配
					break;

				stack.push(*order_list);
				++order_list;
			}
			else
			{
				stack.pop();
				++pop_list;
			}
		}

		return stack.empty() ? true : false;
	}

	void TestQuestion::PrintBinaryTree()
	{

	}
}