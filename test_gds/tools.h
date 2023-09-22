#pragma once

const long double kPi = 3.14159265358979323846;
				   

struct Point
{
	double x;
	double y;
};

class tools
{
public:
	static double IntersectionRadian(const Point& start_point, const Point& end_point);
	static double DistanceBetweenPoint(const Point& start_point, const Point& end_point);
	static Point RawEndPoint(const Point& start_point, const Point& end_point);
};

