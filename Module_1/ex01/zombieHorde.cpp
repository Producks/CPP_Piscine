#include "Zombie.hpp"

Zombie* zombieHorde(int number, std::string name)
{
	Zombie *horde = new Zombie[number];
	for (int i = 0; i < number; i++)
		horde[i].setName(name);
	return horde;
}