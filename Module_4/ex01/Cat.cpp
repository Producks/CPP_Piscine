#include <iostream>

#include "Cat.hpp"
#include "Brain.hpp"
#include "_colors.hpp"

Cat::Cat() : Animal(), brain_(new Brain()) {
  std::cout << BOLD << GRN << "Cat default constructor called" << RESET
            << std::endl;
  //brain_ = new Brain();
}

Cat::Cat(const std::string& type) : Animal(type), brain_(new Brain()) {
  std::cout << BOLD << YEL << "Cat type constructor called" << RESET
            << std::endl;
}

Cat::Cat(const Cat& rhs) : Animal(rhs) {
  std::cout << BOLD << BLU << "Cat copy constructor called" << RESET
            << std::endl;
  *this = rhs;
}

Cat& Cat::operator=(const Cat& rhs) {
  std::cout << BOLD << MAG << "Cat copy operator called" << RESET << std::endl;
  type_ = rhs.getType();
  return *this;
}

Cat::~Cat() {
  delete this->brain_;
  std::cout << BOLD << RED << "Cat destructor called" << RESET << std::endl;
}

void Cat::makeSound() const {
  std::cout << BOLD << PNK << "🐱Meow Meow Meow🐱" << RESET << std::endl;
}