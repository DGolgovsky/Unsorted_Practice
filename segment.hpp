#pragma once

#include "point.hpp"
#include <cmath>

struct Segment {
	Segment(Point p1, Point p2)
		: p1(p1), p2(p2)
	{}

	explicit Segment(double length)
		: p2(length, 0)
	{}

	Point p1;
	Point p2;

	double length();
};
