#include "Test.hpp"

#include <iostream>

Test::Test(){
	std::cout << "Default constructor called" << std::endl;
}

Test::~Test(){
	std::cout << "Destructor called" << std::endl;
}

void Test::makeSound() const{
	std::cout << "HELLO" << std::endl;
}