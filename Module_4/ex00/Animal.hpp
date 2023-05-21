#pragma once

#include <iostream>

class Animal
{
protected:
		std::string type;
public:
		Animal();
		Animal(const Animal& rhs);
		Animal& operator=(const Animal& rhs);
		~Animal();
};