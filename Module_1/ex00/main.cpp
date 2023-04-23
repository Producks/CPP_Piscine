#include "Zombie.hpp"

int main(void)
{
	Zombie *first_zombie = newZombie("Bozo");
	first_zombie->announce();
	randomChump("Bozo_two");
	delete first_zombie;
	return 0;
}