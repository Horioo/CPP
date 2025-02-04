/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajorge-p <ajorge-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 21:44:55 by ajorge-p          #+#    #+#             */
/*   Updated: 2025/01/28 11:43:20 by ajorge-p         ###   ########.fr       */
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
	std::cout << "Copy Constructor" << std::endl;
	*this = copy;
}

Animal &Animal::operator=(const Animal &copy){
	std::cout << "Copy Operator" << std::endl;
	this->type = copy.type;
	return *this;
}

void Animal::makeSound() const {
	std::cout << "MUHHHHHHHHHHHHHHHHHHHHH" << std::endl;
}

std::string Animal::getType() const {
	return this->type;
}