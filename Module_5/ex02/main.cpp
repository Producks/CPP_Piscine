#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <iomanip>

int main(void)
{
	Form *shrubbery = new ShrubberyCreationForm("🌳");
  Form *robot = new RobotomyRequestForm("GPT");
  Form *president = new PresidentialPardonForm("Trump");
  Bureaucrat bozo("Clown", 150);
  Bureaucrat bozoTwo("Goof", 50);
  Bureaucrat bozoThree("Gandhi", 1);
  try{
      bozo.executeForm(*shrubbery);
      bozoTwo.signForm(*shrubbery);
      bozoTwo.executeForm(*shrubbery);
  } catch (std::exception &exception){
    std::cout << exception.what() << std::endl;
  }
  std::cout << std::setfill('~') << std::setw(38) << "" << std::endl;
  try{
    bozo.signForm(*robot);
  } catch (std::exception &exception){
    std::cout << exception.what() << std::endl;
  }
  std::cout << std::setfill('~') << std::setw(38) << "" << std::endl;
  try{
    bozoTwo.signForm(*robot);
    bozoTwo.executeForm(*robot);
  } catch (std::exception &exception){
    std::cout << exception.what() << std::endl;
  }
  try{
    bozoThree.signForm(*shrubbery);
    bozoThree.signForm(*robot);
    bozoThree.signForm(*president);
    bozoThree.executeForm(*shrubbery);
    bozoThree.executeForm(*robot);
    bozoThree.executeForm(*president);
  } catch (std::exception &exception){
    std::cout << exception.what() << std::endl;
  }
  delete shrubbery;
  delete robot;
  delete president;
}
