#include <iomanip>
#include <iostream>

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	{
		const Animal *meta = new Animal();
		const Animal *j = new Dog();
		const Animal *i = new Cat();
		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		i->makeSound(); // will output the cat sound!
		j->makeSound();
		meta->makeSound();

		delete meta;
		delete j;
		delete i;
	}
	std::cout << std::setw(75) << std::setfill('*') << "" << std::endl;
	{
		const WrongAnimal *cat = new WrongCat("BOZO CAT");
		const WrongAnimal *meta = new WrongAnimal("BOZO");

		std::cout << cat->getType() << " " << std::endl;
		std::cout << meta->getType() << " " << std::endl;

		cat->makeSound();
		meta->makeSound();

		delete cat;
		delete meta;
	}
	return 0;
}
