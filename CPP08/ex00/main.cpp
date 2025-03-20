/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajorge-p <ajorge-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 11:40:51 by ajorge-p          #+#    #+#             */
/*   Updated: 2025/03/19 12:33:41 by ajorge-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main() {
    std::vector<int> vec;
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);
    vec.push_back(40);

	std::list<int> list;
	list.push_back(50);
	list.push_back(60);
	list.push_back(70);
	list.push_back(80);
	

    try {
		std::vector<int>::iterator it;
		std::cout << "Using Vector" << std::endl;
		for(int i = 10; i < 50; i += 10)
		{
			it = easyfind(vec, i);
			std::cout << "Found: " << *it << std::endl;
		}
		/*
		//Error
		it = easyfind(vec, 50);
		std::cout << "Found: " << *it << std::endl;
		*/
		std::cout << "Using Lists" << std::endl;
		std::list<int>::iterator it2;
		for(int i = 50; i < 90; i += 10)
		{
			it2 = easyfind(list, i);
			std::cout << "Found: " << *it2 << std::endl;
		}
		/*
		//Error
		it2 = easyfind(list, 90);
		std::cout << "Found: " << *it2 << std::endl;
		*/
    }	
    catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}