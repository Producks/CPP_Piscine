#include <iostream>
#include "contact.hpp"
#include "phonebook.hpp"

int	main(int argc, char *argv[])
{
	std::string comment;
	PhoneBook phonebook;
	std::cout << "Welcome to my awesome phonebook!" << std::endl;
	while (comment != "EXIT")
	{
		std::cout << "Please enter a command:";
		std::cin >> comment;
		if (comment == "ADD")
		{
			std::string first_name, last_name, nickname, phone_number, secret;
			std::cout << "Please enter the first name:";
			std::cin >> first_name;
			std::cout << "Please enter the last name:";
			std::cin >> last_name;
			std::cout << "Please enter your nickname:";
			std::cin >> nickname;
			std::cout << "Please enter your phone number:";
			std::cin >> phone_number;
			std::cout << "Please enter your darkest secret:";
			std::cin >> secret;
			if (first_name == "" || last_name == "" || phone_number == "" | secret == "" || nickname == ""){
				std::cout << "One of the field was empty";
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
			std::cout << "Please enter an Index:";
			std::cin >> index;
			if (std::cin.fail()) 
			{
				 std::cin.clear();
				 std::cin.ignore();
				 std::cout << "Invalid input. Please enter an integer.🤡" << std::endl;
			}
			phonebook.DisplaySpecificContact(index);
		}
	}
}
