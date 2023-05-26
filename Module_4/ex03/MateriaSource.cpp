#include "MateriaSource.hpp"

#include "AMateria.hpp"
#include "Character.hpp"

MateriaSource::MateriaSource() : materia_count_(0) {
  for (int i = 0; i < MAX_MATERIA_SIZE; i++) {
    materia_[i] = NULL;
  }
}

MateriaSource::MateriaSource(const MateriaSource &rhs) { *this = rhs; }

MateriaSource &MateriaSource::operator=(const MateriaSource &rhs) {
  for (int i = 0; i < MAX_MATERIA_SIZE; i++) {
    materia_[i] = rhs.materia_[i];
  }
  materia_count_ = rhs.materia_count_;
  return *this;
}

MateriaSource::~MateriaSource() {
  for (int i = 0; i < MAX_MATERIA_SIZE; i++) {
    if (materia_[i]) {
      delete materia_[i];
    }
  }
}

void MateriaSource::learnMateria(AMateria *materia) {
  if (materia_count_ == MAX_MATERIA_SIZE) {
    std::cout << "Can't learn materia, reached the full amount" << std::endl;
  }
  for (int i = 0; i < MAX_MATERIA_SIZE; i++) {
    if (!materia_[i]) {
      materia_[i] = materia;
      materia_count_++;
      break;
    }
  }
}

AMateria *MateriaSource::createMateria(std::string const &type) {
  for (int i = 0; i < MAX_MATERIA_SIZE; i++) {
    if (!materia_[i]) {
      return NULL;
    }
    if (type == materia_[i]->getType()) {
      return materia_[i]->clone();
    }
  }
  return NULL;
}