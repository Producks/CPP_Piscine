#include <iostream>
#include "Harl.hpp"

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cout << "I would like to speak to the manager, you gave me the wrong number of arguments 👧" << std::endl;
		return 1;
	}
	Harl harl(argv[1]);
	harl.complain(argv[1]);
	return 0;
}