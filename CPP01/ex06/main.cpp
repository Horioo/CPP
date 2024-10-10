/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajorge-p <ajorge-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 09:29:55 by ajorge-p          #+#    #+#             */
/*   Updated: 2024/10/10 10:57:54 by ajorge-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"


//Tests: Debug/Error/Warning/Info - Any other type that doesnt exist

int main(int argc, char **argv)
{
	Harl harl;
	if(argc == 2)
	{
		std::cout << std::endl;
		int nm = harl.assignNumber(argv[1]);
		switch(nm)
		{
			case 0:
				std::cout << "[ DEBUG ]" << std::endl;
				harl.complain(nm);
			break;
			case 1:
				std::cout << "[ INFO ]" << std::endl;
				harl.complain(nm);
			break;
			case 2:
				std::cout << "[ WARNING ]" << std::endl;
				harl.complain(nm);
			break;
			case 3:
				std::cout << "[ ERROR ]" << std::endl;
				harl.complain(nm);
			break;
			default:
			std::cout << "Gnar Noises not Found" << std::endl;
		}
	}
	std::cout << "Invalid number of args" << std::endl;
}