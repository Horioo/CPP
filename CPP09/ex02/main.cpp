/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajorge-p <ajorge-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 11:48:14 by ajorge-p          #+#    #+#             */
/*   Updated: 2025/04/09 18:39:21 by ajorge-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int ac, char **av)
{
	(void)av;
	try{
		if(ac > 1)
		{
			PmergeMe Merge(av);

			Merge.merge_insert();
		}
		else
			throw std::runtime_error("Error");
	} catch (std::exception &e){
		std::cerr << e.what() << std::endl;
	}
}