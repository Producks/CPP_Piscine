#include "PmergeMe.hpp"
#include <iostream>

using std::cerr;
using std::cout;
using std::endl;

int main(int argc, char **argv){
	if (argc == 1){
		cerr << "No arguments were provided" << endl;
		return 1;
	}
	PmergeMe merge;
	merge.sortVector();
	merge.sortDeque();
	return 0;
}
//https://github.com/decidedlyso/merge-insertion-sort/blob/master/README.md?utm_source=pocket_saves