#pragma once

#include "AMateria.hpp"
#include "ICharacter.hpp"

#include <iostream>

class Character : public ICharacter {
private:
  Character();

  std::string name_;
  AMateria *materia_[4];

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