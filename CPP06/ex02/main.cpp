/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajorge-p <ajorge-p@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 11:51:29 by ajorge-p          #+#    #+#             */
/*   Updated: 2025/03/07 12:56:45 by ajorge-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

int main()
{

		Base* Kol = generate();
		
		std::cout << "Identify with Pointer" << std::endl;
		identify(Kol);

		std::cout << "Identify with Reference" << std::endl;
		identify(Kol);
		
}