#pragma once

#include "Bureaucrat.hpp"
#include "typeint.h"
#include <exception>
#include <iostream>

class Bureaucrat; // Forward declaration garbage

class Form {
public:
  Form(const std::string &name, const m_uint8_t &gradeToSign,
       const m_uint8_t &gradeToExecute);
  Form(const Form &rhs);
  virtual ~Form();

  Form &operator=(const Form &rhs);

  const m_uint8_t &getGradeExecute() const;
  const m_uint8_t &getGradeSign() const;
  const bool &getSignedStatus() const;
  const std::string &getFormName() const;

  void beSigned(const Bureaucrat &rhs);
  virtual void execute(
      Bureaucrat const &executor) const = 0; // pure virtual make class abstract
  void canBeExecuted(Bureaucrat const &executor) const;

  class GradeTooHighException : public std::exception {
    virtual const char *what() const throw();
  };
  class GradeTooLowException : public std::exception {
    virtual const char *what() const throw();
  };
  class ExecutionRights : public std::exception {
  public:
    virtual const char *what() const throw();
  };
  class UnsignedForm : public std::exception {
  public:
    virtual const char *what() const throw();
  };

private:
  const std::string name_;
  const m_uint8_t gradeToSign_;
  const m_uint8_t gradeToExecute_;
  bool signed_;
  Form();
};

std::ostream &operator<<(std::ostream &out, const Form &rhs);