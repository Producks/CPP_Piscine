#pragma once

#include <vector>
#include <deque>

class PmergeMe{
public:
	PmergeMe();
	PmergeMe(const PmergeMe &rhs);
	~PmergeMe();

	PmergeMe &operator=(const PmergeMe &rhs);

	bool verifyParsing(int argc, char **argv);
	void sort(int argc, char **argv);

	void mergeSortVector(std::vector<std::pair<int, int> > &pairs, int start, int end);
	void insertSortVector(std::vector<std::pair<int, int> > &pairs, std::vector<int> &result);
	void sortVector(int argc, char **argv);

	void sortDeque(int argc, char **argv);
	void mergeSortDeque(std::deque<std::pair<int, int> > &pairs, int start, int end);
	void insertSortDeque(std::deque<std::pair<int, int> > &pairs, std::deque<int> &result);
};