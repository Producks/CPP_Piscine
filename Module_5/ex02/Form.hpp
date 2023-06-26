#pragma once

#include "Bureaucrat.hpp"
#include <iostream>

class Bureaucrat; // Forward declaration garbage

class Form {
public:
  Form(const std::string &name, const uint8_t &gradeToSign,
       const uint8_t &gradeToExecute);
  Form(const Form &rhs);
  virtual ~Form();

  Form &operator=(const Form &rhs);

  const uint8_t &getGradeExecute() const;
  const uint8_t &getGradeSign() const;
  const bool &getSignedStatus() const;
  const std::string &getFormName() const;

  void beSigned(const Bureaucrat &rhs);
  virtual void execute(Bureaucrat const &executor) const = 0; // pure virtual make class abstract
  void canBeExecuted(Bureaucrat const &executor) const;

  class GradeTooHighException : public std::exception {
    virtual const char *what() const throw() {
      return "Grade is too high for the form";
    }
  };
  class GradeTooLowException : public std::exception {
    virtual const char *what() const throw() {
      return "Grade is too low for the form";
    }
  };
  class ExecutionRights : public std::exception {
    virtual const char *what() const throw() {
      return "Cannot execute the form";
    }
  };

private:
  const std::string name_;
  const uint8_t gradeToSign_;
  const uint8_t gradeToExecute_;
  bool signed_;
  Form();
};

std::ostream &operator<<(std::ostream &out, const Form &rhs);