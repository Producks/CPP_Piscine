#include "Base.hpp"
#include "A.hpp"

int main(void)
{
	Base test;
	A a;

	Base *ptr = test.generate();
	test.identify(ptr);
	test.identify(a);
	delete ptr;
}