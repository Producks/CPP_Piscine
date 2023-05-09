#include "Weapon.hpp"

Weapon::Weapon(std::string weaponType)
{
	this->type = weaponType;
}

const std::string Weapon::getType()
{
	return type;
}

void Weapon::setType(std::string type)
{
	this->type = type;
}