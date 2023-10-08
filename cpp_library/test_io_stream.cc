#include "test_io_stream.h"

#include <fstream>
#include <iomanip>
#include <iostream>

#include "base.h"
#include "test_chrono.h"


namespace test
{
	TestIOStream::TestIOStream()
	{}

	void TestIOStream::Run()
	{
		TestManipulator();
		TestFileExisted();
		TestCoutCache();
	}

	void TestIOStream::TestManipulator()
	{
		std::cout << "this function: " << __func__ << std::ends << " Hello World";
		std::cout << "I am in function " << __func__ << std::ends;
	}

	bool TestIOStream::TestFileExisted()
	{
		test::Tip(__func__);

		std::ifstream file("main.cpp", std::ios::in);
		auto ret = file.good();
		file.close();
		
		return ret;

		//auto open_flag = file.is_open();

	}

	void TestIOStream::TestCoutCache()
	{
		std::ofstream ofs("TestIOStream.txt");
		std::ios_base::sync_with_stdio(false);
		auto loop_count = 1000000;
		while (loop_count)
		{
			ofs << loop_count-- << std::endl;
		}

		ofs << std::endl;
		ofs.close();

	}
}
