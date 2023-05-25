#include <iostream>

#include "Animal.hpp"
#include "_colors.hpp"

Animal::Animal() : type_("Default Type") {
  std::cout << GRN << "Animal default constructor called" << RESET << std::endl;
}

Animal::Animal(const std::string &type) : type_(type) {
  std::cout << YEL << "Animal type constructor called" << RESET << std::endl;
}

Animal::Animal(const Animal &rhs) {
  std::cout << BLU << "Animal copy constructor called" << RESET << std::endl;
  *this = rhs;
}

Animal &Animal::operator=(const Animal &rhs) {
  std::cout << MAG << "Animal copy operator called" << RESET << std::endl;
  type_ = rhs.type_;
  return *this;
}

Animal::~Animal() {
  std::cout << RED << "Animal destructor called" << RESET << std::endl;
}

const std::string &Animal::getType() const { return type_; }

void Animal::makeSound() const {
  std::cout << PNK << "Make inaudible sound" << RESET << std::endl;
}