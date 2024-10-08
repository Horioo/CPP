/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajorge-p <ajorge-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 08:42:32 by ajorge-p          #+#    #+#             */
/*   Updated: 2024/10/08 08:52:13 by ajorge-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(void)
{
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string &stringREF = str;

	std::cout << "Memory Address da String " << &str << std::endl;
	std::cout << "Memory Address do Pointer para a String " << &stringPTR << std::endl;
	std::cout << "Memory Address da Referencia da String " << &stringREF << std::endl;

	std::cout << std::endl;
	std::cout << "Print dos valores" << std::endl;
	std::cout << std::endl;
	
	std::cout << "Valor da String " << str << std::endl;
	std::cout << "Valor do Pointer para a String " << stringPTR << std::endl;
	std::cout << "Valor da Referencia da String " << stringREF << std::endl;	
}