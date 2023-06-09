#include <iostream>
#include "Fixed.hpp"

Fixed::Fixed(){
	std::cout << "\x1B[32mDefault\x1B[0m constructor called" << std::endl;
	fixed_integer = 0;
}

Fixed::Fixed(const Fixed& rhs){
	std::cout << "\x1B[33mCopy\x1B[0m constructor called" << std::endl;
	*this = rhs;
}

Fixed& Fixed::operator=(const Fixed& rhs){
	std::cout << "\x1B[35mCopy assignment\x1B[0m operator called" << std::endl;
	this->fixed_integer = rhs.getRawBits();
	return *this; // check later
}

Fixed::~Fixed(){
	std::cout << "\x1B[31mDestructor\x1B[0m called" << std::endl;
}

int32_t Fixed::getRawBits(void) const{
	std::cout << "\x1B[38;5;206mgetRawBits member\x1B[0m function called" << std::endl;
	return fixed_integer;
}

void Fixed::setRawBits(int32_t const raw){
	std::cout << "\x1B[35msetRawBits\x1B[0m function called" << std::endl;
	fixed_integer = raw;
}