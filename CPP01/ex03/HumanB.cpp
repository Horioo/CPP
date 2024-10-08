/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajorge-p <ajorge-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 09:52:10 by ajorge-p          #+#    #+#             */
/*   Updated: 2024/10/08 11:39:22 by ajorge-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : name(name){
	this->weapon = 0;
}

HumanB::~HumanB(){
	std::cout << this->name << " Neutralized" << std::endl; 
}

void HumanB::attack(void){
	if(this->weapon == 0)
		std::cout << this->name << " attacks with their Hands" << std::endl;
	else
		std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
}

// Usar Referencia faz com que seja possivel alterar
// os valores sem perder informacao.
// Usando o endereco que esta na memoria para localizar
// o que tem de ser alterado

void HumanB::setWeapon(Weapon& weapon){
	this->weapon = &weapon;
}