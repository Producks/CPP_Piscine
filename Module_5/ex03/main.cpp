#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main(void)
{
  Intern intern;
  Form *form = NULL;
  Bureaucrat bozo("Clown", 150);
  Bureaucrat bozoTwo("Goof", 50);
  Bureaucrat bozoThree("Gandhi", 1);
  {
    try{
      form = intern.makeForm("zzzz", "Tree");
      form->beSigned(bozoThree);
      bozoThree.executeForm(*form);
      delete form;
    }
    catch (std::bad_alloc &exception){
      std::cout << exception.what() << std::endl;
    }
    catch (Intern::InvalidFormName &exception){
      std::cout << exception.what() << std::endl;
    }
  }
  return 0;
}
