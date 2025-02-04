/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajorge-p <ajorge-p@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 17:57:58 by ajorge-p          #+#    #+#             */
/*   Updated: 2025/02/04 22:16:21 by ajorge-p         ###   ########.fr       */
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

void Harl::complain(std::string level){
	for(int i = 0; i < 4 ;i++)
	{
		if(this->levels[i] == level)
			(this->*func[i])();
	}
}
