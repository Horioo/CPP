/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajorge-p <ajorge-p@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 21:44:55 by ajorge-p          #+#    #+#             */
/*   Updated: 2025/01/27 22:46:19 by ajorge-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("") {
	std::cout << "Animal Default Class Constructor" << std::endl;
}

Animal::Animal(const std::string &typeName) : type(typeName) {
	std::cout << "Animal Class Constructor" << std::endl;
}

Animal::~Animal(){
	std::cout << "Animal Class Destructor" << std::endl;
}

Animal::Animal(const Animal &copy){
	*this = copy;
}

Animal &Animal::operator=(const Animal &copy){
	this->type = copy.type;
	return *this;
}

void Animal::makeSound() const {
	std::cout << "MUHHHHHHHHHHHHHHHHHHHHH" << std::endl;
}

std::string Animal::getType() const {
	return this->type;
}