#pragma once
#include <stack>
#include <iostream>

class RPN{
public:
	RPN();
	RPN(const RPN &rhs);
	~RPN();

	RPN &operator=(const RPN &rhs);

	void rpnCalculator(std::string input);
	bool isOperand(const char &c) const;
	void executeOperand(const char &c);
private:
	std::stack<int> stack_;
};