/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajorge-p <ajorge-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 21:54:31 by ajorge-p          #+#    #+#             */
/*   Updated: 2025/02/12 11:36:48 by ajorge-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat") {
	std::cout << "Cat Default Class Constructor" << std::endl;
	this->brain = new Brain();
}

Cat::~Cat(){
	std::cout << "Cat Class Destructor" << std::endl;
	delete (this->brain);
}

Cat::Cat(const Cat &copy) : Animal() {
	this->type = copy.type;
	this->brain = new Brain(*copy.brain);
}

Cat &Cat::operator=(const Cat &copy){
	if (this != &copy) {
		this->type = copy.type;
		this->brain = new Brain(*copy.brain);
	}
	return *this;
}

void Cat::makeSound() const {
	std::cout << "Miauuuuuuuuuu" << std::endl;
}

Brain *Cat::getBrain(){
	return (this->brain);
}