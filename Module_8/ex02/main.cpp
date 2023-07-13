#include "MutantStack.hpp"
#include <iostream>
#include <iomanip>
#include <list>

int main() {
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite) {
		std::cout << *it << std::endl;
		++it;
		}
	std::stack<int> s(mstack);
	MutantStack<int>::const_iterator constit = mstack.cbegin();
	//*constit += 5; // proof to show it's const even if deque only implemented const iterator in c++11
	(void)constit;
}
std::cout << std::setfill('~') << std::setw(38) << "" << std::endl;
{
	std::list<int> listack;
	listack.push_front(5);
	listack.push_front(17);
	std::cout << listack.front() << std::endl;
	listack.pop_back();
	std::cout << listack.size() << std::endl;
	listack.push_front(3);
	listack.push_front(5);
	listack.push_front(737);
	//[...]
	listack.push_front(0);
	std::list<int>::reverse_iterator it = listack.rbegin();
	std::list<int>::reverse_iterator ite = listack.rend();
	++it;
	--it;
	while (it != ite) {
		std::cout << *it << std::endl;
		++it;
		}
	std::list<int> s(listack);
}
	return 0;
}