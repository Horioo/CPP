/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajorge-p <ajorge-p@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 17:07:05 by ajorge-p          #+#    #+#             */
/*   Updated: 2025/02/04 22:15:28 by ajorge-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(){

	int i;
	int nZombies = 10;
	Zombie* Z = zombieHorde(nZombies, "Geremias");

	for(i = 0; i < nZombies; i++)
		Z[i].announce();
	delete[] Z;
}