#include "test_array.h"
#include <cstdio>
#include <cstdlib>

#include <random>
#include <vector>

#include "coordinate.h"

namespace test
{

	void TestArray::Test()
	{
		TestTwoDimensionalArray();
		TestDynamicCreateTwoDimensionalArray();
	}

	void TestArray::TestTwoDimensionalArray()
	{
		const size_t rows = 4;
		const size_t cols = 2;
		int coordinate[rows][cols] = { {1,2}, {3,2}, {3,2}, {4,5} };
		int ret[4] = { 0 };

		BuildViaVirtualNetId(coordinate[0], ret, rows, cols);
	}

	void TestArray::BuildViaVirtualNetId(int* via_arr, int* ret, int rows, int cols)
	{
		for (int i = 0; i < rows; ++i)
		{
			for (int j = 0; j < cols; ++j)
			{
				ret[i] = via_arr[i * cols + 1];
			}
		}
	}

	// 创建二维动态数组，并保存从vector中所获得坐标点。
	void TestArray::TestDynamicCreateTwoDimensionalArray()
	{
		// 由于二维数组在内存中是连续的，可以利用malloc函数申请一步到位
		// 所以，可以直接申请一个长度为行数*列数的一维数组，输出是按行输出即可

		constexpr size_t rows = 4;
		constexpr size_t cols = 2;


		std::vector<Coordinate> vi(rows);
		int index = 0;
		for (auto& item : vi)
		{
			item.x_ = index++;
			item.y_ = index++;
		}

		int* coordinate_arr = (int*)malloc(sizeof(int) * rows * cols);
		for (int i = 0; i < rows; ++i)
		{
			coordinate_arr[i * cols] = vi[i].x_;
			coordinate_arr[i * cols + 1] = vi[i].y_;
		}

		int* ret = (int*)malloc(sizeof(int) * rows);
		for (int i = 0; i < rows; ++i)
			ret[i] = coordinate_arr[i*cols];


		free(coordinate_arr);
		coordinate_arr = nullptr;
		free(ret);
		ret = nullptr;

		vi.clear();
	}
}
