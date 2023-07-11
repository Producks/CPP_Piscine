#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>
#include <iomanip>

int main(void)
{
	{
		try{
			Bureaucrat bozo("Bozo", 69);
			Form form("Clown fiesta", 50, 5);
			bozo.signForm(form);
			bozo.incrementGrade(50);
			bozo.signForm(form);
		}
		catch(std::exception &exception) {
			std::cout << exception.what() << std::endl;
		}
	}
	std::cout << std::setfill('~') << std::setw(38) << "" << std::endl;
	{
		try{
			Bureaucrat bozo("Bozo", 19);
			Form form("Clown fiesta", 50, 5);
			bozo.signForm(form);
		}
		catch (std::exception &exception){
			std::cout << exception.what() << std::endl;
		}
	}
	std::cout << std::setfill('~') << std::setw(38) << "" << std::endl;
	{
		try{
			Bureaucrat bozo("Bozo", 69);
			Form form("Clown fiesta", 0, 15);
		}
		catch(std::exception &exception){
			std::cout << exception.what() << std::endl;
		}
	}
	std::cout << std::setfill('~') << std::setw(38) << "" << std::endl;
	{
		try{
			Bureaucrat bozo("Bozo", 69);
			Form form("Clown fiesta", 255, 5);
		}
		catch(std::exception &exception){
			std::cout << exception.what() << std::endl;
		}
	}
	return 0;
}
