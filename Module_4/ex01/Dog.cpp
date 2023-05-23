#include <iostream>

#include "Dog.hpp"
#include "_colors.hpp"

Dog::Dog(): Animal(), _brain(new Brain())
{
	std::cout << UNDERLINE << GRN << "Dog default constructor called" << RESET << std::endl;
}

Dog::Dog(const std::string& type): Animal(type)
{
	std::cout << UNDERLINE << YEL << "Dog type constructor called" << RESET << std::endl;
}

Dog::Dog(const Dog& rhs): Animal(rhs)
{
	std::cout << UNDERLINE << BLU << "Dog copy constructor called" << std::endl;
	*this = rhs;
}

Dog& Dog::operator=(const Dog& rhs)
{
	std::cout << UNDERLINE << MAG << "Dog copy operator called" << RESET << std::endl;
	_type = rhs.getType();
	return *this;
}

Dog::~Dog()
{
	std::cout << UNDERLINE << RED << "Dog destructor called" << RESET << std::endl;
	delete _brain;
}

void Dog::makeSound() const
{
	std::cout << UNDERLINE << PNK << "🐕Woof Woof Woof🐕" << RESET << std::endl;
}