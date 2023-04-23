#include <iostream>

int	main(void)
{
	std::string brain = "HI THIS IS BRAIN";
	std::string *brainPTR = &brain;
	std::string &brainREF = brain;
	std::cout << "Brain address: " << &brain << std::endl;
	std::cout << "Brain Ptr address: " << &brainPTR << std::endl;
	std::cout << "Brain Ref address: " << &brainREF << std::endl;
	std::cout << "Brain value: " << brain << std::endl;
	std::cout << "Brain Ptr value: " << *brainPTR << std::endl;
	std::cout << "Brain Ref value: " << brainREF << std::endl;
	return 0;
}