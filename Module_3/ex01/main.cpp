#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
	{
		ScavTrap raichu("Raichu");

		raichu.attack("Onyx");
		raichu.beRepaired(50);
		raichu.takeDamage(69);
		raichu.guardGate();
		raichu.guardGate();

		ClapTrap pika("Pikachu");
		//pika.guardGate(); doesn't have access to it
		pika.attack("Onyx");
		pika.takeDamage(69);
		pika.attack("Onyx");
		raichu.takeDamage(69);
	}
	std::cout << "------------------------------------------------------" << std::endl;
	{
		ScavTrap raichu("Raichu");

		raichu.takeDamage(50);
		ScavTrap raichu_two = raichu;
		raichu.beRepaired(1);
		raichu_two.beRepaired(10);
	}
}