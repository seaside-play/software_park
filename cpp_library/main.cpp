#include "test_case_question.h"
#include "test_container.h"
#include "test_io_stream.h"
#include "test_iterator.h"
#include "test_math.h"
#include "test_performance.h"
#include "test_question.h"
#include "test_regex.h"
#include "test_set_operator.h"
#include "test_stl_algorithm.h"
#include "test_array.h"

#include "gtest/gtest.h"


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

	test::TestPerformance test_performance;
	test_performance.Test();

	test::TestMath test_math;
	test_math.Test();
	
	test::TestIterator test_iterator;
	test_iterator.Test();

	test::TestContainer test_container;
	test_container.Test();

	test::TestArray test_array;
	test_array.Test();

	test::TestQuestion test_question;
	test_question.Test();

	return 0;
}