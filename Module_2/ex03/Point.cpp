#include "Fixed.hpp"
#include "Point.hpp"

Point::Point():x_axis(Fixed(0)), y_axis(Fixed(0)){}

Point::Point(const Point& rhs) : x_axis(rhs.x_axis), y_axis(rhs.y_axis) {}

Point& Point::operator=(const Point& rhs){
	std::cout << "🤡 Can't use this operator bozo 🤡" << std::endl;
	return *this;
}

Point::~Point(){}

Point::Point(const float x_val, const float y_val):x_axis(Fixed(x_val)), y_axis(Fixed(y_val)){}
 
const Fixed& Point::getX() const{
	return x_axis;
}

const Fixed& Point::getY() const{
	return y_axis;
}