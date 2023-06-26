#pragma once

#include <iostream>

class Bureaucrat {
public:
  Bureaucrat(std::string name, uint8_t grade);
  Bureaucrat(const Bureaucrat &rhs);
  ~Bureaucrat();

  Bureaucrat &operator=(const Bureaucrat &rhs);

  const std::string &getName() const;
  const uint8_t &getGrade() const;

  void incrementGrade(uint8_t amount);
  void decrementGrade(uint8_t amount);

  class GradeTooHighException : public std::exception {
    virtual const char *what() const throw() { return "Grade is too high"; }
  };

  class GradeTooLowException : public std::exception {
    virtual const char *what() const throw() { return "Grade is too low"; }
  };

private:
  Bureaucrat();
  const std::string name_;
  uint8_t grade_;
};

std::ostream &operator<<(std::ostream& out, const Bureaucrat &rhs);