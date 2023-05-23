#pragma once

#include <iostream>

#define NBR_IDEAS 100

class Brain
{
private:
		std::string _ideas[NBR_IDEAS];
public:
		Brain();
		Brain(const Brain& rhs);
		~Brain();

		Brain& operator=(const Brain& rhs);
};