#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() {}

Intern::Intern(const Intern &rhs){ *this = rhs; }

Intern &Intern::operator=(const Intern &rhs){ return *this; }

Intern::~Intern() {}

Form *Intern::makeForm(const std::string &formName, const std::string &target) const{
  std::string nameArray[3]{
    "ShrubberyCreationForm",
    "RobotomyRequestForm",
    "PresidentialPardonForm"
  };
  uint8_t index = 0;
  Form *newForm;
  for(index; index < 3 && nameArray[index] != formName; index++)
    continue;
  switch(index){
    case 0:
      newForm = new ShrubberyCreationForm(target);
      break;
    case 1:
      newForm = new RobotomyRequestForm(target);
      break;
    case 2:
      newForm = new PresidentialPardonForm(target);
      break;
    case 3:
      throw InvalidFormName();
  }
  return newForm;
}