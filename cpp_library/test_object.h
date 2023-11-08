#pragma once

//#include "base.h"

namespace test
{

	//class mars::Tool;
	struct Base
	{};

	struct Derived1 : Base {};
	struct Derived2 : Base {};


	class TestObject
	{
		friend class Tool;

	public:
		TestObject();
		void Test();

	private:
		int tools_count_{ 10 };

	private:
		Base* base_;
	};

}

