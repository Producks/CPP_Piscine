#include "PmergeMe.hpp"

int main(int argc, char **argv){
	PmergeMe sort;
	if (sort.verifyParsing(argc, argv))
		return 1;
	sort.sort(argc, argv);
	return 0;
}
//https://en.wikipedia.org/wiki/Merge-insertion_sort