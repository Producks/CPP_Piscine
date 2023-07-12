#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <time.h>

int main(void)
{
	Base test;
	A a;
	B b;
	C c;

	Base *ptr = test.generate();
	test.identify(ptr);
	std::srand(time(NULL));
	int value = std::rand() % 3;
	if (value == 0)
		test.identify(a);
	else if (value == 1)
		test.identify(b);
	else
		test.identify(c);
	delete ptr;
}