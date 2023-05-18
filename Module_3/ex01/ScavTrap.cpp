#include <iostream>
#include "ScavTrap.hpp"

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name){
	std::cout << BACKGROUNDRED << "HEY" << std::endl;
}

ScavTrap::~ScavTrap(){
	std::cout << "LMAO" << std::endl;
}

void ScavTrap::guardGate()
{
	if (_activated == false)
	{
		std::cout << "GUARD ACTIVATED" << std::endl;
		_activated = true;
	}
	else
		std::cout << "GUARD IS ALREADY ACTIVE" << std::endl;
}