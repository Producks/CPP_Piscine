#pragma once

#include <ctype.h>

#include "AMateria.hpp"
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
 private:
  static const uint8_t MAX_MATERIA_SIZE = 4;
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