/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajorge-p <ajorge-p@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 21:59:41 by ajorge-p          #+#    #+#             */
/*   Updated: 2025/01/27 22:35:04 by ajorge-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(const std::string &typeName) : type(typeName){
	std::cout << "WrongAnimal Class Constructor" << std::endl; 
}

WrongAnimal::WrongAnimal(){
	std::cout << "WrongAnimal Default Class Constructor" << std::endl; 
}

WrongAnimal::~WrongAnimal(){
	std::cout << "WrongAnimal Class Destructor" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy){
	*this = copy;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &copy){
	this->type = copy.type;
	return *this;
}

void WrongAnimal::makeSound() const{
	std::cout << "Wrong Rwarrrrrrrrr!!" << std::endl;
}

std::string WrongAnimal::getType() const {
	return this->type;
}