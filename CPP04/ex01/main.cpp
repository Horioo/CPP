/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajorge-p <ajorge-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 22:00:11 by ajorge-p          #+#    #+#             */
/*   Updated: 2025/02/12 11:37:17 by ajorge-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <cstdlib>
#include <ctime>
#include <sstream>

int main()
{
	const Animal* animal[20];
	std::srand(std::time(0));

	for(int i = 0; i < 20; i++)
	{
		if(i % 2 == 0)
			animal[i] = new Dog();
		else
			animal[i] = new Cat();
	}

	Dog dog;

	std::cout << "Set Ideas" << std::endl;
	for(int i = 0; i < 100; i++)
	{
		std::ostringstream oss;
		oss << "MailMan nº " << i << " Bark " << std::rand() % 100 << " times";
		std::string idea = oss.str();
		//std::string idea = "oLA";
		dog.getBrain()->setIdea(i, idea);
	}
	
	std::cout << "Get Ideas" << std::endl;
	for(int i = 0; i < 100; i++)
		std::cout << dog.getBrain()->getIdea(i) << std::endl;

	std::cout << "Kill Animals" << std::endl;
	for(int i = 0; i < 20; i++)
	{
		std::cout << "Animal "<< animal[i]->getType() << " " << i << " Deleted ";
		delete(animal[i]);
	}

	Cat obj1;
    Cat obj2 = obj1; // Agora cada objeto tem sua própria cópia

    obj1.makeSound(); // "Hello"
    obj2.makeSound(); // "Hello"

	return 0;
}
