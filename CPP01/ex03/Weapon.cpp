/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajorge-p <ajorge-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 08:56:20 by ajorge-p          #+#    #+#             */
/*   Updated: 2024/10/08 11:40:36 by ajorge-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(void){
	
}

Weapon::Weapon(std::string type){
	this->type = type;
}

Weapon::~Weapon(void){
	std::cout << "Weapon Destroyed" << std::endl;
}

void Weapon::setType(std::string newType){
	this->type = newType;
}

// Ao utilizar a referenciacao conseguimos obter o
// Endereco de memoria do Type e assim nao se perde informacao
// E e tambem possivel alterar o valor 

const std::string &Weapon::getType(){
	std::string &ref = this->type;
	return ref;
}