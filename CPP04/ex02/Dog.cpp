/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajorge-p <ajorge-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 21:58:48 by ajorge-p          #+#    #+#             */
/*   Updated: 2025/02/12 11:40:21 by ajorge-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("Dog") {
	std::cout << "Dog Default Class Constructor" << std::endl; 
	this->brain = new Brain();
}

Dog::~Dog(){
	std::cout << "Dog Class Destructor" << std::endl;
	delete (this->brain);
}

Dog::Dog(const Dog &copy) : Animal() {
	this->type = copy.type;
	this->brain = new Brain(*copy.brain);
}

Dog &Dog::operator=(const Dog &copy) {
	if (this != &copy) {
		this->type = copy.type;
		this->brain = new Brain(*copy.brain);
	}
	return *this;
}

void Dog::makeSound() const {
	std::cout << "Woof Woof!!" << std::endl;
}

Brain *Dog::getBrain(){
	return (this->brain);
}