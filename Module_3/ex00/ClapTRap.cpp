#include <iostream>
#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): hitPoint(10), energyPoint(10), attackDamage(0) {}

ClapTrap::ClapTrap()
{

}

ClapTrap::ClapTrap(const ClapTrap& rhs)
{
	*this = rhs;
}

ClapTrap& ClapTrap::operator=(const ClapTrap rhs)
{
	this->hitPoint = rhs.hitPoint;
	this->energyPoint = rhs.energyPoint;
	this->attackDamage = rhs.attackDamage;
	return *this;
}

ClapTrap::~ClapTrap(){}

//ClapTrap <name> attacks <target>, causing <damage> points of damage!
void ClapTrap::attack(const std::string& target)
{
	std::cout << "ClapTrap" << name << target << ", causing" << attackDamage << "points of damage!" << std::endl;
}