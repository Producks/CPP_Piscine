#include "Cure.hpp"

#include <iostream>

Cure::Cure() : AMateria("cure") {}

Cure::Cure(const Cure &rhs) : AMateria(rhs) { *this = rhs; }

Cure &Cure::operator=(const Cure &rhs) { return *this; }

Cure::~Cure() {}

void Cure::use(ICharacter &target) {
 std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

AMateria *Cure::clone() const { return (new Cure(*this)); } //??? https://www.youtube.com/watch?v=UHP-DKrxgBs