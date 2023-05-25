#include "Character.hpp"

Character::Character() : name_("Default") {
  for (int i = 0; i < 4; i++)
    materia_[i] = NULL;
}

Character::Character(const std::string &name) : name_(name) {
  for (int i = 0; i < 4; i++)
    materia_[i] = NULL;
}

Character::Character(const Character &rhs) { *this = rhs; }

Character &Character::operator=(const Character &rhs) {
  if (this == &rhs)
    return *this;
  name_ = rhs.name_;
  for (int i = 0; i < 4; i++) {
    if (rhs.materia_[i]) {
      materia_[i] = rhs.materia_[i]->clone();
    } else {
      materia_[i] = NULL;
    }
  }
  return *this;
}

Character::~Character() {
  for (int i = 0; i < 4; i++) {
    if (materia_[i]) {
      delete materia_[i];
    }
  }
}

std::string const &Character::getName() const { return name_; }

void Character::equip(AMateria *m) {}

void Character::unequip(int index) {}

void Character::use(int idx, ICharacter &target) {}