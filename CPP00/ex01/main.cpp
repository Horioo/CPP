/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajorge-p <ajorge-p@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 18:18:14 by ajorge-p          #+#    #+#             */
/*   Updated: 2024/08/22 18:45:03 by ajorge-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "phonebook.hpp"

int main(void)
{
	PhoneBook PhoneBook;
	std::string cmd;

	while(1)
	{
		std::cout << "Input a Command (Add, Search, Exit)" << std::endl;
		std::cin >> cmd;
		if(cmd == "Add")
			PhoneBook.AddContact();
		else if(cmd == "Search")
			PhoneBook.SearchContact();
		else if(cmd == "Exit")
			PhoneBook.ExitProgram();
		else
			std::cout << "Wrong Command" << std::endl;
	}
}