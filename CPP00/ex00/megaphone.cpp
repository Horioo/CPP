/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajorge-p <ajorge-p@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 17:43:15 by ajorge-p          #+#    #+#             */
/*   Updated: 2024/08/22 17:43:16 by ajorge-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

std::string ToUpperString(std::string str)
{
	std::string  ret = str;

	for(int i = 0; str[i]; i++)
		ret[i] = toupper(str[i]);
	return ret;
}

int main(int ac, char **av)
{
	if(ac != 1)
	{
		for(int i = 1; av[i]; i++)
			std::cout << ToUpperString(av[i]);
		std::cout << std::endl;
	}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
}