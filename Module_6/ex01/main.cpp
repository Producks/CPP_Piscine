#include <iostream>
#include <stdint.h>

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

/*
        uintptr_t is an unsigned integer large enough to hold any ptr value

        How reinterpret cast works behind the hood:

                uint8_t foo = 128;
                foo is also equal to this behind the hood: 1000 0000

                uint16_t footwo = 0;
                footwo is equal to this behind the hood: 0000 0000 0000 0000
                if we reinterpret cast foo into foo2 it won't do a conversion,
   it will literally put bit by bit: footwo = reintrepetcat<uint16_t>(foo);
                which result to:
                0000 0000 1000 0000
*/

struct Data {
  std::string password;
};

static Data *deserialize(uintptr_t raw) {
  return reinterpret_cast<Data *>(raw);
}

static uintptr_t serialize(Data *ptr) {
  return reinterpret_cast<uintptr_t>(ptr);
}

int main(void) {
  Data secret;
  Data *ptr = &secret;
  Data *ptrTwo = NULL;
  uintptr_t raw;

  secret.password = "42password";
  std::cout << "Data pointer adress before serialization is " << MAG << ptr
            << RESET << std::endl;
  raw = serialize(ptr);
  std::cout << "After serialization " << RED << raw << RESET << std::endl;
  ptrTwo = deserialize(raw);
  std::cout << "After deserialization " << MAG << ptrTwo << RESET << std::endl;
  std::cout << "The password is " << GRN << ptrTwo->password << RESET
            << std::endl;
}
