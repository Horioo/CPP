/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajorge-p <ajorge-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 11:35:28 by ajorge-p          #+#    #+#             */
/*   Updated: 2025/03/11 11:40:26 by ajorge-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(){
	std::cout << "ScalarConverter Default Constructor" << std::endl;
}

ScalarConverter::~ScalarConverter(){
	std::cout << "ScalarConverter Destructor" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &other){
	std::cout << "ScalarConverter Copy Constructor" << std::endl;	
	(void)other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &copy){
	(void)copy;
	if(this != &copy)
		std::cout << "ScalarConverter Copy Operator" << std::endl;
	return *this;
}

void ScalarConverter::convert(const std::string &value){
	
	int type = findType(value);
	
	switch (type)
	{
	case 0:
		specialCases(value);
		break;
	case 1:
		printInt(value);
		break;
	case 2:
		printFloat(value);
		break;
	case 3:
		printDouble(value);
		break;
	case 4:
		printChar(value[0]);
		break;
	default:
		std::cout << "Invalid Input :D" << std::endl;
		break;
	}
}

