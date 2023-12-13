#include "gtest/gtest.h"
#include "test_abseil.h"
#include "test_array.h"
#include "test_basic.h"
#include "test_case_question.h"
#include "test_ckt.h"
#include "test_container.h"
#include "test_cpp17.h"
#include "test_hash.h"
#include "test_io_stream.h"
#include "test_iterator.h"
#include "test_ltcd.h"
#include "test_math.h"
#include "test_msg_queue.h"
#include "test_object.h"
#include "test_performance.h"
#include "test_question.h"
#include "test_regex.h"
#include "test_set_operator.h"
#include "test_stl_algorithm.h"
#include "test_honer.h"

int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	RUN_ALL_TESTS();

	//test::TestIOStream test_io_stream;
	//test_io_stream.Run();

	//test::TestSetOperator test_set_operator;
	//test_set_operator.Test();

	//test::TestStlAlgorithm test_algorithm;
	//test_algorithm.Test();

	//test::TestRegex test_regex;
	//test_regex.Test();

	//test::TestPerformance test_performance;
	//test_performance.Test();

	//test::TestMath test_math;
	//test_math.Test();
	//
	//test::TestIterator test_iterator;
	//test_iterator.Test();

	//test::TestContainer test_container;
	//test_container.Test();

	//test::TestArray test_array;
	//test_array.Test();

	//test::TestQuestion test_question;
	//test_question.Test();

	//test::TestCpp17 test_cpp17;
	//test_cpp17.Test();

  //test::TestIOStream test_io_stream;
  //test_io_stream.Run();

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

  test::TestCpp17 test_cpp17;
  test_cpp17.Test();

 // test::TestLtcd test_ltcd;
 // test_ltcd.Test();

 // test::TestAbseil test_abseil;
 // test_abseil.Test();

 // test::TestHash test_hash;
 // test_hash.Test();

 // test::TestObject test_object;
 // test_object.Test();

 // test::TestCkt test_ckt;
 // test_ckt.Test();

  test::TestBasic test_basic;
  test_basic.Test();

  test::TestMsgQueue test_msg_queue;
  test_msg_queue.Test();

  test::TestHoner test_honer;
  test_honer.Test();

  system("pause");

  return 0;
}