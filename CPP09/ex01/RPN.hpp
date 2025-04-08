#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <stdlib.h>

class RPN {

	private:
	std::stack<int>stk;

	public:
	RPN(std::string args);
	~RPN();
	RPN(const RPN &other);
	RPN &operator=(const RPN &copy);

	int checkRPN(std::string& args);
};

#endif