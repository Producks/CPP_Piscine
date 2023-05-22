#include <iostream>
#include "ClapTrap.hpp"

ClapTrap::ClapTrap(){}

ClapTrap::ClapTrap(const std::string& nameToSet)
{
	std::cout << GRN << "Name constructor called" << RESET << std::endl;
	_name = nameToSet;
	_hitPoint = 10;
	_energyPoint = 10;
	_attackDamage = 0;
}

ClapTrap::ClapTrap(const ClapTrap& rhs)
{
	std::cout << BLU << "Copy constructor called" << RESET << std::endl;
	*this = rhs;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& rhs)
{
	std::cout << PNK << "Copy operator called" << RESET << std::endl;
	this->_name = rhs._name;
	this->_hitPoint = rhs._hitPoint;
	this->_energyPoint = rhs._energyPoint;
	this->_attackDamage = rhs._attackDamage;
	return *this;
}

ClapTrap::~ClapTrap(){
	std::cout << RED << "Destructor operator called" << RESET << std::endl;
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
	std::cout << BRED << "ClapTrap " << _name <<" take " << amount << " damage and goes down to " << _hitPoint << " hitPoint" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (canPerformAction())
	{
		_energyPoint--;
		_hitPoint += amount;
		std::cout << YEL << "ClapTrap " << _name << " repair itself for " << amount << " and is now at " << _hitPoint << " hitPoint" << RESET << std::endl;
	}
}

bool ClapTrap::canPerformAction() const
{
	if (_hitPoint == 0)
		std::cout << BACKGROUNDRED << _name << " cannot perform action no hitPoint left 💀" << RESET << std::endl;
	else if (_energyPoint == 0)
		std::cout << BACKGROUNDRED << _name << " cannot perform action no energy left" << RESET << std::endl;
	else
		return true;
	return false;
}