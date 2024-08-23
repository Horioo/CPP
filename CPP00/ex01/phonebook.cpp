/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajorge-p <ajorge-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 17:43:19 by ajorge-p          #+#    #+#             */
/*   Updated: 2024/08/23 17:23:02 by ajorge-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "phonebook.hpp"
#include "contact.hpp"

PhoneBook::PhoneBook(void){
	c_index = 0;
	max_index = 0;
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
	if(this->max_index != 8)
		this->max_index++;
}

void PrintColumn(const std::string &text, int width = 10) {
    if((int)text.length() >= width)
		std::cout << std::setw(width) << text.substr(0, width - 1) + "." << " |";
	else
		std::cout << std::setw(width) << text << " |";
}

void PhoneBook::PrintList(int i){
	PrintColumn(this->contact[i].GetFName());
	PrintColumn(this->contact[i].GetLName());
    PrintColumn(this->contact[i].GetNickname());
}

void PhoneBook::PrintInfo(int i){
	std::cout << "First Name: " << this->contact[i].GetFName() << std::endl;
	std::cout << "Last Name: " << this->contact[i].GetLName() << std::endl;
	std::cout << "NickName: " << this->contact[i].GetNickname() << std::endl;
	std::cout << "Phone Number: " << this->contact[i].GetPhoneNumber() << std::endl;
	std::cout << "Dark Secret: " << this->contact[i].GetDS() << std::endl;
}

void PhoneBook::SearchContact(){
	
	int display;
		/*Escreve os Cabeçalhos*/
	std::cout << std::right << "| ";
	PrintColumn("Index");
	PrintColumn("First Name");
    PrintColumn("Last Name");
    PrintColumn("NickName");
	std::cout << std::endl;
	/*Escreve a lista com parametros reduzidos*/
	for(int i = 0; i <= this->max_index - 1; i++){
		std::cout << std::right << "| "
		<< std::setw(10) << i << " |";
		PrintList(i);
		std::cout << std::endl;
	}
	/*Pede o numero do index e dá display a informação toda*/
	std::cout << "Index Number to Display" << std::endl;
	std::cin >> display;
	/*Verifica se não estão a inserir algo que dê conflicto com o tipo da variavel*/
	if (std::cin.fail() || display < 0) {
            std::cin.clear();
			std::cin.ignore(10000, '\n');
            std::cout << "Entrada inválida. Por favor, insira um número válido." << std::endl;
    }
	else {
		if(display >= c_index)
		{
			std::cout << "Wrong Index Dumb*** can't you see your own Screen??" << std::endl;
			return ;
		}
		PrintInfo(display);
	}
}

void PhoneBook::ExitProgram(){
	exit(0);
}