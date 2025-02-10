/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajorge-p <ajorge-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 17:56:42 by ajorge-p          #+#    #+#             */
/*   Updated: 2025/02/10 17:00:12 by ajorge-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main(){
	
	//FragTrap Testing
	
	DiamondTrap Dia("Dia");
	/*
		FragTrap Serena("Serena");
		FragTrap Horio("Horio");
		ScavTrap Nuno("Nuno");
		ClapTrap  Kyle("Kyle");
		

		std::cout << "Serena Trials" << std::endl;
		Serena.showStats();
		Serena.attack("Anibal");
		Serena.highFivesGuys();
		Serena.takeDamage(50);
		Serena.beRepaired(10);
		Serena.takeDamage(101);
		Serena.beRepaired(10);
		Serena.highFivesGuys();


		std::cout << "Horio Trials" << std::endl;
		Horio.showStats();
		Horio.attack("Anibal");
		Horio.highFivesGuys();
		Horio.takeDamage(50);
		Horio.beRepaired(10);
		Horio.takeDamage(101);
		Horio.beRepaired(10);
		Horio.highFivesGuys();

		Horio = Serena;

		std::cout << "Horio as Serena Trials" << std::endl;
		Horio.showStats();
		Horio.attack("Anibal");
		Horio.highFivesGuys();
		Horio.takeDamage(50);
		Horio.beRepaired(10);
		Horio.takeDamage(101);
		Horio.beRepaired(10);
		Horio.highFivesGuys();

		std::cout << "Kyle Trials" << std::endl;
		Kyle.attack("Anibal");
		Kyle.takeDamage(5);
		Kyle.beRepaired(1);
		Kyle.takeDamage(11);
		Kyle.beRepaired(1);

		std::cout << "Nuno Trials" << std::endl;
		Nuno.showStats();
		Nuno.attack("Anibal");
		Nuno.guardGate();
		Nuno.takeDamage(50);
		Nuno.beRepaired(10);
		Nuno.takeDamage(101);
		Nuno.beRepaired(10);
		Nuno.guardGate();
	*/
	std::cout << "Dia Trials" << std::endl;
	Dia.attack("Anibal");
	Dia.whoAmI();
	Dia.guardGate();
	Dia.takeDamage(50);
	Dia.beRepaired(10);
	Dia.takeDamage(101);
	Dia.beRepaired(10);
	Dia.guardGate();
	
}