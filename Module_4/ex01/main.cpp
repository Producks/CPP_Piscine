#include <iomanip>
#include <iostream>

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	const Animal* j = new Dog();
	const Animal a;
	//const Animal* i = new Cat();

	delete j;//should not create a leak
	a.makeSound();
	//delete i;
	return 0;
}