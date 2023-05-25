#pragma once

#include "AMateria.hpp"

class Ice : public AMateria {
public:
  Ice();
  Ice(const Ice &rhs);
  Ice &operator=(const Ice &rhs);
  ~Ice();

  void use(ICharacter &target);
  AMateria *clone() const;
};