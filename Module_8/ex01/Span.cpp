#include "Span.hpp"
#include <algorithm>
#include <iostream>

Span::Span(unsigned int N) : size_(N), vector_(0) {}

Span::Span(const Span &rhs) { *this = rhs; }

Span &Span::operator=(const Span &rhs) {
	size_ = rhs.size_;
	vector_.clear();
	vector_.resize(rhs.vector_.size());
	vector_.assign(rhs.vector_.begin(), rhs.vector_.end());
	return *this;
}

Span::~Span() {}

const char *Span::MaxSize::what() const throw() { return "Max size was reached"; }

const char *Span::NoSpan::what() const throw() { return "No span was found"; }

const std::vector<int>::iterator Span::getBegin() { return vector_.begin(); }

const std::vector<int>::iterator Span::getEnd() { return vector_.end(); }

void Span::addNumber(int number){
	if (vector_.size() == size_)
		throw MaxSize();
	vector_.push_back(number);
	size_++;
}

void Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end){
	std::vector<int>::iterator tmp = begin;
	unsigned int size = 0;
	while (tmp != end){
		tmp++;
		size++;
	}
	if ((size + vector_.size() - 1) >= size_)
		throw MaxSize();
	while (begin != end){
		vector_.push_back(*begin);
		begin++;
	}
}

int Span::shortestSpan(){
	if (vector_.size() <= 1)
		throw MaxSize();
	std::sort(vector_.begin(), vector_.end());
	int difference = *std::max_element(vector_.begin(), vector_.end());
	for (std::vector<int>::iterator it = vector_.begin(); it != vector_.end(); it++){
		int value = *it;
		for (std::vector<int>::iterator itwo = it; itwo != vector_.end(); itwo++){
			int toCompare = *itwo;
			if ((toCompare - value) < difference && (toCompare - value) != 0)
				difference = toCompare - value;
		}
	}
	if (difference == *std::max_element(vector_.begin(), vector_.end()))
		throw NoSpan();
	return difference;	
}

int Span::longestSpan(){
	if (vector_.size() <= 1)
		throw MaxSize();
	int max = *std::max_element(vector_.begin(), vector_.end());
	int min = *std::min_element(vector_.begin(), vector_.end());
	if (max == min)
		throw NoSpan();
	return max - min;
}

void Span::printContainer(){
	std::cout << "Size of container " << vector_.size() << std::endl;
	for (std::vector<int>::iterator it = vector_.begin(); it != vector_.end(); ++it)
			std::cout << *it << " ";
	std::cout << std::endl;
}