#pragma once

struct Point
{
	explicit Point(double x = 0, double y = 0)
			: x(x), y(y) {}

	double x;
	double y;

	void shift(double x, double y);
};
