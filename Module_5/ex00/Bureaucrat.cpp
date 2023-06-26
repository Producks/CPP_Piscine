#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() {}

Bureaucrat::Bureaucrat(std::string name, uint8_t grade) : name_(name) {
  if (grade > 150)
    throw GradeTooLowException();
  else if (grade < 1)
    throw GradeTooHighException();
  grade_ = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &rhs) : name_(rhs.getName()) {
  *this = rhs;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &rhs) {
  std::cout << "Couldn't copy name over with operator = since it's const"
            << std::endl;
  grade_ = rhs.getGrade();
  return *this;
}

Bureaucrat::~Bureaucrat() {}

const std::string &Bureaucrat::getName() const { return name_; }

const uint8_t &Bureaucrat::getGrade() const { return grade_; }

void Bureaucrat::incrementGrade(uint8_t amount) {
  int32_t result = grade_ - amount;
  if (result <= 0 || amount > 150)
    throw GradeTooHighException();
  grade_ = result;
}

void Bureaucrat::decrementGrade(uint8_t amount) {
  uint16_t result = grade_ + amount;
  if (result > 150 || amount > 150)
    throw GradeTooLowException();
  grade_ = result;
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &rhs) {
  out << rhs.getName() << ", bureaucrat grade " << static_cast<int>(rhs.getGrade());
  return out;
}