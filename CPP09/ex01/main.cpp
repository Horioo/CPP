/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajorge-p <ajorge-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 11:48:14 by ajorge-p          #+#    #+#             */
/*   Updated: 2025/04/09 11:51:58 by ajorge-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int ac, char **av)
{
	if(ac == 2)
		RPN obj(av[1]);
	else
		std::cerr << "Correct Input ./RPN \"n1 n2 op\"" << std::endl;
}