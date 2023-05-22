#include <iostream>
#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap pika("Pikachu");

	pika.attack("Onyx");
	pika.takeDamage(5);
	pika.beRepaired(5);
	for (int i = 0; i < 8; i++) // There to remove all energy points
		pika.beRepaired(5);
	pika.attack("Onyx"); // Cannot attack no energy left
	pika.takeDamage(50);
	pika.attack("Onyx"); // Cannot attack since it's dead
	ClapTrap pika_two = pika;
	pika_two.attack("Onyx");
}