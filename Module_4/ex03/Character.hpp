#pragma once

#include <ctype.h>

#include <iostream>

#include "AMateria.hpp"
#include "ICharacter.hpp"

#define MAX_MATERIA_SIZE 4

class Character : public ICharacter {
 private:
  Character();

  std::string name_;
  AMateria *materia_[MAX_MATERIA_SIZE];
  uint8_t nbr_materia_equip_;

 public:
  Character(const std::string &name);
  Character(const Character &rhs);
  ~Character();

  Character &operator=(const Character &rhs);

  std::string const &getName() const;
  void equip(AMateria *m);
  void unequip(int idx);
  void use(int idx, ICharacter &target);
};