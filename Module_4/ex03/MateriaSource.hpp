#pragma once

#include "AMateria.hpp"
#include "IMateriaSource.hpp"

#include <ctype.h>

class MateriaSource: public IMateriaSource{
private:
 AMateria *materia_[4];
 uint8_t  knowledge_count_;
public:
  MateriaSource();
  MateriaSource(const MateriaSource &rhs);
  ~MateriaSource();

  MateriaSource &operator=(const MateriaSource &rhs);

  void learnMateria(AMateria*);
  AMateria* createMateria(std::string const &type);
};