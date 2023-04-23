#include "Zombie.hpp"

int	main(void)
{
	Zombie	*zombiehorde = zombieHorde(5, "bozo");
	for (int i = 0; i < 5; i++)
	{
		zombiehorde[i].announce();
	}
	delete[] zombiehorde; // ??????
	return 0;
}