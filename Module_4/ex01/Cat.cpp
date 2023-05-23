#include <iostream>

#include "Cat.hpp"
#include "Brain.hpp"
#include "_colors.hpp"

Cat::Cat(): Animal(), _brain(new Brain())
{
	std::cout << BOLD << GRN << "Cat default constructor called" << RESET << std::endl;
	//_brain = new Brain();
}

Cat::Cat(const std::string& type): Animal(type), _brain(new Brain())
{
	std::cout << BOLD << YEL << "Cat type constructor called" << RESET << std::endl;
}

Cat::Cat(const Cat& rhs): Animal(rhs)
{
	std::cout << BOLD << BLU << "Cat copy constructor called" << RESET << std::endl;
	*this = rhs;
}

Cat& Cat::operator=(const Cat& rhs)
{
	std::cout << BOLD << MAG << "Cat copy operator called" << RESET << std::endl;
	_type = rhs.getType();
	return *this;
}

Cat::~Cat()
{
	delete this->_brain;
	std::cout << BOLD << RED << "Cat destructor called" << RESET << std::endl;
}

void Cat::makeSound() const
{
	std::cout << BOLD << PNK << "🐱Meow Meow Meow🐱" << RESET << std::endl;
}