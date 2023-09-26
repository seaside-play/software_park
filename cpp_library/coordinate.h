#pragma once
#include <cmath>

namespace test
{
	struct Coordinate
	{
		Coordinate() = default;
		Coordinate(int x, int y)
			: x_(x), y_(y) {}
		int x_;
		int y_;

		constexpr bool operator<(const Coordinate& rhs) const
		{
			if (x_ < rhs.x_)
				return true;
			else if (x_ == rhs.x_ && y_ < rhs.y_)
				return true;
			else
				return false;
		}

		bool operator==(const Coordinate& rhs)
		{
			return std::abs(x_ - rhs.x_) <= 1 && std::abs(y_ - rhs.y_) <= 1;
		}
	};
}