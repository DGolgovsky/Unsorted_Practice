#pragma once
#include <string>

class Point
{
private:
	double longitude;
	double latitude;
public:
	Point();
    Point(std::string p_long, std::string p_lat);
    double get_longitude() const;
    double get_latitude() const;
    static double distance(const Point& a, const Point& b);
};
