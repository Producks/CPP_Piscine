#pragma once

#include <iostream>

enum type 
{   none = 0, 
    charType = 1, 
    intType = 2,
    floatType = 3,
		doubleType = 4,
		specialType = 5
};

class TypeConversion {
public:
  TypeConversion(const char *arg);
  TypeConversion(const TypeConversion &TypeConversion);
  ~TypeConversion();

  TypeConversion &operator=(const TypeConversion &TypeConversion);

  const std::string &getArgument() const;
  void setArgument(const char *arg);
	void setType();

	void isChar();
	void isInt();
	void isFloat();
	void isDouble();
	void isSpecial();

	void printConversion();
	void printChar();
	void printInt();
	void printFloat();
	void printDouble();

	const std::string printSpecialFloat() const;
	const std::string printSpecialDouble() const;
	const std::string printOverflow(const long int value) const;

	class EmptyArg : public std::exception{
		public:
			virtual const char *what() const throw();
	};
	class InvalidInput : public std::exception{
		public:
			virtual const char *what() const throw();
	};
	class StringTooLong : public std::exception{
		public:
			virtual const char *what() const throw();
	};

	class InvalidType : public std::exception{};
private:
  TypeConversion();
  std::string argument_;
	int type_;
	int precision_;
};