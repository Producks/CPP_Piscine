#include <iostream>
#include "ClapTrap.hpp"

ClapTrap::ClapTrap(){}

ClapTrap::ClapTrap(const std::string nameToSet) : _name(nameToSet), _hitPoint(10), _energyPoint(10), _attackDamage(0)
{
	std::cout << GRN << "ClapTrap Default constructor called" << RESET << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& rhs)
{
	std::cout << BLU << "ClapTrap Copy constructor called" << RESET << std::endl;
	*this = rhs;
}

ClapTrap& ClapTrap::operator=(const ClapTrap rhs)
{
	std::cout << PNK << "ClapTrap Copy assignment operator called" << RESET << std::endl;
	this->_name = rhs._name;
	this->_hitPoint = rhs._hitPoint;
	this->_energyPoint = rhs._energyPoint;
	this->_attackDamage = rhs._attackDamage;
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << RED << "ClapTrap Destructor operator called" << RESET << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	if (canPerformAction())
	{
		_energyPoint--;
		std::cout << BGRE << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << RESET << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	_hitPoint -= amount;
	if (_hitPoint < 0)
		_hitPoint = 0;
	std::cout << BRED << "ClapTrap take " << amount << " damage and goes down to " << _hitPoint << " hitpoint" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (canPerformAction())
	{
		_energyPoint--;
		_hitPoint += amount;
		std::cout << YEL << "ClapTrap repair itself and is now at " << _hitPoint << " hitpoint" << RESET << std::endl;
	}
}

bool ClapTrap::canPerformAction() const
{
	if (_hitPoint == 0)
		std::cout << RED << "Cannot perform action no hitpoint left 💀" << RESET << std::endl;
	else if (_energyPoint == 0)
		std::cout << RED << "Cannot perform action no energy left" << RESET << std::endl;
	else
		return true;
	return false;
}