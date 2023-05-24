#pragma once

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
private:
		Brain* brain_;
public:
		Dog();
		Dog(const std::string& type);
		Dog(const Dog& rhs);
		~Dog();

		Dog& operator=(const Dog& rhs);

		void makeSound() const;
};