#include "TypeConversion.hpp"
#include <cctype>
#include <climits>
#include <cmath>
#include <iomanip>
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
  if (argument_.size() == 1 && std::isprint(argument_[0]) &&
      !std::isdigit(argument_[0]))
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
  if (argument_.size() > 11)
    throw StringTooLong();
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
  if (argument_[index] == '+' || argument_[index] == '-')
    index++;
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

void TypeConversion::printChar() {
  if (type_ == specialType)
    throw InvalidType();
  else if (type_ == charType)
    std::cout << "char: '" << getArgument() << "'" << std::endl;
  else if (type_ == intType) {
    long int intvar = strtol(argument_.c_str(), NULL, 0);
    if (intvar >= 32 && intvar <= 126)
      std::cout << "char: '" << static_cast<char>(intvar) << "'" << std::endl;
    else
      std::cout << "char:  Non displayable" << std::endl;
  } else if (type_ == floatType) {
    int floatvar = static_cast<int>(strtof(argument_.c_str(), NULL));
    if (floatvar >= 32 && floatvar <= 126)
      std::cout << "char: '" << static_cast<char>(floatvar) << "'" << std::endl;
    else
      std::cout << "char: Non displayable" << std::endl;
  } else {
    int doublevar = static_cast<int>(strtod(argument_.c_str(), NULL));
    if (doublevar >= 32 && doublevar <= 126)
      std::cout << "char: '" << static_cast<char>(doublevar) << "'"
                << std::endl;
    else
      std::cout << "char: Non displayable" << std::endl;
  }
}

void TypeConversion::printInt() {
  if (type_ == specialType)
    throw InvalidType();
  else if (type_ == charType)
    std::cout << "int: " << static_cast<int>(argument_[0]) << std::endl;
  else if (type_ == intType) {
    long int intvar = strtol(argument_.c_str(), NULL, 0);
    if (intvar > INT_MAX || intvar < INT_MIN)
      std::cout << "int: overflow" << std::endl;
    else
      std::cout << "int: " << atoi(argument_.c_str()) << std::endl;
  } else if (type_ == floatType)
    std::cout << "int: " << static_cast<int>(strtof(argument_.c_str(), NULL))
              << std::endl;
  else
    std::cout << "int: " << static_cast<int>(strtod(argument_.c_str(), NULL))
              << std::endl;
}

const std::string TypeConversion::printSpecialFloat() const {
  if (argument_ == "nanf" || argument_ == "nan")
    return "nanf";
  if (argument_ == "inf" || argument_ == "inff")
    return "inff";
  if (argument_ == "+inf" || argument_ == "+inff")
    return "+inff";
  else
    return "-inff";
}

const std::string TypeConversion::printOverflow(const long int value) const {
  if (value < 0)
    return "-inff";
  else
    return "+inff";
}

void TypeConversion::printFloat() {
  if (type_ == specialType)
    std::cout << "float: " << printSpecialFloat() << std::endl;
  else if (type_ == charType)
    std::cout << "float: " << static_cast<float>(argument_[0]) << ".0f"
              << std::endl;
  else if (type_ == intType) {
    long int intvar = strtol(argument_.c_str(), NULL, 0);
    if (intvar < INT_MIN || intvar > INT_MAX)
      std::cout << "float: " << printOverflow(intvar) << std::endl;
    else
      std::cout << "float: " << static_cast<float>(atoi(argument_.c_str()))
                << ".0f" << std::endl;
  } else if (type_ == floatType)
    std::cout << std::fixed << std::setprecision(10)
              << "float: " << strtof(argument_.c_str(), NULL) << "f"
              << std::endl;
  else if (type_ == doubleType)
    std::cout << std::fixed << std::setprecision(10) << "float: "
              << static_cast<float>(strtod(argument_.c_str(), NULL)) << "f"
              << std::endl;
}

const std::string TypeConversion::printSpecialDouble() const {
  if (argument_ == "nanf" || argument_ == "nan")
    return "nan";
  if (argument_ == "inf" || argument_ == "inff")
    return "inf";
  if (argument_ == "+inf" || argument_ == "+inff")
    return "+inf";
  else
    return "-inf";
}

void TypeConversion::printDouble() {
  if (type_ == specialType)
    std::cout << "double: " << printSpecialDouble() << std::endl;
  else if (type_ == charType)
    std::cout << "double: " << static_cast<double>(argument_[0]) << ".0"
              << std::endl;
  else if (type_ == intType) {
    long int intvar = strtol(argument_.c_str(), NULL, 0);
    if (intvar < INT_MIN || intvar > INT_MAX) {
      std::string hold = printOverflow(intvar);
      std::cout << "double: " << hold.substr(0, 4) << std::endl;
    } else
      std::cout << "double: " << static_cast<double>(atoi(argument_.c_str()))
                << ".0" << std::endl;
  } else if (type_ == floatType)
    std::cout << std::fixed << std::setprecision(10) << "double: "
              << static_cast<double>(strtof(argument_.c_str(), NULL))
              << std::endl;
  else if (type_ == doubleType)
    std::cout << std::fixed << std::setprecision(10)
              << "double: " << strtod(argument_.c_str(), NULL) << std::endl;
}

void TypeConversion::printConversion() {
  std::cout << "Converting this argument " << getArgument() << std::endl;
  try {
    printChar();
  } catch (std::exception &exception) {
    std::cout << "char: Impossible" << std::endl;
  }
  try {
    printInt();
  } catch (std::exception &exception) {
    std::cout << "int: Impossible" << std::endl;
  }
  try {
    printFloat();
  } catch (std::exception &exception) {
    std::cout << exception.what() << std::endl;
  }
  try {
    printDouble();
  } catch (std::exception &exception) {
    std::cout << exception.what() << std::endl;
  }
}
