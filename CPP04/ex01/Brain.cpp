/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajorge-p <ajorge-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 22:51:37 by ajorge-p          #+#    #+#             */
/*   Updated: 2025/02/12 11:27:19 by ajorge-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(){
	std::cout << "Brain Default Constructor" << std::endl << std::endl;
	for(int i = 0; i < 100; i++)
		ideas[i] = "Waiting Idea";
}

Brain::~Brain(){
	std::cout << "Brain Destructor" << std::endl;
}

Brain::Brain(const Brain &copy){
	for(int i = 0; i < 100; i++)
		this->ideas[i] = copy.ideas[i];
}

Brain &Brain::operator=(const Brain &copy){
	if(this != &copy)
	{
		for(int i = 0; i < 100; i++)
			this->ideas[i] = copy.ideas[i];
	}
	return *this;
}

std::string Brain::getIdea(int index) const {
	return (this->ideas[index]);
}

void Brain::setIdea(int index, const std::string &newIdea){
	this->ideas[index] = newIdea;
}