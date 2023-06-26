#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

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
	{
		try{
			Bureaucrat bozo("Bozo", 69);
			Form form("Clown fiesta", 0, 15);
		}
		catch(std::exception &exception){
			std::cout << exception.what() << std::endl;
		}
	}
	{
		try{
			Bureaucrat bozo("Bozo", 69);
			Form form("Clown fiesta", 255, 5);
		}
		catch(std::exception &exception){
			std::cout << exception.what() << std::endl;
		}
	}
}
