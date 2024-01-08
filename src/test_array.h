#pragma once

namespace test
{
	class TestArray
	{
	public:
		void Test();

	private:
		void TestTwoDimensionalArray();
		void TestDynamicCreateTwoDimensionalArray();

		void BuildViaVirtualNetId(int* via_arr, int* ret, int rows, int cols);

		void TestPointer(int* pt);

	};

}

