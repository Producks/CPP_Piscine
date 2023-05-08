#include <iomanip>
#include "phonebook.hpp"

PhoneBook::PhoneBook()
{
	this->add_contact_index = 0;
	this->current_amount_contact = 0;
}

void PhoneBook::AddContact(Contact contact)
{
	this->contacts[this->add_contact_index] = contact;
	if (this->current_amount_contact < MAX_AMOUNT_CONTACTS)
		this->current_amount_contact++;
	this->add_contact_index = (this->add_contact_index + 1) % MAX_AMOUNT_CONTACTS;
}

static std::string	trunc_str(std::string string)
{
	if (string.length() <= 10)
		return (string);
	else
		return (string.substr(0, 9) + ".");
}

void PhoneBook::DisplayContact()
{
	for (int index = 0; index < this->current_amount_contact; index++)
	{
		std::cout << std::setw(10) << std::right << index + 1;
		std::cout << "|";
		std::cout << std::setw(10) << std::right << trunc_str(this->contacts[index].GetFirstName());
		std::cout << "|";
		std::cout << std::setw(10) << std::right << trunc_str(this->contacts[index].GetLastName());
		std::cout << "|";
		std::cout << std::setw(10) << std::right << trunc_str(this->contacts[index].GetNickName());
		std::cout << std::endl;
	}
}

void PhoneBook::DisplaySpecificContact(int index)
{
	if (index > 8 || index < 1)
		std::cout << "Index is out of range 🤡" << std::endl;
	else if (index > this->current_amount_contact)
		std::cout << "There no entry for that index" << std::endl;
	else
		this->contacts[index - 1].Display();
}