#include <iostream>
#include "FragTrap.hpp"

FragTrap::FragTrap(const std::string& nameToSet): ClapTrap(nameToSet)
{
	std::cout << Bold << GRN << "FragTrap Name constructor called" << RESET << std::endl;
	_hitPoint = 100;
	_energyPoint = 100;
	_attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap& rhs): ClapTrap(rhs)
{
	std::cout << Bold << BLU << "FragTrap Copy constructor called" << RESET << std::endl;
	*this = rhs;
}

FragTrap& FragTrap::operator=(const FragTrap& rhs)
{
	std::cout << Bold << PNK << "FragTrap Copy assignment operator called" << RESET << std::endl;
	_hitPoint = rhs._hitPoint;
	_energyPoint = rhs._energyPoint;
	_attackDamage = rhs._attackDamage;
	return *this;
}

FragTrap::~FragTrap()
{
	std::cout << Bold << RED << "FragTrap Destructor operator called" << RESET << std::endl;
}

void FragTrap::attack(const std::string& target)
{
	if (this->canPerformAction())
	{
		_energyPoint--;
		std::cout << Bold << BGRE << "ScavTrap " << _name << " attacks " << target << " causing " << _attackDamage << " points of damage!" << RESET << std::endl;
	}
}

void FragTrap::highFivesGuys(void)
{
	std::cout << Bold << YEL << "FragTrap request to high fives 👋" << RESET << std::endl;
}
