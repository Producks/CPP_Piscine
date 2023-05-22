#pragma once

#include <iostream>
#include "FragTrap.hpp"
#include "ScavTrap.hpp"


class DiamondTrap: public ScavTrap, public FragTrap // how to get fired from your job https://en.wikipedia.org/wiki/Multiple_inheritance
// Deadly Diamond of Death, BOZO EXERCISE 🤡 🤡 🤡 🤡 🤡
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