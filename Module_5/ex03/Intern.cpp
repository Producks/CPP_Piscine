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

const char *Intern::InvalidFormName::what() const throw(){
	return "Invalid form name";
}

const char *Intern::NullOrEmpty::what() const throw(){
	return "Argument was empty";
}

Form *Intern::makeForm(const std::string &formName,
                       const std::string &target) const {
	if (formName.empty() || target.empty())
		throw NullOrEmpty();
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
