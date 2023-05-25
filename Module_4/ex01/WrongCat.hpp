#pragma once

#include <iostream>

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
public:
  WrongCat();
  WrongCat(const std::string &type);
  WrongCat(const WrongCat &rhs);
  ~WrongCat();

  WrongCat &operator=(const WrongCat &rhs);

  void makeSound() const;
};