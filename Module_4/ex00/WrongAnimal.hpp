#pragma once

#include <iostream>

class WrongAnimal
{
protected:
		std::string _type;
public:
		WrongAnimal();
		WrongAnimal(const std::string& type);
		WrongAnimal(const WrongAnimal& rhs);
		~WrongAnimal();

		WrongAnimal& operator=(const WrongAnimal& rhs);

		const std::string& getType() const;
		void makeSound() const;
};