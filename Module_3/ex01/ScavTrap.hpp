#pragma once

#include "ClapTrap.hpp"

class ScavTrap: public ClapTrap
{
private:
		bool _guard_active;
public:
		ScavTrap(const std::string& name);
		~ScavTrap();
		void guardGate();
};