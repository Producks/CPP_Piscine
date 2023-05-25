#include "AMateria.hpp"

#include <iostream>

AMateria::AMateria() : type_("") {}

AMateria::AMateria(const AMateria &rhs) { *this = rhs; }

AMateria &AMateria::operator=(const AMateria &rhs) {
  type_ = rhs.type_;
  return *this;
}

AMateria::AMateria(std::string const &type) : type_(type) {}

AMateria::~AMateria() {}

std::string const &AMateria::getType() const { return type_; }

void AMateria::use(ICharacter &target){}