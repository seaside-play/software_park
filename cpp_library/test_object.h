#pragma once

//#include "base.h"

namespace test
{

	//class mars::Tool;

	class TestObject
	{
		friend class Tool;

	public:
		void Test();

	private:
		int tools_count_{ 10 };
	};

}

