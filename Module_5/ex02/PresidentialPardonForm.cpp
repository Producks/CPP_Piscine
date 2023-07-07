#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
    : Form("PresidentialPardonForm", 25, 5), target_(target) {}

PresidentialPardonForm::PresidentialPardonForm(
    const PresidentialPardonForm &rhs)
    : Form(rhs), target_(getTarget()) {}

PresidentialPardonForm &
PresidentialPardonForm::operator=(const PresidentialPardonForm &rhs) {
  std::cout << "What are you doing???" << std::endl;
	(void)rhs;
  return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

const std::string &PresidentialPardonForm::getTarget() const { return target_; }

void PresidentialPardonForm::execute(const Bureaucrat &executor) const {
  canBeExecuted(executor);
  std::cout << getTarget() << " has been pardoned by Zaphod Beeblebox"
            << std::endl;
  std::cout << executor.getName() << " executed "
            << " PresidentialPardonForm" << std::endl;
}