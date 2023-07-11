#include "Form.hpp"

Form::Form(const std::string &name, const uint8_t &gradeToSign,
           const uint8_t &gradeToExecute)
    : name_(name), gradeToSign_(gradeToSign), gradeToExecute_(gradeToExecute),
      signed_(false) {
  if (gradeToSign > 150 || gradeToExecute > 150)
    throw GradeTooHighException();
  if (gradeToSign < 1 || gradeToExecute < 1)
    throw GradeTooLowException();
}

Form::Form(const Form &rhs)
    : name_(rhs.getFormName()), gradeToSign_(rhs.getGradeSign()),
      gradeToExecute_(rhs.getGradeExecute()), signed_(rhs.getSignedStatus()) {}

Form &Form::operator=(const Form &rhs) {
  std::cout << "Can only copy status since everything else is const"
            << std::endl;
  signed_ = rhs.getSignedStatus();
  return *this;
}

Form::~Form() {}

const char *Form::GradeTooHighException::what() const throw(){
	 return "Grade is too high for the form";
}

const char *Form::GradeTooLowException::what() const throw(){
	 return "Grade is too low for the form";
}

const uint8_t &Form::getGradeExecute() const { return gradeToExecute_; }
const uint8_t &Form::getGradeSign() const { return gradeToSign_; }
const std::string &Form::getFormName() const { return name_; }
const bool &Form::getSignedStatus() const { return signed_; }

void Form::beSigned(const Bureaucrat &rhs) {
  if (getGradeSign() < rhs.getGrade())
    throw GradeTooLowException();
  signed_ = true;
}

std::ostream &operator<<(std::ostream &out, const Form &rhs) {
  out << "Grade to execute:" << static_cast<int>(rhs.getGradeExecute())
      << " Grade to sign:" << static_cast<int>(rhs.getGradeSign())
      << " Form name: " << rhs.getFormName()
      << " Is signed:" << rhs.getSignedStatus() << std::endl;
  return out;
}