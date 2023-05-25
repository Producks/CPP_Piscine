#include "MateriaSource.hpp"

MateriaSource::MateriaSource(): knowledge_count_(0){}

MateriaSource::MateriaSource(const MateriaSource &rhs){}

MateriaSource &MateriaSource::operator=(const MateriaSource &rhs){ return *this; }

MateriaSource::~MateriaSource(){}

void MateriaSource::learnMateria(AMateria*){}

AMateria* MateriaSource::createMateria(std::string const &type){return NULL;}