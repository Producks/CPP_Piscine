#pragma once

#include <iostream>
#include "Animal.hpp"

class Cat : public Animal
{
public:
		Cat();
		Cat(const std::string& type);
		Cat(const Cat& rhs);
		~Cat();

		Cat& operator=(const Cat& rhs);

		void makeSound() const;
};