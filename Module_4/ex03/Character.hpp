#pragma once

#include <ctype.h>

#include <iostream>

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Character : public ICharacter {
private:
  Character();

  std::string name_;
  static const uint8_t MAX_MATERIA_SIZE = 4;
  AMateria *materia_[MAX_MATERIA_SIZE];
  uint8_t nbr_materia_equip_;

  //doesn't copy over since it's literal purpose is garbage collection
  static const uint8_t MAX_POINTERS = 100;
  AMateria *pointers_[MAX_POINTERS];
  int pointerCount_;

public:
  Character(const std::string &name);
  Character(const Character &rhs);
  ~Character();

  Character &operator=(const Character &rhs);

  std::string const &getName() const;
  void equip(AMateria *m);
  void unequip(int idx);
  void use(int idx, ICharacter &target);
  void addGarbage(AMateria *materia);
  void clearGarbage();
};