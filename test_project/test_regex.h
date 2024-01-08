#pragma once

#include <string>

namespace test
{
	class TestRegex
	{
	public:
		void Test();

	private:
		size_t TestGetColumnCount();

		void TestStart();
		size_t ModifyInterator(std::string data);

	};
}

