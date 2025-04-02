/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajorge-p <ajorge-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 08:54:09 by ajorge-p          #+#    #+#             */
/*   Updated: 2025/04/02 12:31:48 by ajorge-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int ac, char **av){
	if(ac == 2){

		BitcoinExchange btc(av[1]);
		btc.display();
	}
	else 
		std::cout << "Invalid number of files: \nFormat: ./btc FileWithValuesToEvaluate " << std::endl;

}