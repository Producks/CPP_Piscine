#pragma once

#include "AMateria.hpp"

class Cure : public AMateria {
public:
  Cure();
  Cure(const Cure &rhs);
  Cure &operator=(const Cure &rhs);
  ~Cure();

  void use(ICharacter &target);
  AMateria *clone() const;
};