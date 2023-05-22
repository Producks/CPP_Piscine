#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
	{
		FragTrap snorlax("Snorlax");
		snorlax.highFivesGuys();
		snorlax.attack("Onyx");
		snorlax.takeDamage(69);
		FragTrap snorlax_two = snorlax;
		snorlax_two.takeDamage(69);
		snorlax.takeDamage(1);
	}
	std::cout << "------------" << std::endl;
	{
		FragTrap snorlax("Snorlax");
		ScavTrap raichu("Raichu");
		ClapTrap pika("Pikachu");

		pika.attack("Onyx");
		raichu.attack("Onyx");
		snorlax.attack("Onyx");
		raichu.guardGate();
		raichu.guardGate();
		snorlax.highFivesGuys();
		//snorlax.guardGate(); doesn't have access
	}
}