#include "Ice.hpp"

#include <iostream>

Ice::Ice() : AMateria("ice") {}

Ice::Ice(const Ice &rhs) : AMateria(rhs) { *this = rhs; }

Ice &Ice::operator=(const Ice &rhs) { return *this; }

Ice::~Ice() {}

void Ice::use(ICharacter &target) {
 std::cout << "* shoots an ice bolt at " << target.getName() << std::endl;
}

AMateria *Ice::clone() const { return (new Ice(*this)); } //??? https://www.youtube.com/watch?v=UHP-DKrxgBs