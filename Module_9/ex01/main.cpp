#include "RPN.hpp"
#include <iostream>

using std::cout;
using std::endl;

int main(int argc, char **argv){
	if (argc == 1){
		cout << "No argument were provided" << endl;
		return 1;
	}
	RPN calculator;
	for (int index = 1; index < argc; index++)
		calculator.rpnCalculator(argv[index]);
}
// https://www.youtube.com/watch?v=7ha78yWRDlE amazing explanation of RPN/Postfix notation