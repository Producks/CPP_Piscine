#pragma once

#include <iostream>
#include "ClapTrap.hpp"

class FragTrap: virtual public ClapTrap
{
private:
		FragTrap();
public:
		FragTrap(const std::string& nameToSet);
		FragTrap(const FragTrap& rhs);
		FragTrap& operator=(const FragTrap& rhs);
		~FragTrap();

		void attack(const std::string& target);
		void highFivesGuys(void);
};