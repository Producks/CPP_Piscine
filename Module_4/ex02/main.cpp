#include <iomanip>
#include <iostream>

#include "Brain.hpp"
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	{
		Brain a;
		
		Brain b = a;
		for (int i = 0; i < NBR_IDEAS; i++)
			std::cout << b.getIdea(i) << std::endl;
	}
	std::cout << std::setw(33) << std::setfill('*') << "" << std::endl;
	std::cout <<  "~	Main from subject	~" << "" << std::endl;
	std::cout << std::setw(33) << std::setfill('*') << "" << std::endl;
	{
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		delete j;//should not create a leak
		delete i;
	}
	std::cout << std::setw(33) << std::setfill('*') << "" << std::endl;
	std::cout <<  "~	Multiple animal		~" << "" << std::endl;
	std::cout << std::setw(33) << std::setfill('*') << "" << std::endl;
	{
		Animal* animalArray[10];

		for (int i = 0; i < 5; i++)
			animalArray[i] = new Cat();
		for (int i = 5; i < 10; i++)
			animalArray[i] = new Dog();
		
		animalArray[5]->makeSound();
		animalArray[0]->makeSound();

		std::cout << ((Cat *)animalArray[0])->getCatIdea(0) << std::endl;
		std::cout << ((Dog *)animalArray[5])->getDogIdea(50) << std::endl;

		for (int i = 0; i < 10; i++)
			delete animalArray[i];
	}
	std::cout << std::setw(33) << std::setfill('*') << "" << std::endl;
	std::cout <<  "~	Multiple animal		~" << "" << std::endl;
	std::cout << std::setw(33) << std::setfill('*') << "" << std::endl;
	{
		//Animal a;
		//Can't call Animal by itself since it's pure virtual
	}
	return 0;
}
