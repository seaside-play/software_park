#include "main.h"
#include "test_io_stream.h"
#include "test_set_operator.h"
#include "test_stl_algorithm.h"
#include "test_regex.h"

#include "gtest/gtest.h"


int Foo(int a, int b);

TEST(FooTest, HandleNoneZeroInput)
{
	EXPECT_EQ(2, Foo(4, 10));
	EXPECT_EQ(6, Foo(30, 18));
}



int main(int argc, char** argv)
{
	::testing::InitGoogleTest(&argc, argv);
	RUN_ALL_TESTS();

	test::TestIOStream test_io_stream;
	test_io_stream.Run();

	test::TestSetOperator test_set_operator;
	test_set_operator.Test();

	test::TestStlAlgorithm test_algorithm;
	test_algorithm.Test();

	test::TestRegex test_regex;
	test_regex.Test();


	return 0;
}

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