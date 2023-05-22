#pragma once

#include <iostream>
#include "Animal.hpp"

class Dog : public Animal
{
public:
		Dog();
		Dog(const std::string& type);
		Dog(const Dog& rhs);
		~Dog();

		Dog& operator=(const Dog& rhs);

		void makeSound() const;
};