/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajorge-p <ajorge-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 17:07:05 by ajorge-p          #+#    #+#             */
/*   Updated: 2024/09/03 17:13:04 by ajorge-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(){

	int i = 0;
	int nZombies = 1187238;
	Zombie* Z = zombieHorde(nZombies, "Geremias");

	for(i = 0; i < nZombies; i++)
		Z[i].announce();
	delete[] Z;
}