#pragma once

#include <vector>
#include <deque>

class PmergeMe{
public:
	PmergeMe();
	PmergeMe(const PmergeMe &rhs);
	~PmergeMe();

	PmergeMe &operator=(const PmergeMe &rhs);

	bool verifyParsing(char **argv);
	void sortVector(char **argv);
	void sortDeque(char **argv);
private:
	std::vector<int, int> vector_;
	std::deque<int, int> deque_;
};