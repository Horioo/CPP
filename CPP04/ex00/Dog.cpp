/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajorge-p <ajorge-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 21:58:48 by ajorge-p          #+#    #+#             */
/*   Updated: 2025/01/28 11:58:44 by ajorge-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("Dog") {
	std::cout << "Dog Default Class Constructor" << std::endl; 
}

Dog::~Dog(){
	std::cout << "Dog Class Destructor" << std::endl;
}

Dog::Dog(const Dog &copy) : Animal() {
	this->type = copy.type;
}

Dog &Dog::operator=(const Dog &copy) {
	this->type = copy.type;
	return *this;
}

void Dog::makeSound() const {
	std::cout << "Woof Woof!!" << std::endl;
}