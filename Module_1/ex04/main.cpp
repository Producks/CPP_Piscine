#include <iostream>
#include <fstream>

int	main(int argc, char *argv[])
{
	if (argc != 4)
	{
		std::cout << "Wrong number of arguments" << std::endl;
		return 0;
	}
	std::string filename(argv[1]);
	std::string stringOne(argv[2]);
	std::string stringTwo(argv[3]);
	std::string filenameReplace = filename + ".replace";
	std::ifstream myfile;
	myfile.open(filename);
	myfile.close();
}