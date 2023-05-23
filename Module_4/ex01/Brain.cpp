#include <iostream>

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain Default constructor called" << std::endl;
	for (int i = 0; i < NBR_IDEAS; i++)
		_ideas[i] = "Hello";
}

Brain::Brain(const Brain& rhs)
{
	std::cout << "Brain copy constructor called" << std::endl;
	*this = rhs;
}

Brain& Brain::operator=(const Brain& rhs)
{
	std::cout << "Brain copy operator called" << std::endl;
	return *this;
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}