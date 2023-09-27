#pragma once

namespace test
{

	class TestQuestion
	{
	public:
		void Test();

		bool IsPopStackReasonable(int* order_list, int* pop_list, int count);
		void PrintBinaryTreeByOrder();
		void PrintBinaryTreeByLine();
		void PrintBinaryTreeByZ();
	};

}


