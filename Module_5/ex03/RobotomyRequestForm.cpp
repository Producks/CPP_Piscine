#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : Form("RobotomyRequestForm",72, 45), target_(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &rhs) : Form(rhs), target_(getTarget()) {}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &rhs){
  std::cout << "???🤡" << std::endl;
	(void)rhs;
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

const std::string &RobotomyRequestForm::getTarget() const { return target_; }


void  RobotomyRequestForm::execute(const Bureaucrat &executor) const {
  canBeExecuted(executor);
  std::srand(static_cast<unsigned int>(std::time(NULL)));
  if (std::rand() % 2)
    std::cout << "Robotomy failed" << std::endl;
  else
  {
    std::cout << "BZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ" << std::endl;
    std::cout << getTarget() << " has been robotomized" << std::endl;
    std::cout << executor.getName() << " executed " << " Robotomy" << std::endl;
  }
}