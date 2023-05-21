#pragma once

#include "ClapTrap.hpp"

class ScavTrap: virtual public ClapTrap
{
private:
		bool _guard_active;
protected:
		ScavTrap();
public:
		ScavTrap(const std::string& nameToSet);
		ScavTrap(const ScavTrap& rhs);
		ScavTrap& operator=(const ScavTrap& rhs);
		~ScavTrap();

		void attack(const std::string& target);
		void guardGate();
};