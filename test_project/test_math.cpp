#include "test_math.h"

#include <cmath>

namespace test
{
	void TestMath::Test()
	{
		TestRound();
		TestCeil();
	}

	void TestMath::TestRound()
	{
		int n1 = 209;
		int n2 = std::round(n1 / 9.0);
	}

	void TestMath::TestCeil()
	{
		double d1 = 19.9;
		double d2 = 20.0;

		int n1 = static_cast<int>(std::ceil(d1));
		int n2 = static_cast<int>(std::ceil(d2));
	}
}