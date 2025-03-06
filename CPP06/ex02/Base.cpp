/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajorge-p <ajorge-p@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 17:45:03 by ajorge-p          #+#    #+#             */
/*   Updated: 2025/03/06 22:33:04 by ajorge-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base::Base(){
	std::cout << "Base Constructor" << std::endl;
}

Base::~Base(){
	std::cout << "Base Destructor" << std::endl;
}

Base *Base::generate(void){
	std::srand(std::time(0));
	int chance = std::rand() % 3;
	switch(chance){
		case 1:
			return new 
	}
}