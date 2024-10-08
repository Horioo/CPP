/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajorge-p <ajorge-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 09:29:55 by ajorge-p          #+#    #+#             */
/*   Updated: 2024/10/10 10:03:24 by ajorge-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"


//Tests: Debug/Error/Warning/Info - Any other type that doesnt exist

int main(int argc, char **argv)
{
	Harl harl;
	if(argc < 2)
		return 1;
	std::cout << std::endl;
	for(int i = 1; i < argc; i++)
		harl.complain(argv[i]);	
}