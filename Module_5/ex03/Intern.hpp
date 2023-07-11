#pragma once
#include <iostream>
#include "Form.hpp"

class Intern{
  public:
  Intern();
  Intern(const Intern &rhs);
  ~Intern();

  Intern &operator=(const Intern &rhs);

  Form *makeForm(const std::string &formName, const std::string &target) const;
  class InvalidFormName : public std::exception{
    public:
      virtual const char *what() const throw();
  };

  class NullOrEmpty : public std::exception{
    public:
      virtual const char *what() const throw();
  };
};