#ifndef HARL_HPP
# define HARL_HPP

#include <iostream>
#include <map>

class Harl
{
	typedef void (Harl::*t_func)(void);
	
	public:
	Harl();
	void complain(std::string level);

	private:
	void debug();
	void info();
	void warning();
	void error();
	std::map<std::string, t_func> functions_map;//
};

#endif