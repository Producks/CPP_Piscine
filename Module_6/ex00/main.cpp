#include "TypeConversion.hpp"
#include <iostream>

int main(int argc, char **argv) {
  if (argc == 1) {
    std::cout << "No arguments were provided" << std::endl;
    return 1;
  }
  try {
    TypeConversion conversion(argv[1]);
    for (int index = 1; index < argc; index++) {
      conversion.setArgument(argv[index]);
			conversion.setType();
			conversion.printConversion();
    }
  }
	catch (std::exception &exception){
    std::cout << exception.what() << std::endl;
  }
  return 0;
}