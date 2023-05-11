#include <iostream>

#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define PNK   "\x1B[38;5;206m"
#define RESET "\x1B[0m"

int	main(void)
{
	std::string brain = "HI THIS IS BRAIN";
	std::string *brainPTR = &brain;
	std::string &brainREF = brain;
	std::cout << GRN << "Brain variable address: " << RESET << &brain << std::endl;
	std::cout << YEL << "Brain Ptr address: " << RESET << &brainPTR << std::endl;
	std::cout << PNK << "Brain Ref address: " << RESET << &brainREF << std::endl;
	std::cout << GRN << "Brain value: " << RESET << brain << std::endl;
	std::cout << YEL << "Brain Ptr value: " << RESET << *brainPTR << std::endl;
	std::cout << PNK << "Brain Ref value: " << RESET << brainREF << std::endl;
	return 0;
}