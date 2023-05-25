#pragma once

#include <iostream>

#define NBR_IDEAS 100

class Brain {
 private:
  std::string ideas_[NBR_IDEAS];

 public:
  Brain();
  Brain(const Brain& rhs);
  virtual ~Brain();

  Brain& operator=(const Brain& rhs);
  const std::string &getIdea(int index) const;
};