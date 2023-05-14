#include <cmath>
#include <iostream>
#include "Fixed.hpp"

//Orthodox Canonical Form
Fixed::Fixed(){
	std::cout << GRN << "Default constructor called" << RESET << std::endl;
}

Fixed::Fixed(const Fixed& ref_class){
	std::cout << CYN << "Copy constructor called" << RESET << std::endl;
	*this = ref_class;
}

Fixed& Fixed::operator=(const Fixed& ref_class){
	std::cout << PNK << "Copy assignment operator called" << RESET << std::endl;
	fixed_value_ = ref_class.getRawBits();
	return *this;
}

Fixed::~Fixed(){
	std::cout << RED << "Destructor called" << RESET << std::endl;
}

//Constructor asked by subject
Fixed::Fixed(const int number){
	std::cout << YEL << "Int constructor called" << RESET << std::endl;
	fixed_value_ = number << fractional;
}

Fixed::Fixed(const float number){
	std::cout << BLU << "Float constructor called" << RESET << std::endl;
	fixed_value_ = static_cast<int>(roundf(number * (1 << fractional)));
}

std::ostream& operator<<(std::ostream& out_stream, const Fixed &Ref_Fixed){
	out_stream << Ref_Fixed.toFloat();
	return out_stream;
}

//Getter and Setter
int	Fixed::getRawBits(void) const{
	return fixed_value_;
}

void	Fixed::setRawBits(int const rawBits){
	fixed_value_ = rawBits;
}

//Member functions
float Fixed::toFloat(void) const{
	  return static_cast<float>(fixed_value_) / (1 << fractional);
}

int	Fixed::toInt(void) const{
	return (fixed_value_ >> fractional);
}
