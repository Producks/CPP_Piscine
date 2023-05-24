#include "WrongCat.hpp"

#include <iostream>

#include "WrongAnimal.hpp"
#include "_colors.hpp"

WrongCat::WrongCat() : WrongAnimal("Wrong Default") {
  std::cout << UNDERLINE << GRN << "WrongCat default constructor called"
            << RESET << std::endl;
}

WrongCat::WrongCat(const std::string& type) : WrongAnimal(type) {
  std::cout << UNDERLINE << YEL << "WrongCat type constructor called" << RESET
            << std::endl;
}

WrongCat::WrongCat(const WrongCat& rhs) : WrongAnimal(rhs) {
  std::cout << UNDERLINE << BLU << "WrongCat copy constructor called"
            << std::endl;
  *this = rhs;
}

WrongCat& WrongCat::operator=(const WrongCat& rhs) {
  std::cout << UNDERLINE << MAG << "WrongCat copy operator called" << RESET
            << std::endl;
  type_ = rhs.getType();
  return *this;
}

WrongCat::~WrongCat() {
  std::cout << UNDERLINE << RED << "WrongCat destructor called" << RESET
            << std::endl;
}

void WrongCat::makeSound() const {
  std::cout << UNDERLINE << PNK << "🐱Meow Meow Meow🐱" << RESET << std::endl;
}