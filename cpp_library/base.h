#pragma once

#include <string>


namespace test
{

	void Tip(const std::string& message);
	long long GetHashId(int x, int y);

}

namespace mars
{
	class Tool
	{
	public:
		explicit Tool(int number) : number_(number){}

	private:
		int number_;
	};
}
