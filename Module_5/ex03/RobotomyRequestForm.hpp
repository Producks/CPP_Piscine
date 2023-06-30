#pragma once

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

class RobotomyRequestForm : public Form {
public:
  RobotomyRequestForm(const std::string &target);
  RobotomyRequestForm(const RobotomyRequestForm &rhs);
  ~RobotomyRequestForm();

  RobotomyRequestForm &operator=(const RobotomyRequestForm &rhs);

  const std::string &getTarget() const;

  void execute(const Bureaucrat &executor) const;

private:
  const std::string target_;
  RobotomyRequestForm();
};