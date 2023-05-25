#pragma once

#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>

class Cat : public Animal {
private:
  Brain *brain_;

public:
  Cat();
  Cat(const std::string &type);
  Cat(const Cat &rhs);
  ~Cat();

  Cat &operator=(const Cat &rhs);

  void makeSound() const;
  const std::string &getCatIdea(int index) const;
};