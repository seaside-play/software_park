#include "tools.h"
#include <cmath>



double tools::IntersectionRadian(const Point& start_point, const Point& end_point)
{
	return std::atan2l(end_point.y - start_point.y, end_point.x - start_point.x);
}

double tools::DistanceBetweenPoint(const Point& start_point, const Point& end_point)
{
	return std::hypot(end_point.y - start_point.y, end_point.x - start_point.x);
}

Point tools::RawEndPoint(const Point& start_point, const Point& end_point)
{
	auto angle = IntersectionRadian(start_point, end_point);
	auto angle2 = angle * 180 / kPi;
	auto dist = DistanceBetweenPoint(start_point, end_point);

	// todo
	auto rotate_x = std::cos(angle) * dist;
	auto rotate_y = std::sin(angle) * dist;
	
	auto ret = dist / std::cos(angle);
	return { start_point.x + ret, start_point.y };
}
