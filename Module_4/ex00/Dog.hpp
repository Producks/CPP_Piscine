#pragma once

#include "Animal.hpp"
#include <iostream>

class Dog : public Animal {
public:
  Dog();
  Dog(const std::string &type);
  Dog(const Dog &rhs);
  ~Dog();

  Dog &operator=(const Dog &rhs);

  void makeSound() const;
};