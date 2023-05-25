#pragma once

#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>

class Dog : public Animal {
private:
  Brain *brain_;

public:
  Dog();
  Dog(const std::string &type);
  Dog(const Dog &rhs);
  ~Dog();

  Dog &operator=(const Dog &rhs);

  void makeSound() const;
  const std::string &getDogIdea(int index) const;
};