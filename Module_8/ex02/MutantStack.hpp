#include <stack>
#include <deque>

//template <class T, class Container = deque<T> > class stack;

template <typename T>
class MutantStack : public std::stack<T, std::deque<T> > {
public:
	MutantStack() {};
	MutantStack(const MutantStack &rhs) { *this = rhs; };
	~MutantStack() {};

	//Mutanstack &operator=(const Mutanstack &rhs) { return *this; } //fix later
};