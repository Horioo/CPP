/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajorge-p <ajorge-p@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 19:16:40 by ajorge-p          #+#    #+#             */
/*   Updated: 2025/01/20 20:04:51 by ajorge-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap(), guardGateStatus(false){
	this->hp = 100;
	this->ep = 50;
	this->ad = 20;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name), guardGateStatus(false){
	std::cout << "ScavTrap Constructor Called" << std::endl;
	this->hp = 100;
	this->ep = 50;
	this->ad = 20;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap Destructor Called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &copy): ClapTrap() {
	std::cout << "ScavTrap Copy Constructor Called" << std::endl;
	*this = copy;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &copy){
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

void ScavTrap::attack(const std::string& target){
	if(this->ep > 0)
	{
		std::cout << "ScavTrap " << this->name << " attacks " << target << ", causing " << this->ad << " points of damage!" << std::endl;
		this->ep--;
	}
	else
		std::cout << "No Energy!!" << std::endl;
}

void ScavTrap::guardGate(){
	if(this->ep > 0)
	{
		if(this->hp <= 0 || hp > 4000000000)
			std::cout << "ScavTrap " << this->name << " is dead and cant enter Guard Mode" << std::endl;
		else
		{
			this->guardGateStatus = true;
			std::cout << "ScavTrap " << this->name << " is now in Gate Mode" << std::endl;
		}
	}
	else
		std::cout << "No Energy!!" << std::endl;
}

void ScavTrap::showStats(){
	std::cout << "ScavTrap name = " << this->name << " | hp = " << this->hp << " | ep = " << this->ep << " | ad = " << this->ad << " | guardGate = " << this->guardGateStatus << std::endl; 
}

void ScavTrap::takeDamage(unsigned int amount){
	this->hp -= amount;
	this->ep--;
	if(this->hp <= 0 || hp > 4000000000)
		std::cout << "ScavTrap " << this->name << " is dead!!" << std::endl;
	else
		std::cout << "ScavTrap " << this->name << " took " << amount << " damage / HP = " << this->hp << std::endl;
	
}

void ScavTrap::beRepaired(unsigned int amount){
	if(this->ep > 0)
	{
		if(this->hp <= 0 || hp > 4000000000)
			std::cout << "ScavTrap " << this->name << " is dead and cant be repaired" << std::endl;
		else
		{
			std::cout << "ScavTrap " << this->name << " repaired for " << amount << " HP / HP = " << this->hp + amount << std::endl;
			this->hp += amount;
			this->ep--;
		}
			
	}
	else
		std::cout << "No Energy!!" << std::endl;
}