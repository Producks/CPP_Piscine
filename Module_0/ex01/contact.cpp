#include "contact.hpp"

Contact::Contact(std::string first_name, std::string last_name, std::string nickname, std::string phone_number, std::string secret)
{
	this->first_name = first_name;
	this->last_name = last_name;
	this->nickname = nickname;
	this->phone_number = phone_number;
	this->secret = secret;
}

Contact::Contact(){}

std::string Contact::GetFirstName(){
	return this->first_name;
}

std::string Contact::GetLastName(){
	return this->last_name;
}

std::string Contact::GetNickName(){
	return this->nickname;
}

std::string Contact::GetPhoneNumber(){
	return this->phone_number;
}

std::string Contact::GetSecret(){
	return this->secret;
}

void Contact::Display()
{
	std::cout << "First name: " << this->first_name << std::endl;
	std::cout << "Last name: " << this->last_name << std::endl;
	std::cout << "Nickname: " << this->nickname << std::endl;
	std::cout << "Phone number: " << this->phone_number << std::endl;
	std::cout << "My darkess secret: " << this->secret << std::endl;
}
