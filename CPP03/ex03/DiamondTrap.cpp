/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajorge-p <ajorge-p@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 20:32:18 by ajorge-p          #+#    #+#             */
/*   Updated: 2025/01/20 21:32:19 by ajorge-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"


DiamondTrap::DiamondTrap() : ScavTrap(), FragTrap() {
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(), FragTrap(), name(name) {
	std::cout << "DiamondTrap Constructor Called" << std::endl;
}

DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap Destructor Called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &copy) : ClapTrap(), ScavTrap(), FragTrap() {
	std::cout << "DiamondTrap Copy Constructor Called" << std::endl;
	*this = copy;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &copy){
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

void DiamondTrap::attack(const std::string& target){
	ScavTrap::attack(target);
}

void DiamondTrap::takeDamage(unsigned int amount){
	this->hp -= amount;
	this->ep--;
	if(this->hp <= 0 || hp > 4000000000)
		std::cout << "DiamondTrap " << this->name << " is dead!!" << std::endl;
	else
		std::cout << "DiamondTrap " << this->name << " took " << amount << " damage / HP = " << this->hp << std::endl;
}

void DiamondTrap::beRepaired(unsigned int amount){
	if(this->ep > 0)
	{
		if(this->hp <= 0 || hp > 4000000000)
			std::cout << "DiamondTrap " << this->name << " is dead and cant be repaired" << std::endl;
		else
		{
			std::cout << "DiamondTrap " << this->name << " repaired for " << amount << " HP / HP = " << this->hp + amount << std::endl;
			this->hp += amount;
			this->ep--;
		}
			
	}
	else
		std::cout << "No Energy!!" << std::endl;
}

void DiamondTrap::whoAmI(){
	std::cout << "My name is " << this->name << " but my real name is " << ClapTrap::getName() << std::endl;
}