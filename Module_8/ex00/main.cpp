#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "easyfind.hpp"

#define RED "\x1B[31m"
#define GRN "\x1B[32m"
#define YEL "\x1B[33m"
#define BLU "\x1B[34m"
#define MAG "\x1B[35m"
#define CYN "\x1B[36m"
#define WHT "\x1B[37m"
#define PNK "\x1B[38;5;206m"
#define ORNG "\x1B[38;2;255;165;0m"
#define RESET "\x1B[0m"

int main(void){
	std::vector<int> intVector;
	std::srand(static_cast<unsigned int>(std::time(NULL)));

	std::cout << PNK << "✨Welcome to the easyfind game✨" << RESET << std::endl;
	std::cout << YEL << "You only have 4 tries to find all 3 numbers between 0-9" << RESET << std::endl;

	while (intVector.size() < 3){
		int randomNumber = (std::rand() % 10);
		if (!duplicate(intVector, randomNumber))
			intVector.push_back(randomNumber);
	}
	int numberOfTries = 4;
	std::string input;
	try{
		while (numberOfTries && intVector.size()){
			std::cout << MAG << "Number of tries remaining " << numberOfTries << RESET;
			std::cout << BLU << "  Numbers left to find " << intVector.size() << RESET << std::endl;
			std::cout << "Please enter your input:";
			std::getline(std::cin, input);
			if (input.empty() || input.size() > 1)
				throw InvalidInput();
			if (intVector.end() != easyfind(intVector, atoi(input.c_str()))){
				intVector.erase(easyfind(intVector, atoi(input.c_str())));
				std::cout << GRN << input << " was found!" << RESET << std::endl;
			}
			else{
				numberOfTries--;
				std::cout << RED << input << " wasn't found!" << RESET << std::endl;
			}
		}
	}
	catch (std::exception &exception){
		std::cout << exception.what() << std::endl;
	}
	if (intVector.size() == 0)
		std::cout << ORNG << "🎉Congratulation you won!🎉" << RESET << std::endl;
	else
		std::cout << CYN << "You lost! Better luck next time😔" << RESET << std::endl;
	return 0;
}