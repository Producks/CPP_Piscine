#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>

class Contact
{
	public:
	std::string first_name, last_name, nickname, phone_number, secret;
	Contact(std::string first_name, std::string last_name, std::string nickname, std::string phone_number, std::string secret);
	Contact();
	void Display();
};

#endif