/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajorge-p <ajorge-p@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 17:56:42 by ajorge-p          #+#    #+#             */
/*   Updated: 2025/01/20 19:40:57 by ajorge-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(){

	ClapTrap Jose("José");
	ClapTrap Anibal("Aníbal");
	ClapTrap Toze;
	ClapTrap Antonio(Jose);

	Toze = Anibal;

	//Testes Normais
	Jose.attack("Anibal");
	Anibal.takeDamage(0);
	Anibal.beRepaired(5);
	Toze.attack("José");
	Jose.takeDamage(5);
	Jose.beRepaired(2);
	Jose.attack("Anibal");
	
	//Toze e Antonio Morrem
	Toze.takeDamage(15);
	Antonio.takeDamage(11);
	//Toze está morto mas quer reparar
	Toze.beRepaired(10);

	//Kyle Fica sem energia
	ClapTrap Kyle("Kyle");
	for(int i = 0; i <= 10 ; i++)
		Kyle.attack("Anibal");
	Kyle.beRepaired(1);
}