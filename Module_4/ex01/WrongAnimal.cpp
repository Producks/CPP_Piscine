#include <iostream>

#include "WrongAnimal.hpp"
#include "_colors.hpp"

WrongAnimal::WrongAnimal(): _type("Wrong Default Type")
{
	std::cout << GRN << "WrongAnimal default constructor called" << RESET << std::endl;
}

WrongAnimal::WrongAnimal(const std::string& type): _type(type)
{
	std::cout << YEL << "WrongAnimal type constructor called" << RESET << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& rhs)
{
	std::cout << BLU << "WrongAnimal copy constructor called" << std::endl;
	*this = rhs;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& rhs)
{
	std::cout << MAG << "WrongAnimal copy operator called" << RESET << std::endl;
	_type = rhs.getType();
	return *this;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << RED << "WrongAnimal destructor called" << RESET << std::endl;
}

const std::string& WrongAnimal::getType() const
{
	return _type;
}

void WrongAnimal::makeSound() const
{
	std::cout << PNK << "Make wrong inaudible sound" << RESET << std::endl;
}