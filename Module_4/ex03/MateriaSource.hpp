#pragma once

#include <ctype.h>

#include "AMateria.hpp"
#include "IMateriaSource.hpp"

#define MAX_MATERIA_SIZE 4

class MateriaSource : public IMateriaSource {
 private:
  AMateria *materia_[MAX_MATERIA_SIZE];
  uint8_t materia_count_;

 public:
  MateriaSource();
  MateriaSource(const MateriaSource &rhs);
  ~MateriaSource();

  MateriaSource &operator=(const MateriaSource &rhs);

  void learnMateria(AMateria *materia); //bozo giving us bad protoype
  AMateria *createMateria(std::string const &type);
};