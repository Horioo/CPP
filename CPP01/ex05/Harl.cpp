/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajorge-p <ajorge-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 17:57:58 by ajorge-p          #+#    #+#             */
/*   Updated: 2024/10/10 09:59:40 by ajorge-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(){
	
	levels[0] = "debug";
	levels[1] = "info";
	levels[2] = "warning";
	levels[3] = "error";

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
