/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajorge-p <ajorge-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 12:39:30 by ajorge-p          #+#    #+#             */
/*   Updated: 2025/02/19 13:15:12 by ajorge-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(){
	std::cout << "Intern Creation" << std::endl;
}

Intern::~Intern(){
	std::cout << "Intern Destroyer" << std::endl;
}

Intern::Intern(const Intern &other){
	std::cout << "Intern Copy Constructor" << std::endl;
	(void)&other;
}

Intern &Intern::operator=(const Intern &other){
	(void)other;
	return *this;
}

AForm* Intern::makeForm(const std::string formName, const std::string& target){

	std::string names[3] = {
		"presidential pardon",
		"robotomy request",
		"shrubbery creation"
	};

	for(int i = 0; i < 3; i++)
	{
		if(formName.compare(names[i]) == 0)
		{
			switch(i){
				case 0:
				return new PresidentialPardonForm(target);
				break;
				case 1:
				return new RobotomyRequestForm(target);
				break;
				case 2:
				return new ShrubberyCreationForm(target);
				break;
			}
		}
	}
	std::cout << "The Intern cant do magic, the Form doenst exist so maybe give a name that is correct" << std::endl;
	return NULL;
}