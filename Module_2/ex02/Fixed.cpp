#include <cmath>
#include <iostream>
#include "Fixed.hpp"

Fixed::Fixed():fixed_number_(0){}

Fixed::Fixed(const Fixed& rhs){
	*this = rhs;
}

Fixed& Fixed::operator=(const Fixed& rhs){
	fixed_number_ = rhs.getRawBits();
	return *this;
}

Fixed::~Fixed(){}

Fixed::Fixed(const int32_t number){
	fixed_number_ = (number << fractional);
}

Fixed::Fixed(const float number){
	fixed_number_ = static_cast<int>(roundf(number * (1 << fractional)));;
}

bool Fixed::operator>(const Fixed& rhs) const{
	return fixed_number_ > rhs.getRawBits();
}

bool Fixed::operator<(const Fixed& rhs) const{
	return fixed_number_ < rhs.getRawBits();
}

bool Fixed::operator>=(const Fixed& rhs) const{
	return fixed_number_ >= rhs.getRawBits();
}

bool Fixed::operator<=(const Fixed& rhs) const{
	return fixed_number_ <= rhs.getRawBits();
}

bool Fixed::operator==(const Fixed& rhs) const{
	return fixed_number_ == rhs.getRawBits();
}

bool Fixed::operator!=(const Fixed& rhs) const{
	return fixed_number_ != rhs.getRawBits();
}

Fixed Fixed::operator+(const Fixed& rhs) const{
	Fixed result;

	result.setRawBits((fixed_number_ + (rhs.getRawBits() >> fractional)));
	return result;
}

Fixed Fixed::operator-(const Fixed& rhs) const{
	Fixed result;

	result.setRawBits((fixed_number_ - (rhs.getRawBits() >> fractional)));
	return result;
}

Fixed Fixed::operator*(const Fixed& rhs) const{
	Fixed result;

	result.setRawBits((fixed_number_ * (rhs.getRawBits() >> fractional)));
	return result;
}

Fixed Fixed::operator/(const Fixed& rhs) const{
	Fixed result;

	result.setRawBits((fixed_number_ / (rhs.getRawBits() >> fractional)));
	return result;
}

Fixed& Fixed::operator++(){
	++fixed_number_;
	return *this;
}

Fixed& Fixed::operator--(){
	--fixed_number_;
	return *this;
}

Fixed Fixed::operator++(int){
	Fixed result;

	result = *this;
	fixed_number_++;
	return result;
}

Fixed Fixed::operator--(int){
	Fixed result;

	result = *this;
	fixed_number_--;
	return result;
}

int32_t	Fixed::getRawBits(void) const{
	return fixed_number_;
}

void Fixed::setRawBits(int32_t const rawBits){
	fixed_number_ = rawBits;
}

Fixed &Fixed::min(Fixed &lhs, Fixed &rhs){
	if (lhs < rhs)
		return lhs;
	return rhs;
}

const Fixed &Fixed::min(const Fixed &lhs, const Fixed &rhs){
	if (lhs < rhs)
		return lhs;
	return rhs;
}

Fixed &Fixed::max(Fixed &lhs, Fixed &rhs){
	if (lhs > rhs)
		return lhs;
	return rhs;
}

const Fixed &Fixed::max(const Fixed &lhs, const Fixed &rhs){
	if (lhs > rhs)
		return lhs;
	return rhs;
}

float Fixed::toFloat(void) const{
	return static_cast<float>(fixed_number_) / (1 << fractional);
}

int32_t	Fixed::toInt(void) const{
	return (fixed_number_ >> fractional);
}

std::ostream& operator<<(std::ostream& out, const Fixed &rhs)
{
	out << rhs.toFloat();
	return out;
}