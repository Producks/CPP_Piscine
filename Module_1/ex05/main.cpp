#include <iostream>
#include "Harl.hpp"

#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define PNK   "\x1B[38;5;206m"
#define BLU   "\033[0;34m"
#define RESET "\x1B[0m"

int main(void)
{
	Harl harl;
	std::cout << BLU << "Debug:" << RESET << std::endl;
	harl.complain("DEBUG");
	std::cout << GRN << "Info:" << RESET << std::endl;
	harl.complain("INFO");
	std::cout << PNK << "WARNING:" << RESET << std::endl;
	harl.complain("WARNING");
	std::cout << YEL << "ERROR:" << RESET << std::endl;
	harl.complain("ERROR");
	return 0;
}