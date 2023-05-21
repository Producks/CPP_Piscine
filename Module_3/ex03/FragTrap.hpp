#pragma once

#include <iostream>
#include "ClapTrap.hpp"

class FragTrap: virtual public ClapTrap
{
protected:
		FragTrap();
public:
		FragTrap(const std::string& nameToSet);
		FragTrap(const FragTrap& rhs);
		FragTrap& operator=(const FragTrap& rhs);
		~FragTrap();

		void highFivesGuys(void);
};