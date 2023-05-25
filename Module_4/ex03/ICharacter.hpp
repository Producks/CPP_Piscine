#pragma once

#include <iostream>

#include "AMateria.hpp"

class AMateria; // circular dependency garbage, thanks for making me look for 15 years 😡😡😡😡😡😡😡😡

class ICharacter {
public:
  virtual ~ICharacter() {}
  virtual std::string const &getName() const = 0;
  virtual void equip(AMateria *m) = 0;
  virtual void unequip(int idx) = 0;
  virtual void use(int idx, ICharacter &target) = 0;
};
