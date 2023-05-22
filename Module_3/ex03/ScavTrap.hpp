#pragma once

#include "ClapTrap.hpp"

class ScavTrap: virtual public ClapTrap
{
private:
		ScavTrap();
protected:
		bool _guard_active;
public:
		ScavTrap(const std::string& name);
		ScavTrap(const ScavTrap& rhs);
		ScavTrap& operator=(const ScavTrap& rhs);
		~ScavTrap();

		void attack(const std::string& target);
		void guardGate();
};