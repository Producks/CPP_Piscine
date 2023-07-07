#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "typeint.h"

Intern::Intern() {}

Intern::Intern(const Intern &rhs) { *this = rhs; }

Intern &Intern::operator=(const Intern &rhs) {
  (void)rhs;
  return *this;
}

Intern::~Intern() {}

Form *Intern::makeForm(const std::string &formName,
                       const std::string &target) const {
  std::string nameArray[3];
  nameArray[0] = "ShrubberyCreationForm";
  nameArray[1] = "RobotomyRequestForm";
  nameArray[2] = "PresidentialPardonForm";
  m_uint8_t index = 0;
  Form *newForm;
  for (; index < 3 && nameArray[index] != formName; index++)
    continue;
  switch (index) {
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