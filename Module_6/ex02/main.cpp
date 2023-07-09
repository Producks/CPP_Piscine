#include "Base.hpp"
#include "B.hpp"

int main(void)
{
	Base test;
	B b;

	Base *ptr = test.generate();
	test.identify(ptr);
	test.identify(b);
	delete ptr;
}