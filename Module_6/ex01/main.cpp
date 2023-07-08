#include <iostream>
#include <stdint.h>

/*
	uintptr_t is an unsigned integer large enough to hold any ptr value

	How reinterpret cast works behind the hood:

		uint8_t foo = 128;
		foo is also equal to this behind the hood: 1000 0000

		uint16_t footwo = 0;
		footwo is equal to this behind the hood: 0000 0000 0000 0000
		if we reinterpret cast foo into foo2 it won't do a conversion, it will literally put bit by bit:
		footwo = reintrepetcat<uint16_t>(foo);
		which result to:
		0000 0000 1000 0000
*/

struct Data{
	std::string password;
};

static Data *deserialize(uintptr_t raw){
	return reinterpret_cast<Data*>(raw);
}

static uintptr_t serialize(Data* ptr){
	return reinterpret_cast<uintptr_t>(ptr);
}

int main(void)
{
	Data secret;
	Data *ptr = &secret;
	Data *ptrTwo = NULL;
	uintptr_t raw;

	secret.password = "42";
	std::cout << "Data pointer adress before sereliazation is " << ptr << std::endl;
	raw = serialize(ptr);
	std::cout << "After serelization " << raw << std::endl;
	ptrTwo = deserialize(raw);
	std::cout << "After deserialiation " << ptrTwo << std::endl;
	std::cout << "The password is " << ptrTwo->password << std::endl;
}
