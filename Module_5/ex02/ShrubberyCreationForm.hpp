  #pragma once

  #include "Bureaucrat.hpp"
  #include "Form.hpp"
  #include <iostream>

  class ShrubberyCreationForm : public Form {
  public:
    ShrubberyCreationForm(const std::string &target);
    ShrubberyCreationForm(const ShrubberyCreationForm &rhs);
    ~ShrubberyCreationForm();

    ShrubberyCreationForm &operator=(const ShrubberyCreationForm &rhs);

    const std::string &getTarget() const;

    void execute(const Bureaucrat &executor) const;

    class FileError : public std::exception {
      virtual const char *what() const throw() {
        return "Couldn't create file";
      }
    };
  private:
    const std::string target_;
    ShrubberyCreationForm();
  };