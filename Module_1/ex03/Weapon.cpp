#include "Weapon.hpp"

Weapon::Weapon(){}

Weapon::Weapon(std::string weaponType)
{
	type = weaponType;
}

const std::string& Weapon::getType() const
{
	return type;
}

void Weapon::setType(std::string type)
{
	this->type = type;
}