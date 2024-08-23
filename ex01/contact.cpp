/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajorge-p <ajorge-p@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 18:36:48 by ajorge-p          #+#    #+#             */
/*   Updated: 2024/08/22 21:15:37 by ajorge-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "contact.hpp"

Contact::Contact(void){
}

Contact::~Contact(void){
	std::cout << "Contact deleted" << std::endl;
}

//Setters
void	Contact::SetFName(const std::string &str){
	this->f_name = str;
}

void	Contact::SetLName(const std::string &str){
	this->l_name = str;
}

void	Contact::SetNickname(const std::string &str){
	this->nickname = str;
}

void	Contact::SetPhoneNumber(const std::string &str){
	this->phone_number = str;
}

void	Contact::SetDS(const std::string &str){
	this->dark_secret = str;
}

//Getters
std::string	Contact::GetFName(){
	return (this->f_name);
}

std::string	Contact::GetLName(){
	return(this->l_name);
}

std::string	Contact::GetNickname(){
	return(this->nickname);
}

std::string	Contact::GetPhoneNumber(){
	return(this->phone_number);
}

std::string	Contact::GetDS(){
	return(this->dark_secret);
}