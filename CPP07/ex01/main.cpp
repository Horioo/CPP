/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajorge-p <ajorge-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 14:15:58 by ajorge-p          #+#    #+#             */
/*   Updated: 2025/03/25 11:41:32 by ajorge-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

template <typename T>
void iter(T* array, size_t len, void (*func)(T&)){
	for(size_t i = 0; i < len; i++)
		func(array[i]);
	std::cout << std::endl;
}

template <typename T>
void display(T element){
	std::cout << element << std::endl;
}

int main(){
	
	int arr1[] = {3, 2, 5, 12312, 1};
	std::string arr2[] = {"Bom", "Dia", "Senhora", "Da", "Padaria"};
	double arr3[] = {1.2, 3.5, 85.2, 39.4, 0.1};

	std::cout << "Display Arr1" << std::endl;
	iter(arr1, sizeof(arr1) / sizeof(arr1[0]), display);

	std::cout << "Display Arr2" << std::endl;
	iter(arr2, sizeof(arr2) / sizeof(arr2[0]), display);

	std::cout << "Display Arr3" << std::endl;
	iter(arr3, sizeof(arr3) / sizeof(arr3[0]), display);
	
}