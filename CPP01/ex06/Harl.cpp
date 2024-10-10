/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajorge-p <ajorge-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 17:57:58 by ajorge-p          #+#    #+#             */
/*   Updated: 2024/10/10 10:56:31 by ajorge-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(){
	
	levels[0] = "DEBUG";
	levels[1] = "INFO";
	levels[2] = "WARNING";
	levels[3] = "ERROR";

	func[0] = &Harl::debug;
	func[1] = &Harl::info;
	func[2] = &Harl::warning;
	func[3] = &Harl::error;
	
}

Harl::~Harl(){
	std::cout << "Harl talked like Gnar and died " << std::endl;
}

void Harl::debug(void){
	std::cout << "Debug: Ovagarava!" << std::endl << std::endl;
}

void Harl::info(void){
	std::cout << "Info: Shargh!" << std::endl << std::endl;	
}

void Harl::warning(void){
	std::cout << "Warning: Shugi Shugi Shugi" << std::endl << std::endl;	
}

void Harl::error(void){
	std::cout << "Error: Vigishu!" << std::endl << std::endl;	
}

void Harl::complain(int i){
	for(int j = i ; j < 4 ; j++)
		(this->*func[j])();
	}


int Harl::assignNumber(std::string arg)
{
	if(arg.compare("DEBUG") == 0)
		return 0;
	else if(arg.compare("INFO") == 0)
		return 1;
	else if(arg.compare("WARNING") == 0)
		return 2;
	else if(arg.compare("ERROR") == 0)
		return 3;
	return -1;
}
