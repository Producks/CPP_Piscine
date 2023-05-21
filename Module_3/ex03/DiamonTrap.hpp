#pragma once

#include <iostream>
#include "FragTrap.hpp"
#include "ScavTrap.hpp"


class DiamondTrap: public ScavTrap, public FragTrap
{
private:
		std::string _name;
		DiamondTrap();
public:
		DiamondTrap(const std::string& nameToSet);
		DiamondTrap(const DiamondTrap& rhs);
		DiamondTrap& operator=(const DiamondTrap& rhs);
		~DiamondTrap();

		void whoAmI();
		void attack(const std::string& target);
};