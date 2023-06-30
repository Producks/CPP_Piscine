#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main(void)
{
	Form *shrubbery = new ShrubberyCreationForm("🌳");
  Form *robot = new RobotomyRequestForm("GPT");
  Form *president = new PresidentialPardonForm("Trump");
  Bureaucrat bozo("Clown", 150);
  Bureaucrat bozoTwo("Goof", 50);
  Bureaucrat bozoThree("Gandhi", 1);
  {
      bozo.executeForm(*shrubbery);
      bozoTwo.signForm(*shrubbery);
      bozoTwo.executeForm(*shrubbery);
  }
  {
    bozo.signForm(*robot);
    bozoTwo.signForm(*robot);
    bozoTwo.executeForm(*robot);
    bozoTwo.incrementGrade(30);
    bozoTwo.executeForm(*robot);
  }
  {
    bozo.signForm(*president);
    bozoThree.signForm(*president);
    bozoThree.executeForm(*president);
  }
  delete shrubbery;
  delete robot;
  delete president;
}
