/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajorge-p <ajorge-p@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 21:58:48 by ajorge-p          #+#    #+#             */
/*   Updated: 2025/01/27 22:26:21 by ajorge-p         ###   ########.fr       */
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
	*this = copy;
}

Dog &Dog::operator=(const Dog &copy) {
	this->type = copy.type;
	return *this;
}

void Dog::makeSound() const {
	std::cout << "Woof Woof!!" << std::endl;
}