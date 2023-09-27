#include "base.h"

#include <iostream>

namespace test
{

	void Tip(const std::string& message)
	{
		std::cout << "\ntesting " << message << "::" << std::endl;
	}

	long long GetHashId(int x, int y)
	{
		return (static_cast<long long>(x) << 32) + y;
	}

}
