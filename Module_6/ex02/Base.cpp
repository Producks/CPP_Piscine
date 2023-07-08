#include <cstdlib>
#include <iostream>
#include <typeinfo>
#include <time.h>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base() {};

Base *Base::generate(void){
	std::srand(time(NULL));
	int randomValue = rand();
	if (randomValue < RAND_MAX / 3)
		return dynamic_cast<Base*>(new A);
	else if (randomValue < (RAND_MAX / 3) * 2)
		return dynamic_cast<Base*>(new B);
	else
		return dynamic_cast<Base*>(new C);
}

void Base::identify(Base *p){
	Base *result;
	result = dynamic_cast<A*>(p);
	if (result == NULL)
		std::cout << "Base pointer wasn't A" << std::endl;
	else
		std::cout << "Base pointer was A" << std::endl;
	result = dynamic_cast<B*>(p);
	if (result == NULL)
		std::cout << "Base pointer wasn't B" << std::endl;
	else
		std::cout << "Base pointer was B" << std::endl;
	result = dynamic_cast<C*>(p);
	if (result == NULL)
		std::cout << "Base pointer wasn't C" << std::endl;
	else
		std::cout << "Base pointer was C" << std::endl;
}

void Base::identify(Base &p){
	try{
		A &aResult = dynamic_cast<A&>(p);
		(void)aResult;
		std::cout << "Base reference was A" << std::endl;
	}
	catch (std::bad_cast &exception){
		std::cout << "Base reference wasn't A " << exception.what() << std::endl;
	}
	try{
		B &bResult = dynamic_cast<B&>(p);
		(void)bResult;
		std::cout << "Base reference was B" << std::endl;
	}
	catch (std::bad_cast &exception){
		std::cout << "Base reference wasn't B " << exception.what() << std::endl;
	}
	try{
		C &cResult = dynamic_cast<C&>(p);
		(void)cResult;
		std::cout << "Base reference was C" << std::endl;
	}
	catch (std::bad_cast &exception){
		std::cout << "Base reference wasn't C " << exception.what() << std::endl;
	}
}