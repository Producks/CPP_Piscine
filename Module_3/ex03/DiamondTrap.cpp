#include <iostream>
#include "DiamonTrap.hpp"

DiamondTrap::DiamondTrap(const std::string& nameToSet): ClapTrap("BOZO"), ScavTrap("dot"), FragTrap("GOV")
{
	std::cout << Underline << Bold << GRN << "DiamondTrap Name constructor called" << RESET << std::endl;
	ClapTrap::_name = nameToSet + "clap_name";
	_name = nameToSet;
	_hitPoint = FragTrap::_hitPoint;
	_energyPoint = ScavTrap::_energyPoint;
	_attackDamage = FragTrap::_attackDamage;
}

DiamondTrap::DiamondTrap(const DiamondTrap& rhs): ClapTrap(rhs), ScavTrap(rhs), FragTrap(rhs)
{
	std::cout << Underline << Bold << BLU << "DiamondTrap Copy constructor called" << RESET << std::endl;
	*this = rhs;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& rhs)
{
	std::cout << Underline << Bold << PNK << "DiamondTrap Copy assignment operator called" << RESET << std::endl;
	return *this;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << Underline << Bold << RED << "DiamondTrap Destructor operator called" << RESET << std::endl;
}

void DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
	std::cout << Underline << Bold << RED << "I AM " << _name << " And " << ClapTrap::_name << RESET << std::endl;
}