/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajorge-p <ajorge-p@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 17:43:19 by ajorge-p          #+#    #+#             */
/*   Updated: 2024/08/22 21:16:51 by ajorge-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "phonebook.hpp"
#include "contact.hpp"

PhoneBook::PhoneBook(void){
	c_index = 0;
	std::cout << "PhoneBook ready to Register" << std::endl;
}

PhoneBook::~PhoneBook(void){
	std::cout << "PhoneBook deleted" << std::endl;
}

void PhoneBook::AddContact(){

	std::string value;

	if(this->c_index == 8)
		this->c_index = 0;
	std::cout << "Insert First Name" << std::endl;
	std::cin >> value;
	this->contact[this->c_index].SetFName(value);
	std::cout << "Insert Last Name" << std::endl;
	std::cin >> value;
	this->contact[this->c_index].SetLName(value);
	std::cout << "Insert NickName" << std::endl;
	std::cin >> value;
	this->contact[this->c_index].SetNickname(value);
	std::cout << "Insert PhoneNumber" << std::endl;
	std::cin >> value;
	this->contact[this->c_index].SetPhoneNumber(value);
	std::cout << "Insert Darkest Secret" << std::endl;
	std::cin >> value;
	this->contact[this->c_index].SetDS(value);
	this->c_index++;
}

void PhoneBook::SearchContact(){
	
	int display;
	
	std::cout << std::right << "| " << std::setw(10) << "Index |" << std::setw(10) << "First Name | " << std::setw(10) << "Last Name |" << std::setw(10) << "NickName" << " |" << std::endl;
	for(int i = 0; i <= this->c_index - 1; i++)
		std::cout << std::right << "|" << std::setw(10) << i << "|" << std::setw(10) << this->contact[i].GetFName() <<  " |" << std::setw(10) << this->contact[i].GetLName() << " |" << std::setw(10) << this->contact[i].GetNickname() << " |" << std::endl;
	
	std::cout << "Index Number to Display" << std::endl;
	std::cin >> display;
	if(display >= c_index)
	{
		std::cout << "Wrong Index Dumb*** can't you see the monitor??" << std::endl;
		return ;
	}
	std::cout << std::right << "|" << std::setw(10) << display << "|" << std::setw(10) << this->contact[display].GetFName() <<  " |" << std::setw(10) << this->contact[display].GetLName() << " |" << std::setw(10) << this->contact[display].GetNickname() << " |" << std::endl;
}

void PhoneBook::ExitProgram(){
	exit(0);
}