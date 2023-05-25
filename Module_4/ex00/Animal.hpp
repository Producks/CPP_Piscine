#pragma once

#include <iostream>

class Animal {
protected:
  std::string type_;

public:
  Animal();
  Animal(const std::string &type);
  Animal(const Animal &rhs);
  ~Animal();

  Animal &operator=(const Animal &rhs);

  const std::string &getType() const;
  virtual void makeSound() const;
};