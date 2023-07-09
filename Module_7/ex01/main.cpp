#include "iter.hpp"
#include <iostream>

int main(void){
	int array[5] = {1, 2, 3, 4, 5};
	float floatArray [3] = {1.2f, 2.1f, 3.4f};
	iter(array, 5, print);
	std::cout << std::endl << "--------------" << std::endl;
	iter(array, 5, incrementationFunc);
	iter(array, 5, print);
	std::cout << std::endl << "--------------" << std::endl;
	iter(floatArray, 3, print);
	std::cout << std::endl << "--------------" << std::endl;
	iter(floatArray, 3, incrementationFunc);
	iter(floatArray, 3, print);
	return 0;
}