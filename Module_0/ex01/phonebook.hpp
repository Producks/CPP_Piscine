#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "contact.hpp"

# define MAX_AMOUNT_CONTACTS 8

class PhoneBook
{
	public:
	PhoneBook();
	void AddContact(Contact contact);
	void DisplayContact();
	void DisplaySpecificContact(int index);

	private:
	Contact contacts[MAX_AMOUNT_CONTACTS];
	uint8_t	add_contact_index;
	uint8_t	current_amount_contact;
};

#endif