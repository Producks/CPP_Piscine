#pragma once

#include "ClapTrap.hpp"

class ScavTrap: public ClapTrap
{
private:
		bool _activated;
public:
		ScavTrap(const std::string& name);
		~ScavTrap();
		void guardGate();
};