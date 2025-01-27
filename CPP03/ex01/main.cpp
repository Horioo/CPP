/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajorge-p <ajorge-p@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 17:56:42 by ajorge-p          #+#    #+#             */
/*   Updated: 2025/01/27 21:35:49 by ajorge-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(){
	
	//ScavTrap Testing
	ScavTrap Serena("Serena");
	ScavTrap Horio("Horio");
	ClapTrap  Kyle("Kyle");

	std::cout << "Serena Trials" << std::endl;
	Serena.showStats();
	Serena.attack("Anibal");
	Serena.guardGate();
	Serena.takeDamage(50);
	Serena.beRepaired(10);
	Serena.takeDamage(101);
	Serena.beRepaired(10);
	Serena.guardGate();


	std::cout << "Horio Trials" << std::endl;
	Horio.showStats();
	Horio.attack("Anibal");
	Horio.guardGate();
	Horio.takeDamage(50);
	Horio.beRepaired(10);
	Horio.takeDamage(101);
	Horio.beRepaired(10);
	Horio.guardGate();

	Horio = Serena;

	std::cout << "Horio as Serena Trials" << std::endl;
	Horio.showStats();
	Horio.attack("Anibal");
	Horio.guardGate();
	Horio.takeDamage(50);
	Horio.beRepaired(10);
	Horio.takeDamage(101);
	Horio.beRepaired(10);
	Horio.guardGate();

	std::cout << "Kyle Trials" << std::endl;
	Kyle.attack("Anibal");
	Kyle.takeDamage(5);
	Kyle.beRepaired(1);
	Kyle.takeDamage(11);
	Kyle.beRepaired(1);
}