#pragma once

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

class PresidentialPardonForm : public Form {
public:
  PresidentialPardonForm(const std::string &target);
  PresidentialPardonForm(const PresidentialPardonForm &rhs);
  ~PresidentialPardonForm();

  PresidentialPardonForm &operator=(const PresidentialPardonForm &rhs);

  const std::string &getTarget() const;

  void execute(const Bureaucrat &executor) const;

private:
  const std::string target_;
  PresidentialPardonForm();
};