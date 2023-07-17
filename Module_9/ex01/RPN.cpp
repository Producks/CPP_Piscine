#include "RPN.hpp"
#include <iostream>
#include <ctype.h>
#include <stdexcept>

using std::endl;
using std::cout;

RPN::RPN(){}

RPN::RPN(const RPN &rhs) { *this = rhs; }

RPN &RPN::operator=(const RPN &rhs) { (void)rhs; return *this; }

RPN::~RPN(){}

bool RPN::isOperand(const char &c) const{
	if (c == '+' || c == '-' || c == '*' || c == '/')
		return true;
	return false;
}

void RPN::executeOperand(const char &c){
	if (stack_.size() < 2)
		throw std::runtime_error("Invalid syntax for postfix notation");
	int registerOne = stack_.top();
	stack_.pop();
	int registerTwo = stack_.top();
	stack_.pop();
	int result = 0;
	switch (c){
		case '+':
			result = registerTwo + registerOne;
			break;
		case '-':
			result = registerTwo - registerOne;
			break;
		case '*':
			result = registerTwo * registerOne;
			break;
		case '/':
			if (!registerOne)
				throw std::logic_error("Can't divive by 0");
			result = registerTwo / registerOne;
			break;
	}
	stack_.push(result);
}

void RPN::rpnCalculator(std::string input) {
  if (input.empty() || input.find_first_of("+-*/") == std::string::npos) {
    cout << "Invalid syntax for postfix notation" << endl;
    return;
  }
  try {
    for (std::string::iterator it = input.begin(); it != input.end(); ++it)
		{
      char c = *it;
      if (isdigit(c))
			{
				stack_.push(c - 48);
				if (stack_.size() > 3)
					throw std::runtime_error("Invalid syntax for postfix notation");
			}
      else if (isOperand(c))
        executeOperand(c);
      else if (c == ' ')
        continue;
      else
        throw std::runtime_error("Found invalid character");
    }
		if (stack_.size() > 1)
			throw std::runtime_error("Invalid syntax for postfix notation");
    cout << stack_.top() << endl;
    stack_.pop();
  } catch (std::exception &exception) {
		cout << exception.what() << endl;
    while (!stack_.empty())
      stack_.pop();
  }
}