#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

int main(void)
{
	Bureaucrat bozo("Bozo", 150);
	Form *shrubbery = new ShrubberyCreationForm("🌳");
  {
    try{
			shrubbery->beSigned(bozo);
			shrubbery->execute(bozo);
    } 
		catch (const std::exception &exception) {
      std::cout << exception.what() << std::endl;
    }
  }
	delete shrubbery;
}
