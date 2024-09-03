/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajorge-p <ajorge-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 16:15:57 by ajorge-p          #+#    #+#             */
/*   Updated: 2024/09/03 16:55:55 by ajorge-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void Zombie::announce(){
	if(this->name.empty())
		std::cout << "New Zombie : BraiiiiiiinnnzzzZ..." << std::endl;
	else
		std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl; 
}

void Zombie::setName(std::string name){
	this->name = name;
}

std::string Zombie::getName(){

	if(this->name.empty())
		return "No Name";
	return this->name;
}
