#include "Bureaucrat.hpp"
#include <iostream>

int main(void)
{
	{
		try{
			Bureaucrat Bozo("Bozo", 69);
			Bozo.decrementGrade(10);
			std::cout << Bozo << std::endl;
			Bozo.decrementGrade(80);
			std::cout << Bozo << std::endl;
		}
		catch (std::exception &exception){ //avoid slicing
			std::cout << exception.what() << std::endl;
		}
	}
	{
		try{
			Bureaucrat Bozo("Bozo", 69);
			Bozo.incrementGrade(10);
			std::cout << Bozo << std::endl;
			Bozo.incrementGrade(69);
		}
		catch (std::exception &exception){
			std::cout << exception.what() << std::endl;
		}
	}
	{
		try{
			Bureaucrat Bozo("Bozo", 0xFF);
		}
		catch (std::exception &exception){
			std::cout << exception.what() << std::endl;
		}
	}
		{
		try{
			Bureaucrat Bozo("Bozo", 0);
		}
		catch (std::exception &exception){
			std::cout << exception.what() << std::endl;
		}
	}
}
