#include "test_chrono.h"
#include <chrono>
#include <iostream>

namespace test
{

	TestChrono::TestChrono()
	{
		StartTime();
	}

	TestChrono::TestChrono(const std::string& str)
		: message_(str)
	{
		StartTime();
	}

	TestChrono::~TestChrono()
	{
		StopTime();
	}

	void TestChrono::Test()
	{
	
	}

	void TestChrono::StartTime()
	{
		start_ = tm::system_clock::now();
	}

	void TestChrono::StopTime()
	{
		end_ = tm::system_clock::now();

		std::cout << " Testing " << message_ << " uses duration milliseconds " << std::chrono::duration_cast<tm::milliseconds>(end_ - start_).count() << std::endl;
	}

}
