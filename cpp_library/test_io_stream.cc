#include "test_io_stream.h"

#include <fstream>
#include <iomanip>
#include <iostream>

#include "base.h"

namespace test
{
	TestIOStream::TestIOStream()
	{}

	void TestIOStream::Run()
	{
		TestManipulator();
		TestFileExisted();
	}

	void TestIOStream::TestManipulator()
	{
		std::cout << "this function: " << __func__ << std::ends << " Hello World";
		std::cout << "I am in function " << __func__ << std::ends;
	}

	bool TestIOStream::TestFileExisted()
	{
		utils::Tip(__func__);

		std::ifstream file("main.cpp", std::ios::in);
		auto ret = file.good();
		file.close();
		
		return ret;

		//auto open_flag = file.is_open();

	}
}
