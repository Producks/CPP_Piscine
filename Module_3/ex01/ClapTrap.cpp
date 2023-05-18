#include <iostream>
#include "ClapTrap.hpp"

ClapTrap::ClapTrap(){}

ClapTrap::ClapTrap(std::string nameToSet)
{
	std::cout << GRN << "Default constructor called" << RESET << std::endl;
	name = nameToSet;
	hitPoint = 10;
	energyPoint = 10;
	attackDamage = 0;
}

ClapTrap::ClapTrap(const ClapTrap& rhs)
{
	std::cout << BLU << "Copy constructor called" << RESET << std::endl;
	*this = rhs;
}

ClapTrap& ClapTrap::operator=(const ClapTrap rhs)
{
	std::cout << PNK << "Copy operator called" << RESET << std::endl;
	this->name = rhs.name;
	this->hitPoint = rhs.hitPoint;
	this->energyPoint = rhs.energyPoint;
	this->attackDamage = rhs.attackDamage;
	return *this;
}

ClapTrap::~ClapTrap(){
	std::cout << RED << "Destructor operator called" << RESET << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	if (canPerformAction())
	{
		energyPoint--;
		std::cout << BGRE << "ClapTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << RESET << std::endl;
	 }
}

void ClapTrap::takeDamage(unsigned int amount)
{
	hitPoint -= amount;
	if (hitPoint < 0)
		hitPoint = 0;
	std::cout << BRED << "ClapTrap take " << amount << " damage and goes down to " << hitPoint << " hitpoint" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (canPerformAction())
	{
		energyPoint--;
		hitPoint += amount;
		std::cout << YEL << "ClapTrap repair itself and is now at " << hitPoint << " hitpoint" << RESET << std::endl;
	}
}

bool ClapTrap::canPerformAction() const
{
	if (hitPoint == 0)
		std::cout << RED << "Cannot perform action no hitpoint left 💀" << RESET << std::endl;
	else if (energyPoint == 0)
		std::cout << RED << "Cannot perform action no energy left" << RESET << std::endl;
	else
		return true;
	return false;
}