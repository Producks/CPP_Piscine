#ifndef HARL_HPP
# define HARL_HPP

#include <iostream>

class Harl
{	
private:
	Harl();
	void debug();
	void info();
	void warning();
	void error();
	void karen();
	std::string level_array[4];
	std::string	filter;

public:
	Harl(std::string intensity);
	void complain(std::string level);
};

#endif