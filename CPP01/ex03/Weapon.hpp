/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajorge-p <ajorge-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 08:56:23 by ajorge-p          #+#    #+#             */
/*   Updated: 2024/10/08 11:20:12 by ajorge-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>

class Weapon {

	public:
	Weapon(void);
	Weapon(std::string type);
	~Weapon(void);
	const std::string &getType();
	void setType(std::string newType);

	private:
		std::string type;
};

#endif