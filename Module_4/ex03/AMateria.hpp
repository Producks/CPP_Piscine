#pragma once

#include <iostream>

#include "ICharacter.hpp"

class AMateria {
private:
  AMateria();
protected:
  std::string type_;
public:
  AMateria(const AMateria &rhs);
  AMateria &operator=(const AMateria &rhs);
  virtual ~AMateria();

  AMateria(std::string const &type);
  std::string const &getType() const; // Returns the materia type
  virtual AMateria *clone() const = 0;
  virtual void use(ICharacter &target);
};