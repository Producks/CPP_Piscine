#include <iostream>
#include <fstream>

int	main(int argc, char *argv[])
{
	if (argc != 4)
	{
		std::cout << "Wrong number of arguments" << std::endl;
		return 0;
	}
	std::ifstream	file;
	file.open (argv[1], std::ifstream::in);
	if (!file.is_open())
	{
		std::cout << "Couldn't open the file pass by argument" << std::endl;
		return 1;
	}
	std::ofstream file_out;
    file_out.open("sedoutput", std::ofstream::out);
	std::string	word;
	while (std::getline(file, word))
	{
		std::cout << word << std::endl;
		// if (word == argv[2])
		// 	file_out << argv[3];
		// else
		// 	file_out << word;
	}
	file.close();
	file_out.close();
	return 0;
}
