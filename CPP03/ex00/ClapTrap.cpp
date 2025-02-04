/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajorge-p <ajorge-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 17:56:40 by ajorge-p          #+#    #+#             */
/*   Updated: 2025/01/28 11:47:39 by ajorge-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : hp(10), ep(10), ad(0){
	
}

ClapTrap::ClapTrap(std::string name) : name(name), hp(10), ep(10), ad(0){
	std::cout << "Constructor Called" << std::endl;
}

ClapTrap::~ClapTrap(){
	std::cout << "Destructor Called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy){
	std::cout << "Copy Constructor Called" << std::endl;
	this->name = copy.name;
	this->hp = copy.hp;
	this->ep = copy.ep;
	this->ad = copy.ad;	
}

ClapTrap &ClapTrap::operator=(const ClapTrap &copy){
	std::cout << "Copy operator Called" << std::endl;
	if(this != &copy)
	{
		this->name = copy.name;
		this->hp = copy.hp;
		this->ep = copy.ep;
		this->ad = copy.ad;	
	}
	return *this;
}

void ClapTrap::attack(const std::string& target){
	if(this->ep > 0)
	{
		std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->ad << " points of damage!" << std::endl;
		this->ep--;
	}
	else
		std::cout << "No Energy!!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount){
	if(this->hp <= amount)
		this->hp = 0;
	else
		this->hp -= amount;
	this->ep--;
	if(this->hp == 0)
		std::cout << "ClapTrap " << this->name << " is dead!!" << std::endl;
	else
		std::cout << "ClapTrap " << this->name << " took " << amount << " damage / HP = " << this->hp << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount){
	if(this->ep > 0)
	{
		if(this->hp == 0)
			std::cout << "ClapTrap " << this->name << " is dead and cant be repaired" << std::endl;
		else
		{
			std::cout << "ClapTrap " << this->name << " repaired for " << amount << " HP / HP = " << this->hp + amount << std::endl;
			this->hp += amount;
			this->ep--;
		}
	}
	else
		std::cout << "No Energy!!" << std::endl;
}

