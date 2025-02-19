/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajorge-p <ajorge-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 22:29:45 by ajorge-p          #+#    #+#             */
/*   Updated: 2025/02/19 12:13:32 by ajorge-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("Presidential Pardon Form", 25, 5), target(target){
	std::cout << "PresidentialPardonForm Constructor" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm(){
	std::cout << "PresidentialPardonForm Shredder" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : AForm(other), target(other.target){
	std::cout << "PresidentialPardonForm Copy Constructor" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &copy){
	if(this != &copy)
	{
		std::cout << "PresidentialPardonForm Copy Operator" << std::endl;
		AForm::operator=(copy);
		this->target = copy.target;
	}
	return *this;
}

std::string PresidentialPardonForm::getTarget() const{
	return this->target;
}

int PresidentialPardonForm::execute(Bureaucrat const &executor) const{
	if(AForm::execute(executor) == 1){
		std::cout << this->target << " has been pardoned by Zaphod Beeblebrox (The Hitchhikers Guide to the Galaxy)" << std::endl;
		return 1;
	}
	return -1;
}