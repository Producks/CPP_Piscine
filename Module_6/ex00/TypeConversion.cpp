#include "TypeConversion.hpp"
#include <cctype>
#include <cmath>
#include <string>

TypeConversion::TypeConversion() {}

TypeConversion::TypeConversion(const char *arg) : argument_(arg), type_(none) {}

TypeConversion::TypeConversion(const TypeConversion &rhs) { *this = rhs; }

TypeConversion &TypeConversion::operator=(const TypeConversion &rhs) {
  argument_ = rhs.getArgument();
  type_ = rhs.type_;
  return *this;
}

TypeConversion::~TypeConversion() {}

const std::string &TypeConversion::getArgument() const { return argument_; }

void TypeConversion::setArgument(const char *arg) { argument_ = arg; }

void TypeConversion::isChar() {
  if (argument_.size() == 1 && std::isprint(argument_[0]) && !std::isdigit(argument_[0]))
    type_ = charType;
}

void TypeConversion::isInt() {
  if (type_ != none)
    return;
  size_t index = 0;
  if (argument_[index] == '+' || argument_[index] == '-')
    index++;
  for (; index < argument_.size(); index++) {
    if (!std::isdigit(argument_[index]))
      return;
  }
  type_ = intType;
}

void TypeConversion::isFloat() {
  if (type_ != none || argument_.size() <= 2)
    return;
  size_t index = 0;
  while (argument_[index])
    index++;
  size_t back = index - 1;
  if (argument_[back] != 'f')
    return;
  bool dot = false;
  index = 0;
  if (argument_[index] == '+' || argument_[index] == '-')
    index++;
  for (; index < back; index++) {
    if (argument_[index] == '.') {
      if (dot)
        return;
      dot = true;
      continue;
    }
    if (!std::isdigit(argument_[index])) {
      return;
    }
  }
  if (dot)
    type_ = floatType;
}

void TypeConversion::isDouble() {
  if (type_ != none || argument_.size() <= 2)
    return;
  size_t index = 0;
  bool dot = false;
  for (; argument_[index]; index++) {
    if (argument_[index] == '.') {
      if (dot)
        return;
      dot = true;
      continue;
    }
    if (!std::isdigit(argument_[index])) {
      return;
    }
  }
  if (dot)
    type_ = doubleType;
}

void TypeConversion::isSpecial() {
  if (argument_ == "nanf" || argument_ == "nan" || argument_ == "-inff" ||
      argument_ == "+inff" || argument_ == "+inf" || argument_ == "-inf" ||
      argument_ == "inff" || argument_ == "inf") {
    type_ = specialType;
  }
}

void TypeConversion::setType() {
  if (argument_.empty())
    throw EmptyArg();
  isChar();
  isInt();
  isFloat();
  isDouble();
  isSpecial();
  if (type_ == none)
    throw InvalidInput();
}

void TypeConversion::printChar(){
	if (type_ == specialType)
		throw InvalidType();
	else if (type_ == charType)
		std::cout << "char: '" << getArgument() << "'" << std::endl;
	else if (type_ == intType){
		int intvar = atoi(argument_.c_str());
		if (intvar >= 0 && intvar <= 127)
			std::cout << "char: '" << static_cast<char>(intvar) << "'" << std::endl;
		else
			std::cout << "char:  Non displayable" << std::endl;
	}
	else if (type_ == floatType){
		int floatvar = static_cast<int>(atof(argument_.c_str()));
		if (floatvar >= 0 && floatvar <= 127)
			std::cout << "char: '" << static_cast<char>(floatvar) << "'" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
	}
	else{
		int doublevar = static_cast<int>(atof(argument_.c_str()));
		if (doublevar >= 0 && doublevar <= 127)
			std::cout << "char: '" << static_cast<char>(doublevar) << "'" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
	}
}

void TypeConversion::printInt(){
	if (type_ == specialType)
		throw InvalidType();
	else if (type_ == charType)
		std::cout << "int: " << static_cast<int>(argument_[0]) << std::endl;
	else if (type_ == intType)
		std::cout << "int: " << atoi(argument_.c_str()) << std::endl;
	else if (type_ == floatType)
		std::cout << "int: " << static_cast<int>(atof(argument_.c_str())) << std::endl;
	else
		std::cout << "int: " << static_cast<int>(atof(argument_.c_str())) << std::endl;
}

const std::string TypeConversion::printSpecialFloat() const{
	if (argument_ == "nanf" || argument_ == "nan")
		return "nanf";
	if (argument_ == "inf" || argument_ == "inff")
		return "inff";
	if (argument_ == "+inf" || argument_ == "+inff")
		return "+inff";
	else
		return "-inff";
}

void TypeConversion::printFloat(){
	if (type_ == specialType)
		std::cout << "float: " << printSpecialFloat() << std::endl;
	else if (type_ == charType)
		std::cout << "float: " << static_cast<float>(argument_[0]) << ".0f" << std::endl;
	else if (type_ == intType)
		std::cout << "float: " << static_cast<float>(atoi(argument_.c_str())) << ".0f" << std::endl;
	else if (type_ == floatType)
		std::cout << "float: " << static_cast<float>(atof(argument_.c_str())) << std::endl;
	else if (type_ == doubleType)
		std::cout << "float: " << static_cast<float>(atof(argument_.c_str())) << std::endl;
}

const std::string TypeConversion::printSpecialDouble() const{
	if (argument_ == "nanf" || argument_ == "nan")
		return "nan";
	if (argument_ == "inf" || argument_ == "inff")
		return "inf";
	if (argument_ == "+inf" || argument_ == "+inff")
		return "+inf";
	else
		return "-inf";
}

void TypeConversion::printDouble(){
	if (type_ == specialType)
		std::cout << "double: " << printSpecialDouble() << std::endl;
	else if (type_ == charType)
		std::cout << "double: " << static_cast<double>(argument_[0]) << ".0" << std::endl;
	else if (type_ == intType)
		std::cout << "double: " << static_cast<double>(atoi(argument_.c_str())) << ".0" << std::endl;
	else if (type_ == floatType)
		std::cout << "double: " << static_cast<double>(atof(argument_.c_str())) << std::endl;
	else if (type_ == doubleType)
		std::cout << "double: " << static_cast<double>(atof(argument_.c_str())) << std::endl;
}

void TypeConversion::printConversion(){
	std::cout << "Converting this argument " << getArgument() << std::endl;
	try{
		printChar();
	}
	catch (std::exception &exception){
		std::cout << "char: Impossible" << std::endl; 
	}
	try{
		printInt();
	}
	catch (std::exception &exception){
		std::cout << "int: Impossible" << std::endl;
	}
	try{
		printFloat();
	}
	catch (std::exception &exception){
		std::cout << exception.what() << std::endl;
	}
	try{
		printDouble();
	}
	catch (std::exception &exception){
		std::cout << exception.what() << std::endl;
	}
}
