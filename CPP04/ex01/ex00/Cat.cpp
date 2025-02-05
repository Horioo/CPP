/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajorge-p <ajorge-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 21:54:31 by ajorge-p          #+#    #+#             */
/*   Updated: 2025/01/28 11:58:39 by ajorge-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat") {
	std::cout << "Cat Default Class Constructor" << std::endl; 
}

Cat::~Cat(){
	std::cout << "Cat Class Destructor" << std::endl;
}

Cat::Cat(const Cat &copy) : Animal() {
	this->type = copy.type;
}

Cat &Cat::operator=(const Cat &copy){
	this->type = copy.type;
	return *this;
}

void Cat::makeSound() const {
	std::cout << "Miauuuuuuuuuu" << std::endl;
}