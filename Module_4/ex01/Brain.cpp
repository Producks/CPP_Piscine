#include "Brain.hpp"
#include "_colors.hpp"
#include <iostream>

Brain::Brain() {
  std::cout << "Brain Default constructor called" << std::endl;
  std::string array_ideas[4] = {"🦴", "🥫", "meow", "woof"};
  for (int i = 0; i < NBR_IDEAS; i++)
    ideas_[i] = array_ideas[std::rand() % 4];
}

Brain::Brain(const Brain& rhs) {
  std::cout << "Brain copy constructor called" << std::endl;
  *this = rhs;
}

Brain& Brain::operator=(const Brain& rhs) {
  std::cout << "Brain copy operator called" << std::endl;
  for (int i = 0; i < NBR_IDEAS; i++){
    ideas_[i] = rhs.ideas_[i];
  }
  return *this;
}

Brain::~Brain() { 
  std::cout << "Brain destructor called" << std::endl; 
}

const std::string &Brain::getIdea(int index) const {
  if (index < 0 || index >= NBR_IDEAS){
	std::cout << "Index out of scope" << std::endl;
	return ideas_[0]; // should handle with thow catch
  }
  return ideas_[index];
}