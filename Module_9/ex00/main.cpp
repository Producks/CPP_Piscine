#include "BitcoinExchange.hpp"
#include <iostream>

using std::cerr;
using std::endl;
using std::cout;

int main (int argc, char **argv){
	if (argc != 2){
		cerr << "Error: Invalid number of arguments" << endl;
		return 1;
	}
	try{
		BitcoinExchange exchange(argv[1]);
		exchange.readInputDataBase();
		// cout << "---" << endl;
		// BitcoinExchange a = exchange; //left to prove copy operator works
		// a.readInputDataBase();
	} catch (std::exception &exception){
		cerr << exception.what() << endl;
		return 1;
	}
	return 0;
}