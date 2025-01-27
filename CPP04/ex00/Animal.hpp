/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajorge-p <ajorge-p@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 21:45:21 by ajorge-p          #+#    #+#             */
/*   Updated: 2025/01/27 22:43:05 by ajorge-p         ###   ########.fr       */
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
	
	virtual void makeSound() const;
	std::string getType() const;
};

#endif