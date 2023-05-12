#include <functional>
#include "Harl.hpp"

Harl::Harl(){}

Harl::Harl(std::string intensity)
{
	level_array[0] = "DEBUG";
	level_array[1] = "INFO";
	level_array[2] = "WARNING";
	level_array[3] = "ERROR";
	filter = intensity;
}

void Harl::complain(std::string level)
{
	int	case_index = 4;
	int	index = 0;

	for (int index = 0; index < 4; index++)
	{
		if (level_array[index] == level)
		{
			case_index = index;
			break;
		}
	}
	switch(case_index)
	{
		case 0:
			Harl::debug();
			case_index--;
		case 1:
			Harl::info();
			case_index--;
		case 2:
			Harl::warning();
			case_index--;
		case 3:
			Harl::error();
			break;
		default:
			Harl::karen();
			break;
	}
}

void Harl::debug()
{
	std::cout << "\x1B[32m[ DEBUG ]\x1B[0m" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger."
			  << std::endl << "I really do !" << std::endl << std::endl;;
}

void Harl::info()
{
	std::cout << "\x1B[33m[ INFO ]\x1B[0m" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money." << std::endl
			  << "You didn’t put enough bacon in my burger ! If you did, I wouldn’t be asking for more !"
			  << std::endl << std::endl;
}
void Harl::warning()
{
	std::cout << "\x1B[38;5;206m[ WARNING ]\x1B[0m" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. " << std::endl <<
		"I’ve been coming for years whereas you started working here since last month." << std::endl << std::endl;;
}

void Harl::error()
{
	std::cout << "\033[0;34m[ ERROR ]\x1B[0m" << std::endl;
	std::cout << "This is unacceptable ! I want to speak to the manager now" << std::endl << std::endl;
}

void Harl::karen()
{
	std::cout << "[ 👧Probably complaining about insignificant problems👧 ]" << std::endl;
}