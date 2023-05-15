#include "Fixed.hpp"
#include "Point.hpp"

Point::Point():_x(Fixed(0)), _y(Fixed(0)){}

Point::Point(const Point& classRef): _x(classRef._x), _y(classRef._y){}

Point& Point::operator=(const Point& classRef){} // fix later

Point::~Point(){}

Point::Point(const float x_val, const float y_val):_x(Fixed(x_val)), _y(Fixed(y_val)){}