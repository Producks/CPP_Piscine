#include <cmath>
#include <iostream>
#include "Fixed.hpp"

Fixed::Fixed():fixed_value_(0){}

Fixed::Fixed(const Fixed& ref_class){
	*this = ref_class;
}

Fixed& Fixed::operator=(const Fixed& ref_class){
	fixed_value_ = ref_class.getRawBits();
	return *this;
}

Fixed::~Fixed(){}

Fixed::Fixed(const int number){
	fixed_value_ = (number << fractional);
}

Fixed::Fixed(const float number){
	fixed_value_ = fixed_value_ = static_cast<int>(roundf(number * (1 << fractional)));;
}

bool Fixed::operator>(const Fixed& ref_class) const{
	return fixed_value_ > ref_class.getRawBits();
}

bool Fixed::operator<(const Fixed& ref_class) const{
	return fixed_value_ < ref_class.getRawBits();
}

bool Fixed::operator>=(const Fixed& ref_class) const{
	return fixed_value_ >= ref_class.getRawBits();
}

bool Fixed::operator<=(const Fixed& ref_class) const{
	return fixed_value_ <= ref_class.getRawBits();
}

bool Fixed::operator==(const Fixed& ref_class) const{
	return fixed_value_ == ref_class.getRawBits();
}

bool Fixed::operator!=(const Fixed& ref_class) const{
	return fixed_value_ != ref_class.getRawBits();
}

Fixed Fixed::operator+(const Fixed& ref_class) const{
	Fixed result;

	result = (fixed_value_ + ref_class.getRawBits());
	return result;
}

Fixed Fixed::operator-(const Fixed& ref_class) const{
	Fixed result;

	result = (fixed_value_ - ref_class.getRawBits());
	return result;
}

Fixed Fixed::operator*(const Fixed& ref_class) const{
	Fixed result;

	result = (fixed_value_ * ref_class.getRawBits());
	return result;
}

Fixed Fixed::operator/(const Fixed& ref_class) const{
	Fixed result;

	result = (fixed_value_ / ref_class.getRawBits());
	return result;
}

int	Fixed::getRawBits(void) const{
	return fixed_value_;
}

void Fixed::setRawBits(int const rawBits){
	fixed_value_ = rawBits;
}

float Fixed::toFloat(void) const{
	return static_cast<float>(fixed_value_) / (1 << fractional);
}

int	Fixed::toInt(void) const{
	return (fixed_value_ >> fractional);
}

std::ostream& operator<<(std::ostream& out, const Fixed &ref_fixed)
{
	out << ref_fixed.toFloat();
	return out;
}