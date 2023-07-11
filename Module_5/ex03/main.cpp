#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iomanip>
#include <iostream>

int main(void) {
  Intern intern;
  Form *form = NULL;
  Bureaucrat bozo("Clown", 150);
  Bureaucrat bozoTwo("Goof", 50);
  Bureaucrat bozoThree("Gandhi", 1);
  {
    try {
      form = intern.makeForm("zzzz", "Tree");
      form->beSigned(bozoThree);
      bozoThree.executeForm(*form);
      delete form;
    } catch (std::bad_alloc &exception) {
      std::cout << exception.what() << std::endl;
    } catch (Intern::InvalidFormName &exception) {
      std::cout << exception.what() << std::endl;
    } catch (std::exception &exception) {
      std::cout << exception.what() << std::endl;
			delete form;
    }
  }
  std::cout << std::setfill('~') << std::setw(38) << "" << std::endl;
  {
    try {
      form = intern.makeForm("PresidentialPardonForm", "Trump");
      form->beSigned(bozoThree);
      bozoThree.executeForm(*form);
      delete form;
    } catch (std::bad_alloc &exception) {
      std::cout << exception.what() << std::endl;
    } catch (Intern::InvalidFormName &exception) {
      std::cout << exception.what() << std::endl;
    } catch (std::exception &exception) {
      std::cout << exception.what() << std::endl;
			delete form;
    }
  }
	std::cout << std::setfill('~') << std::setw(38) << "" << std::endl;
  {
    try {
      form = intern.makeForm("ShrubberyCreationForm", "Treess");
      form->beSigned(bozo);
      bozoThree.executeForm(*form);
      delete form;
    } catch (std::bad_alloc &exception) {
      std::cout << exception.what() << std::endl;
    } catch (Intern::InvalidFormName &exception) {
      std::cout << exception.what() << std::endl;
    } catch (std::exception &exception) {
      std::cout << exception.what() << std::endl;
			delete form;
    }
  }
  std::cout << std::setfill('~') << std::setw(38) << "" << std::endl;
  {
    try {
      form = intern.makeForm("ShrubberyCreationForm", "Treess");
      form->beSigned(bozoThree);
      bozoThree.executeForm(*form);
      delete form;
    } catch (std::bad_alloc &exception) {
      std::cout << exception.what() << std::endl;
    } catch (Intern::InvalidFormName &exception) {
      std::cout << exception.what() << std::endl;
    } catch (std::exception &exception) {
      std::cout << exception.what() << std::endl;
			delete form;
    }
  }
  std::cout << std::setfill('~') << std::setw(38) << "" << std::endl;
  {
    try {
      form = intern.makeForm("RobotomyRequestForm", "ZZZ");
      form->beSigned(bozoThree);
      bozoThree.executeForm(*form);
      delete form;
    } catch (std::bad_alloc &exception) {
      std::cout << exception.what() << std::endl;
    } catch (Intern::InvalidFormName &exception) {
      std::cout << exception.what() << std::endl;
    } catch (std::exception &exception) {
      std::cout << exception.what() << std::endl;
    }
  }
  std::cout << std::setfill('~') << std::setw(38) << "" << std::endl;
  {
    try {
      form = intern.makeForm("", "");
      form->beSigned(bozoThree);
      bozoThree.executeForm(*form);
      delete form;
    } catch (std::bad_alloc &exception) {
      std::cout << exception.what() << std::endl;
    } catch (Intern::InvalidFormName &exception) {
      std::cout << exception.what() << std::endl;
    } catch (Intern::NullOrEmpty &exception){
			std::cout << exception.what() << std::endl;
		} catch (std::exception &exception){
      std::cout << exception.what() << std::endl;
			delete form;
    }
  }
  return 0;
}
