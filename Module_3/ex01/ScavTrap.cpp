#include <iostream>
#include "ScavTrap.hpp"

ScavTrap::ScavTrap(const std::string &name): ClapTrap(name)
{
	std::cout << Underline << GRN << "ScavTrap Name Constructor Called" << RESET << std::endl;
	_hitPoint = 100;
	_energyPoint = 50;
	_attackDamage = 20;
	_guard_active = false;
}

ScavTrap::ScavTrap(const ScavTrap& rhs): ClapTrap(rhs)
{
	std::cout << Underline << BLU << "ScavTrap Copy Constructor Called" << RESET << std::endl;
	*this = rhs;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& rhs)
{
	std::cout << Underline << PNK << "ScavTrap Copy assignment operator called" << RESET << std::endl;
	_name = rhs._name;
	_hitPoint = rhs._hitPoint;
	_energyPoint = rhs._energyPoint;
	_attackDamage = rhs._attackDamage;
	return *this;
}

ScavTrap::~ScavTrap()
{
	std::cout << Underline << RED << "ScavTrap Destructor Called" << RESET << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	if (this->canPerformAction())
	{
		_energyPoint--;
		std::cout << Underline << BGRE << "ScavTrap " << _name << " attacks " << target << " causing " << _attackDamage << " points of damage!" << RESET << std::endl;
	}
}

void ScavTrap::guardGate()
{
	if (_guard_active == false)
	{
		std::cout << Underline << MAG << "ScavTrap is now in Gatekeeper mode" << RESET << std::endl;
		_guard_active = true;
	}
	else
		std::cout << Underline << CYN << "Scavtrap is already in Gatekeeper mode" << RESET << std::endl;
}