/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajorge-p <ajorge-p@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 22:30:16 by ajorge-p          #+#    #+#             */
/*   Updated: 2025/03/24 22:46:34 by ajorge-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

template <typename T>
MutantStack<T>::MutantStack(){
	std::cout << "Mutant Stack Default Constructor" << std::endl;
}

template <typename T>
MutantStack<T>::~MutantStack(){
	std::cout << "Mutant Stack Destructor" << std::endl;
}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack &other) : std::stack<T>(other){
	std::cout << "Mutant Stack Copy Constructor" << std::endl;
}

template <typename T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack &copy){
	if(this != &copy){
		std::stack<T>::operator=(copy);
	}
	return *this;
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin(){
	return this->c.begin();
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end(){
	return this->c.end();
}