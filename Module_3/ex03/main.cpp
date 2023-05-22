#include <iostream>
#include <iomanip>
#include "DiamonTrap.hpp"
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
	{
		DiamondTrap ditto("Ditto");

		ditto.attack("Mewtwo");
		ditto.takeDamage(0);
		ditto.highFivesGuys();
		ditto.guardGate();
		ditto.guardGate();
		ditto.beRepaired(0);
		DiamondTrap ditto_two = ditto;
	}
	std::cout << std::setw(75) << std::setfill('*') << "" << std::endl;
	{
		DiamondTrap ditto("Ditto");
		ScavTrap	raichu("Raichu");
		ClapTrap	pika("Pikachu");
		FragTrap	snorlax("Snorlax");

		ditto.attack("Onyx");
		raichu.attack("Onyx");
		pika.attack("Onyx");
		snorlax.attack("Onyx");
		raichu.guardGate();
		raichu.guardGate();
		ditto.guardGate();
		ditto.guardGate();
		ditto.highFivesGuys();
		snorlax.highFivesGuys();
	}
}