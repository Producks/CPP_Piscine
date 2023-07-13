#pragma once
#include <stack>

// template <class T, class Container = deque<T> > class stack;

template <typename T> class MutantStack : public std::stack<T> {
public:
  MutantStack(){};
  MutantStack(const MutantStack &rhs) { *this = rhs; };
  ~MutantStack(){};

  MutantStack &operator=(const MutantStack &rhs) { return *this; }

  typedef typename std::deque<T>::iterator iterator;
  typedef typename std::deque<T>::const_iterator const_iterator;
  typedef typename std::deque<T>::reverse_iterator reverse_iterator;
  typedef typename std::deque<T>::const_reverse_iterator const_reverse_iterator;

  iterator begin() { return std::stack<T>::c.begin(); }
  iterator end() { return std::stack<T>::c.end(); }
  reverse_iterator rbegin() { return std::stack<T>::c.rbegin(); }
  reverse_iterator rend() { return std::stack<T>::c.rend(); }
	const iterator cbegin() { return std::stack<T>::c.begin(); }
	const iterator cend() { return std::stack<T>::c.end(); }
	const reverse_iterator crbegin() { return std::stack<T>::c.rbegin(); }
	const reverse_iterator crend() { return std::stack<T>::c.rend(); }
};