#include "PmergeMe.hpp"
#include <iostream>
#include <cctype>
#include <string.h>
#include <utility>
#include <stdlib.h>
#include <ctime>

using std::cout;
using std::cerr;
using std::endl;

PmergeMe::PmergeMe(){}

PmergeMe::PmergeMe(const PmergeMe &rhs) { *this = rhs; }

PmergeMe::~PmergeMe(){}

PmergeMe &PmergeMe::operator=(const PmergeMe &rhs) { (void)rhs; return *this; }

void PmergeMe::sort(int argc, char **argv){
	cout << "Before: ";
	for (int index = 1; index < argc; index++)
		cout << argv[index] << " ";
	cout << endl;
	std::clock_t startVector = std::clock();
	sortVector(argc, argv);
	double resultVector = static_cast<double>(std::clock() - startVector) / CLOCKS_PER_SEC * 1000;
	time_t beginDeque = time(NULL); 
	sortDeque(argc, argv);
	time_t resultDeque = (time(NULL) - beginDeque);
	cout << "Vector sorted " << argc - 1 << " elements in " << resultVector << " us" << endl;
	cout << "Deque sorted " << argc - 1 << " elements in " << resultDeque << " us" << endl;
}

bool PmergeMe::verifyParsing(int argc, char **argv){
	if (argc == 1){
		cout << "No arguments were provided" << endl;
		return true;
	}
	for (int i = 1; i < argc; i++){
		for (int j = i + 1; j < argc; j++){
			if (!strcmp(argv[i], argv[j])){
				cout << "Found duplicate argument" << endl;
				return true;
			}
		}
	}
	for (int index = 1; index < argc; index++){
		if (!argv[index][0]){
			cout << "Found a non digit character in the argument provided" << endl;
			return true;
		}
		for (int i = 0; argv[index][i]; i++){
			if (!isdigit(argv[index][i])){
				cout << "Found a non digit character in the argument provided" << endl;
				return true;
			}
		}
	}
	return false;
}

void PmergeMe::mergeSortVector(std::vector<std::pair<int, int> > &pairs, int start, int end) {
  if (start >= end)
    return;
  int middle = start + (end - start) / 2;
  mergeSortVector(pairs, start, middle);
  mergeSortVector(pairs, middle + 1, end);
  int leftIndex = start;
  int rightIndex = middle + 1;
  std::vector<std::pair<int, int> > mergedPairs;
  while (leftIndex <= middle && rightIndex <= end) {
    if (pairs[leftIndex].first < pairs[rightIndex].first)
      mergedPairs.push_back(pairs[leftIndex++]);
    else
      mergedPairs.push_back(pairs[rightIndex++]);
  }
  while (leftIndex <= middle)
    mergedPairs.push_back(pairs[leftIndex++]);
  while (rightIndex <= end)
    mergedPairs.push_back(pairs[rightIndex++]);
  for (int i = start, j = 0; i <= end; i++, j++)
  	pairs[i] = mergedPairs[j];
}

void PmergeMe::insertSortVector(std::vector<std::pair<int, int> > &pairs, std::vector<int> &result){
	int index = 0;
	while (!pairs.empty()){
		int nbr = pairs.front().second;
		if (nbr != -1){
			std::vector<int>::iterator it = std::lower_bound(result.begin() + index++, result.end(), nbr);
			result.insert(it, nbr);
		}
		pairs.erase(pairs.begin());
	}
}

//https://en.wikipedia.org/wiki/Merge-insertion_sort
void PmergeMe::sortVector(int argc, char **argv){
	std::vector<std::pair<int, int> > pairs;
	pairs.reserve(argc / 2);
	int index = 1;
	while (index < argc){
		int number1 = atoi(argv[index++]);
		if (index < argc){
			int number2 = atoi(argv[index++]);
			pairs.push_back(std::make_pair(number1, number2)); // first step
		}
		else
			pairs.push_back(std::make_pair(number1, -1));
	}
	for(std::vector<std::pair<int, int > >::iterator it = pairs.begin(); it != pairs.end(); ++it){ // 2nd step
		if (it->first > it->second && it->second != -1)
			std::swap(it->first, it->second);
	}
	mergeSortVector(pairs, 0, pairs.size() - 1); // 3rd step
	std::vector<int> result;
	result.reserve(argc - 1);
	for(std::vector<std::pair<int, int > >::iterator it = pairs.begin(); it != pairs.end(); ++it)
			result.push_back(it->first);
	result.push_back(pairs.back().second); // 4th step
	pairs.pop_back();
	insertSortVector(pairs, result); // 5th step
}

void PmergeMe::insertSortDeque(std::deque<std::pair<int, int> > &pairs, std::deque<int> &result){
	int index = 0;
	while (!pairs.empty()){
		int nbr = pairs.front().second;
		if (nbr != -1){
			std::deque<int>::iterator it = std::lower_bound(result.begin() + index++, result.end(), nbr);
			result.insert(it, nbr);
		}
		pairs.erase(pairs.begin());
	}
}

void PmergeMe::mergeSortDeque(std::deque<std::pair<int, int> > &pairs, int start, int end){
  if (start >= end)
    return;
  int middle = start + (end - start) / 2;
  mergeSortDeque(pairs, start, middle);
  mergeSortDeque(pairs, middle + 1, end);
  int leftIndex = start;
  int rightIndex = middle + 1;
  std::deque<std::pair<int, int> > mergedPairs;
  while (leftIndex <= middle && rightIndex <= end) {
    if (pairs[leftIndex].first < pairs[rightIndex].first)
      mergedPairs.push_back(pairs[leftIndex++]);
    else
      mergedPairs.push_back(pairs[rightIndex++]);
  }
  while (leftIndex <= middle)
    mergedPairs.push_back(pairs[leftIndex++]);
  while (rightIndex <= end)
    mergedPairs.push_back(pairs[rightIndex++]);
  for (int i = start, j = 0; i <= end; i++, j++)
  	pairs[i] = mergedPairs[j];
}

void PmergeMe::sortDeque(int argc, char **argv){
	std::deque<std::pair<int, int> > pairs;
	//pairs.resize(argc / 2);
	int index = 1;
	while (index < argc){
		int number1 = atoi(argv[index++]);
		if (index < argc){
			int number2 = atoi(argv[index++]);
			pairs.push_back(std::make_pair(number1, number2)); // first step
		}
		else
			pairs.push_back(std::make_pair(number1, -1));
	}
	for(std::deque<std::pair<int, int > >::iterator it = pairs.begin(); it != pairs.end(); ++it){ // 2nd step
		if (it->first > it->second && it->second != -1)
			std::swap(it->first, it->second);
	}
	mergeSortDeque(pairs, 0, pairs.size() - 1); // 3rd step
	std::deque<int> result;
	//result.resize(argc - 1);
	for(std::deque<std::pair<int, int > >::iterator it = pairs.begin(); it != pairs.end(); ++it)
			result.push_back(it->first);
	result.push_back(pairs.back().second); // 4th step
	pairs.pop_back();
	insertSortDeque(pairs, result); // 5th step
	cout << "After: ";
	for(std::deque<int>::iterator it = result.begin(); it != result.end(); ++it)
			cout << *it << " ";
	cout << endl;
}