#pragma once

#include <chrono>
#include <string>

namespace test
{
	namespace tm = std::chrono;

	class TestChrono
	{
	public:
		TestChrono();
		TestChrono(const std::string& str);
		~TestChrono();

		void Test();

	private:
		void StartTime();
		void StopTime();

	private:
		tm::time_point<tm::system_clock> start_;
		tm::time_point<tm::system_clock> end_;
		std::string message_;
	};


}
