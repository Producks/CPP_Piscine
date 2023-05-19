#include <iostream>
#include "ScavTrap.hpp"

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name)
{
	_guard_active = false;
	std::cout << "ScavTrap Constructor Called" << std::endl;
}

ScavTrap::~ScavTrap(){
	std::cout << "ScavTrap Destructor Called" << std::endl;
}

void ScavTrap::guardGate()
{
	if (_guard_active == false)
	{
		std::cout << "GUARD KEEPER MODE ACTIVATED" << std::endl;
		_guard_active = true;
	}
	else
		std::cout << "GUARD IS ALREADY ACTIVE" << std::endl;
}