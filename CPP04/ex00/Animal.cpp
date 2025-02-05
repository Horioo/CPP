/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajorge-p <ajorge-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 10:53:10 by ajorge-p          #+#    #+#             */
/*   Updated: 2025/02/05 11:03:38 by ajorge-p         ###   ########.fr       */
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
	this->type = copy.type;
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