/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajorge-p <ajorge-p@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 22:29:56 by ajorge-p          #+#    #+#             */
/*   Updated: 2025/01/27 22:30:57 by ajorge-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat") {
	std::cout << "WrongCat Default Class Constructor" << std::endl; 
}

WrongCat::~WrongCat(){
	std::cout << "WrongCat Class Destructor" << std::endl;
}

WrongCat::WrongCat(const WrongCat &copy) : WrongAnimal() {
	*this = copy;
}

WrongCat &WrongCat::operator=(const WrongCat &copy){
	this->type = copy.type;
	return *this;
}

void WrongCat::makeSound() const {
	std::cout << "Mehhhhhhhhhhhhhh" << std::endl;
}