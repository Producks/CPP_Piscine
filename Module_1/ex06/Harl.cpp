#include <functional>
#include "Harl.hpp"

Harl::Harl(std::string intensity)
{
	this->functions_map["DEBUG"] = &Harl::debug;
	this->functions_map["INFO"] = &Harl::info;
	this->functions_map["WARNING"] = &Harl::warning;
	this->functions_map["ERROR"] = &Harl::error;
	this->levels["DEBUG"] = 0;
	this->levels["INFO"] = 1;
	this->levels["WARNING"] = 2;
	this->levels["ERROR"] = 3;
	this->intensity = this->levels[intensity];
}

void Harl::complain(std::string level)
{
	if (this->levels[level] >= this->intensity)
		std::invoke(functions_map[level], this);
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

void Harl::error()
{
	std::cout << "This is unacceptable ! I want to speak to the manager now" << std::endl;
}