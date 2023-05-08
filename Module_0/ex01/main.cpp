#include <iostream>
#include <limits>
#include "contact.hpp"
#include "phonebook.hpp"
#include "colors.hpp"

int	main(int argc, char *argv[])
{
	std::cout << BLU << "✨~Welcome to my awesome phonebook~✨" << RESET << std::endl;
	std::cout << GRN << "Here a list of valid commands{ADD,SEARCH,EXIT}" << RESET << std::endl;
	std::string comment;
	PhoneBook phonebook;
	while (true)
	{
		std::cout << ORNG << "Please enter a command:" << RESET;
		std::getline(std::cin, comment);
		if (std::cin.fail())
			break ;
		if (comment == "ADD")
		{
			std::string first_name, last_name, nickname, phone_number, secret;
			std::cout << "Please enter the contact first name:";
			std::getline(std::cin, first_name);
			std::cout << "Please enter the contact last name:";
			std::getline(std::cin, last_name);
			std::cout << "Please enter the contact nickname:";
			std::getline(std::cin, nickname);
			std::cout << "Please enter the contact phone number:";
			std::getline(std::cin, phone_number);
			std::cout << "Please enter the contact darkest secret:";
			std::getline(std::cin, secret);
			if (first_name == "" || last_name == "" || phone_number == "" | secret == "" || nickname == "")
			{
				std::cout << RED << "One of the field was left empty" << RESET << std::endl;
			}
			else
			{
				Contact contact(first_name, last_name, nickname, phone_number, secret);
				phonebook.AddContact(contact);
			}
		}
		else if (comment == "SEARCH")
		{
			int	index;
			phonebook.DisplayContact();
			std::cout << PNK << "Please enter an Index:" << RESET;
			std::cin >> index;
			if (std::cin.fail()) 
				 std::cout << RED << "Invalid input. Please enter an integer.🤡" << RESET << std::endl;
			else if (index < 1 || index > 8)
				std::cout << RED << "Invalid index number: " << RESET << index << std::endl;
			else
				phonebook.DisplaySpecificContact(index);
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		else if (comment == "EXIT")
		{
			std::cout << MAG << "Buh bye" << RESET << std::endl;
			break ;
		}
		else
			std::cout << comment << RED << " Isn't a valid command" << RESET << std::endl; 
	}
}
