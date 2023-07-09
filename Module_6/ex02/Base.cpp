#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <iostream>
#include <time.h>
#include <typeinfo>

#define RED "\x1B[31m"
#define GRN "\x1B[32m"
#define YEL "\x1B[33m"
#define BLU "\x1B[34m"
#define MAG "\x1B[35m"
#define CYN "\x1B[36m"
#define WHT "\x1B[37m"
#define PNK "\x1B[38;5;206m"
#define ORNG "\x1B[38;2;255;165;0m"
#define RESET "\x1B[0m"

Base::~Base(){};

Base *Base::generate(void) {
  std::srand(time(NULL));
  int randomValue = rand();
  if (randomValue < RAND_MAX / 3)
    return dynamic_cast<Base *>(new A);
  else if (randomValue < (RAND_MAX / 3) * 2)
    return dynamic_cast<Base *>(new B);
  else
    return dynamic_cast<Base *>(new C);
}

void Base::identify(Base *p) {
  Base *result;
  std::cout << PNK << "✨Identifying pointer type✨" << RESET << std::endl;
  result = dynamic_cast<A *>(p);
  if (result == NULL)
    std::cout << RED << "Base pointer wasn't A" << RESET << std::endl;
  else
    std::cout << GRN << "Base pointer was A" << RESET << std::endl;
  result = dynamic_cast<B *>(p);
  if (result == NULL)
    std::cout << RED << "Base pointer wasn't B" << RESET << std::endl;
  else
    std::cout << GRN << "Base pointer was B" << RESET << std::endl;
  result = dynamic_cast<C *>(p);
  if (result == NULL)
    std::cout << RED << "Base pointer wasn't C" << RESET << std::endl;
  else
    std::cout << GRN << "Base pointer was C" << RESET << std::endl;
}

void Base::identify(Base &p) {
  std::cout << BLU << "👻Identifying reference type👻" << RESET << std::endl;
  try {
    A &aResult = dynamic_cast<A &>(p);
    (void)aResult;
    std::cout << GRN << "Base reference was A" << RESET << std::endl;
  } catch (std::bad_cast &exception) {
    std::cout << RED << "Base reference wasn't A " << exception.what() << RESET
              << std::endl;
  }
  try {
    B &bResult = dynamic_cast<B &>(p);
    (void)bResult;
    std::cout << GRN << "Base reference was B" << RESET << std::endl;
  } catch (std::bad_cast &exception) {
    std::cout << RED << "Base reference wasn't B " << exception.what() << RESET
              << std::endl;
  }
  try {
    C &cResult = dynamic_cast<C &>(p);
    (void)cResult;
    std::cout << GRN << "Base reference was C" << RESET << std::endl;
  } catch (std::bad_cast &exception) {
    std::cout << RED << "Base reference wasn't C " << exception.what() << RESET
              << std::endl;
  }
}