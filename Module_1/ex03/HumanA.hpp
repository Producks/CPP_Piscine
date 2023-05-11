#ifndef HUMANA_HPP
# define HUMANA_HPP

#include <iostream>
#include "Weapon.hpp"

class HumanA
{
private:
	HumanA();
	Weapon *weapon;
	std::string name;

public:
	HumanA(std::string name, Weapon &weapon);
	void attack();
};

#endif