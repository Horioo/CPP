/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajorge-p <ajorge-p@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 22:00:11 by ajorge-p          #+#    #+#             */
/*   Updated: 2025/01/27 22:49:19 by ajorge-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* animal = new Animal();
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();

	std::cout << animal->getType() << ": " << std::endl;
	animal->makeSound();

	std::cout << dog->getType() << ": " << std::endl;
	dog->makeSound();

	std::cout << cat->getType() << ": " << std::endl;
	cat->makeSound();

	delete (animal);
	delete(dog);
	delete(cat);

	std::cout << "Wrong Noises and Animals" << std::endl;

	const WrongAnimal* wAnimal = new WrongAnimal();
	const WrongAnimal* wCat = new WrongCat();

	std::cout << wAnimal->getType() << ": " << std::endl;
	wAnimal->makeSound();

	std::cout << wCat->getType() << ": " << std::endl;
	wCat->makeSound();

	delete(wAnimal);
	delete(wCat);
}
