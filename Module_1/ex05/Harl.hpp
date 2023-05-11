#ifndef HARL_HPP
# define HARL_HPP

#include <iostream>
class Harl
{
private:
	void debug();
	void info();
	void warning();
	void error();
	std::string level_array[4];
	
public:
	Harl();
	~Harl();
	void complain(std::string level);
};

#endif