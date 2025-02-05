/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajorge-p <ajorge-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 21:45:21 by ajorge-p          #+#    #+#             */
/*   Updated: 2025/01/28 12:19:02 by ajorge-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

class Animal{

	protected:
	std::string type;

	public:
	/*		Canonical Form		*/
	Animal();
	Animal(const std::string &typeName);
	virtual ~Animal();
	Animal(const Animal &copy);
	Animal &operator=(const Animal &copy);
	/*					  		*/
	
	virtual void makeSound() const = 0;
	std::string getType() const;
};

#endif