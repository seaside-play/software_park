#pragma once

namespace test
{
	class TestIOStream
	{
	public:
		TestIOStream();

		void Run();

	private:
		void TestManipulator();
		bool TestFileExisted();
		void TestCoutCache();
	};
}


