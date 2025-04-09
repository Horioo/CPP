/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajorge-p <ajorge-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 20:03:49 by ajorge-p          #+#    #+#             */
/*   Updated: 2025/04/09 12:21:44 by ajorge-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(std::string args){
	std::cout << "RPN Default Constructor" << std::endl;

	if(args.empty())
	{
		std::cerr << "Cant be Empty" << std::endl;	
		return ;
	} 
	
	if(checkRPN(args))
	{
		int i = 0;
		int n1;
		int n2;
		
		while(args[i])
		{
			switch(args[i])
			{
				case '+':
					n2 = this->stk.top();
					this->stk.pop();
					n1 = this->stk.top();
					this->stk.pop();
					this->stk.push(n1 + n2);
					break;
				case '-':
					n2 = this->stk.top();
					this->stk.pop();
					n1 = this->stk.top();
					this->stk.pop();
					this->stk.push(n1 - n2);
					break;
				case '*':
					n2 = this->stk.top();
					this->stk.pop();
					n1 = this->stk.top();
					this->stk.pop();
					this->stk.push(n1 * n2);
					break;
				case '/':
					n2 = this->stk.top();
					this->stk.pop();
					n1 = this->stk.top();
					this->stk.pop();
					if(n2 == 0)
					{
						std::cerr << "\033[1;31mDivision by 0 is impossible\033[0m" << std::endl;
						return ;
					}
					this->stk.push(n1 / n2);
					break;
				case ' ':
					break;
				default:
					this->stk.push(args[i] - '0');
			}
			i++;
		}
		std::cout << "\033[1;32mFinal Result = " << this->stk.top() << "\033[0m" << std::endl;
	}
	else
		std::cerr << "\033[1;31mInvalid Expression\033[0m" << std::endl;
}

RPN::~RPN(){
	std::cout << "RPN Default Destructor" << std::endl;
}	

RPN::RPN(const RPN &other){
	std::cout << "RPN Copy Constructor" << std::endl;
	this->stk = other.stk;
}

RPN &RPN::operator=(const RPN &copy){
	if(this != &copy){
		std::cout << "RPN Assignment Operator" << std::endl;
		this->stk = copy.stk;
	}
	return *this;
}

int RPN::checkRPN(std::string& args){
	int count = 0;

	for(size_t i = 0; i < args.size(); i += 2)
	{
		if(std::isdigit(args[i]))
			count++;
		else if(args[i] == '+' || args[i] == '-' || args[i] == '*' || args[i] == '/'  )
		{
			if(count < 2)
				return 0;
			count--;
		}
		else
			return 0;
	}
	return count == 1;
}
