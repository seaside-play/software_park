#pragma once

#include <array>

#include "gtest/gtest.h"
#include "test_question.h"


int Foo(int a, int b)
{
	if (a == 0 || b == 0)
	{
		throw "don't do that";
	}
	int c = a % b;
	if (c == 0)
		return b;

	return Foo(b, c);
}

TEST(FooTest, HandleNoneZeroInput)
{
	EXPECT_EQ(2, Foo(4, 10));
	EXPECT_EQ(6, Foo(30, 18));
}

TEST(PopStackReasonableTest, IsPopStackReasonable)
{
	test::TestQuestion test_question;
	
	//std::array<int, 5> order_list{1,2,3,4,5};
	//std::array<int, 5> pop_list{4,5,3,2,1};
	//EXPECT_TRUE(test_question.IsPopStackReasonable(order_list.data(), pop_list.data(), 5));

	std::array<int, 5> order_list1{ 1,2,3,4,5 };
	std::array<int, 5> pop_list1{ 4,5,3,1,2 };
	EXPECT_FALSE(test_question.IsPopStackReasonable(order_list1.data(), pop_list1.data(), 5));
}

