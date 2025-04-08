/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajorge-p <ajorge-p@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 11:48:14 by ajorge-p          #+#    #+#             */
/*   Updated: 2025/04/08 21:43:52 by ajorge-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int ac, char **av)
{
	(void)av;
	if(ac > 1){
		RPN obj(av[1]);
		
		//obj.makeRPN();
	}
	else{
		std::cerr << "Correct Input ./RPN \"n1 n2 op\"" << std::endl;
	}

}