#include "Point.h"
#include <cmath>

using std::string;

Point::Point()
{
    latitude = longitude = 0;
}

Point::Point(string p_long, string p_lat)
{
    // Replace ',' by '.' to match floats
    int pos = p_lat.find(',');
    p_lat[pos] = '.';
    pos = p_long.find(',');
    p_long[pos] = '.';
    // Convert strings to double
    latitude = std::stod(p_lat);
    longitude = std::stod(p_long);
}

double Point::get_longitude() const
{
    return longitude;
}

double Point::get_latitude() const
{
    return latitude;
}

double Point::distance(const Point& a, const Point& b)
{
    double x = (b.longitude - a.longitude)
                * cos((a.latitude + b.latitude)
                / 2);
    double y = b.latitude - a.latitude;
    return (sqrt(pow(x,2) + pow(y,2)) * 6371);
}
