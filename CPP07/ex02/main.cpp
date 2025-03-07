/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajorge-p <ajorge-p@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 14:40:36 by ajorge-p          #+#    #+#             */
/*   Updated: 2025/03/07 16:21:08 by ajorge-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main(){

	try {
		std::srand(std::time(0));
		Array<std::string> arr0(10);

		for(int i = 0; i < 10; i++)
		{
			std::stringstream ss;
			ss << std::rand() % 1000;
			arr0[i] = ss.str();
			std::cout <<"Arr0[" << i << "] = " << arr0[i] << std::endl;
		}

		Array<int> arr1(10);

		for(int i = 0; i < 10; i++)
		{
			arr1[i] = std::rand() % 1000;
			std::cout <<"Arr1[" << i << "] = " << arr1[i] << std::endl;
		}

		Array<int> arr2(arr1);
		for(int i = 0; i < 10; i++)
		std::cout <<"Arr2[" << i << "] = " << arr2[i] << std::endl;

		Array<int> arr3;
		arr3 = arr2;
		for(int i = 0; i < 10; i++)
			std::cout <<"Arr3[" << i << "] = " << arr3[i] << std::endl;

		std::cout << "\nArray Sizes\n" 
		<< "arr0 = " << arr0.size()
		<< "\narr1 = " << arr1.size() 
		<< "\narr2 = " << arr2.size() 
		<< "\narr3 = " << arr3.size() 
		<< std::endl; 
		
	} catch(std::exception &e) {
		std::cerr << "Out of Bounds " << std::endl;
	}
}