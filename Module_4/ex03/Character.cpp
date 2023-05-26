#include "Character.hpp"

#include <iostream>

#include "AMateria.hpp"

Character::Character() : name_("Default"), nbr_materia_equip_(0) {
  for (int i = 0; i < MAX_MATERIA_SIZE; i++) {
    materia_[i] = NULL;
  }
}

Character::Character(const std::string &name)
    : name_(name), nbr_materia_equip_(0) {
  for (int i = 0; i < MAX_MATERIA_SIZE; i++) {
    materia_[i] = NULL;
  }
}

Character::Character(const Character &rhs) { *this = rhs; }

Character &Character::operator=(const Character &rhs) {
  if (this == &rhs) {
    return *this;
  }
  name_ = rhs.name_;
  nbr_materia_equip_ = rhs.nbr_materia_equip_;
  for (int i = 0; i < MAX_MATERIA_SIZE; i++) {
    if (materia_[i]) delete materia_[i];
    materia_[i] = rhs.materia_[i];
  }
  return *this;
}

Character::~Character() {
  for (int i = 0; i < MAX_MATERIA_SIZE; i++) {
    if (materia_[i]) {
      delete materia_[i];
    }
  }
}

std::string const &Character::getName() const { return name_; }

void Character::equip(AMateria *m) {
  if (nbr_materia_equip_ == MAX_MATERIA_SIZE) {
    std::cout << "Can't equip inventory is full!" << std::endl;
    return;
  }
  for (int i = 0; i < MAX_MATERIA_SIZE; i++) {
    if (materia_[i]) {
      continue;
    } else {
      materia_[i] = m;
      std::cout << &materia_[i] << std::endl << &m << std::endl;
      nbr_materia_equip_++;
      break;
    }
  }
}

void Character::unequip(int index) {
  if (nbr_materia_equip_ == 0) {
    std::cout << "Can't unequip a materia none are equiped" << std::endl;
    return;
  }
  if (index >= MAX_MATERIA_SIZE || index < 0) {
    std::cout << "Invalid index" << std::endl;
    return;
  }
  materia_[index] = NULL;
  nbr_materia_equip_--;
}

void Character::use(int idx, ICharacter &target) {
  if (idx >= MAX_MATERIA_SIZE || idx < 0) {
    std::cout << "Invalid Index" << std::endl;
    return;
  }
  if (!materia_[idx]) {
    std::cout << "No materia are equiped for that index" << std::endl;
    return;
  }
  materia_[idx]->use(target);
  unequip(idx);
}