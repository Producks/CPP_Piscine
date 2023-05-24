#pragma once

#include <iostream>

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
 private:
  Brain* brain_;

 public:
  Cat();
  Cat(const std::string& type);
  Cat(const Cat& rhs);
  virtual ~Cat();

  Cat& operator=(const Cat& rhs);

  void makeSound() const;
};