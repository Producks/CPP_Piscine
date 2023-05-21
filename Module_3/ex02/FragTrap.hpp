#pragma once

#include <iostream>
#include "ClapTrap.hpp"

class FragTrap: public ClapTrap
{
private:
		FragTrap();
public:
		FragTrap(const std::string& nameToSet);
		FragTrap(const FragTrap& rhs);
		FragTrap& operator=(const FragTrap& rhs);
		~FragTrap();

		void highFivesGuys(void);
};