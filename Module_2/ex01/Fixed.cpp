#include <cmath>
#include <iostream>
#include "Fixed.hpp"

Fixed::Fixed(){
	std::cout << GRN << "Default constructor called" << RESET << std::endl;
}

Fixed::Fixed(const Fixed& rhs){
	std::cout << CYN << "Copy constructor called" << RESET << std::endl;
	*this = rhs;
}

Fixed& Fixed::operator=(const Fixed& rhs){
	std::cout << PNK << "Copy assignment operator called" << RESET << std::endl;
	fixed_value_ = rhs.getRawBits();
	return *this;
}

Fixed::~Fixed(){
	std::cout << RED << "Destructor called" << RESET << std::endl;
}

Fixed::Fixed(const int32_t number){
	std::cout << YEL << "Int constructor called" << RESET << std::endl;
	fixed_value_ = number << fractional;
}

Fixed::Fixed(const float number){
	std::cout << BLU << "Float constructor called" << RESET << std::endl;
	fixed_value_ = static_cast<int>(roundf(number * (1 << fractional)));
}

int	Fixed::getRawBits(void) const{
	return fixed_value_;
}

void	Fixed::setRawBits(int const rawBits){
	fixed_value_ = rawBits;
}

float Fixed::toFloat(void) const{
	  return static_cast<float>(fixed_value_) / (1 << fractional);
}

int32_t	Fixed::toInt(void) const{
	return (fixed_value_ >> fractional);
}

std::ostream& operator<<(std::ostream& out_stream, const Fixed &rhs){
	out_stream << rhs.toFloat();
	return out_stream;
}