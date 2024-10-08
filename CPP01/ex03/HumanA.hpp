/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajorge-p <ajorge-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 09:06:15 by ajorge-p          #+#    #+#             */
/*   Updated: 2024/10/08 11:22:47 by ajorge-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

#include <iostream>
#include "Weapon.hpp"

// Usar a Referenciacao da Weapon faz com que seja 
// obrigatorio existir uma weapon

class HumanA {

	public:
	HumanA(std::string name, Weapon& weapon);
	~HumanA(void);
	void attack(void);
	void setWeapon(Weapon& weapon);
	
	private:
	Weapon &weapon;
	std::string name;
};

#endif