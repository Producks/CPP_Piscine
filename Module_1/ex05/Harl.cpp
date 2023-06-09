#include <iostream>
#include "Harl.hpp"

Harl::Harl()
{
	level_array[0] = "DEBUG";
	level_array[1] = "INFO";
	level_array[2] = "WARNING";
	level_array[3] = "ERROR";
}

Harl::~Harl(){}

void Harl::complain(std::string level)
{
	void (Harl::*func_ptr[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	for (int i = 0; i < 4; i++)
	{
		if (level_array[i] == level)
			(this->*func_ptr[i])();
	}
}

void Harl::debug()
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do !"
			  << std::endl;
}

void Harl::info()
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger ! If you did, I wouldn’t be asking for more !"
			  << std::endl;
}
void Harl::warning()
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

/*Function should be rename to karen*/
void Harl::error()
{
	std::cout << "This is unacceptable ! I want to speak to the manager now" << std::endl;
}