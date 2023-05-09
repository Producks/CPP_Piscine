#include <iostream>
#include <fstream>
#include <cstring>

static	std::string	replacementName(std::string name)
{
	std::string		file_name_replacement;
	size_t			position;

	file_name_replacement = name;
	position = file_name_replacement.find('.');
	return file_name_replacement.substr(0, position) + ".replacement";
}

int	main(int argc, char *argv[])
{
	std::ifstream	file;
	std::ofstream	output_file;
	std::string		line;
	size_t			position;

	if (argc != 4)
	{
		std::cout << "Wrong number of arguments" << std::endl;
		return 1;
	}
	if (!std::strlen(argv[1]) || !std::strlen(argv[2]))
	{
		std::cout << "Argument can't be empty" << std::endl;
		return 1;
	}
	file.open (argv[1], std::ifstream::in);
	if (!file.is_open())
	{
		std::cout << "Couldn't open the file pass by argument" << std::endl;
		return 1;
	}
    output_file.open(replacementName(argv[1]), std::ofstream::out);
	if (!output_file.is_open())
	{
		std::cout << "Couldn't create the output file" << std::endl;
		file.close();
		return 1;
	}
	while (std::getline(file, line))
	{
		position = 0;
		while ((position = line.find(argv[2], position)) != std::string::npos)
		{
			line = line.substr(0, position) + argv[3] + line.substr(position + std::strlen(argv[2]));
			position += std::strlen(argv[3]);
		}
		if (file.eof() == false)
			output_file << line << std::endl;
		else
			output_file << line;
	}
	file.close();
	output_file.close();
	return 0;
}
