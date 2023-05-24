#pragma once

#include <iostream>

class AAnimal
{
 private:
  AAnimal();
  AAnimal(const std::string& type);
  AAnimal(const AAnimal& rhs);
  AAnimal& operator=(const AAnimal& rhs);
  ~AAnimal();
protected:
 std::string& type_;
 virtual void makeSound() const;
};