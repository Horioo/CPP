/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajorge-p <ajorge-p@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 20:14:16 by ajorge-p          #+#    #+#             */
/*   Updated: 2025/01/20 21:34:05 by ajorge-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
	this->hp = 100;
	this->ep = 100;
	this->ad = 30;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	std::cout << "FragTrap Constructor Called" << std::endl;
	this->hp = 100;
	this->ep = 100;
	this->ad = 30;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap Destructor Called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &copy): ClapTrap() {
	std::cout << "FragTrap Copy Constructor Called" << std::endl;
	*this = copy;
}

FragTrap &FragTrap::operator=(const FragTrap &copy){
	if(this != &copy)
	{
		this->name = copy.name;
		if(this->hp > 4000000000)
			this->hp = 0;
		else
			this->hp = copy.hp;
		this->ep = copy.ep;
		this->ad = copy.ad;
	}
	return *this;
}

void FragTrap::attack(const std::string& target){
	if(this->ep > 0)
	{
		std::cout << "FragTrap " << this->name << " attacks " << target << ", causing " << this->ad << " points of damage!" << std::endl;
		this->ep--;
	}
	else
		std::cout << "No Energy!!" << std::endl;
}

void FragTrap::showStats(){
	std::cout << "FragTrap name = " << this->name << " | hp = " << this->hp << " | ep = " << this->ep << " | ad = " << this->ad << std::endl; 
}

void FragTrap::takeDamage(unsigned int amount){
	this->hp -= amount;
	this->ep--;
	if(this->hp <= 0 || hp > 4000000000)
		std::cout << "FragTrap " << this->name << " is dead!!" << std::endl;
	else
		std::cout << "FragTrap " << this->name << " took " << amount << " damage / HP = " << this->hp << std::endl;
	
}

void FragTrap::beRepaired(unsigned int amount){
	if(this->ep > 0)
	{
		if(this->hp <= 0 || hp > 4000000000)
			std::cout << "FragTrap " << this->name << " is dead and cant be repaired" << std::endl;
		else
		{
			std::cout << "FragTrap " << this->name << " repaired for " << amount << " HP / HP = " << this->hp + amount << std::endl;
			this->hp += amount;
			this->ep--;
		}
			
	}
	else
		std::cout << "No Energy!!" << std::endl;
}

void FragTrap::highFivesGuys(void){
	
	if(this->ep > 0)
	{
		if(this->hp <= 0 || hp > 4000000000)
			std::cout << "FragTrap " << this->name << " is dead and cant HighFive People" << std::endl;
		else
			std::cout << "HighFive Guys!!!" << std::endl;
			
	}
	else
		std::cout << "No Energy!!" << std::endl;
	
}