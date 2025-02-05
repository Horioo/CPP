/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajorge-p <ajorge-p@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 21:54:54 by ajorge-p          #+#    #+#             */
/*   Updated: 2025/01/27 23:31:00 by ajorge-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Animal;
class Brain;

class Cat : public Animal {
	
	private:
	Brain *brain;

	public:
	Cat();
	~Cat();
	Cat(const Cat &copy);
	Cat &operator=(const Cat &copy);
	
	void makeSound() const ;
	Brain *getBrain();
};

#endif