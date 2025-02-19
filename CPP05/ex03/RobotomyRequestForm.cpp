/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajorge-p <ajorge-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 22:29:48 by ajorge-p          #+#    #+#             */
/*   Updated: 2025/02/19 12:29:28 by ajorge-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("Robotomy", 72, 45), target(target){
	std::cout << "RobotomyRequestForm Default Constructor" << std::endl;
} 

RobotomyRequestForm::~RobotomyRequestForm(){
	std::cout << "RobotomyRequestForm Shredder" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other), target(other.target){
	std::cout << "RobotomyRequestForm copy Constructor" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &copy){
	if(this != &copy)
	{
		std::cout << "RobotomyRequestForm Copy Operator" << std::endl;
		AForm::operator=(copy);
		this->target = copy.target;
	}
	return *this;
}

std::string RobotomyRequestForm::getTarget() const{
	return this->target;
}

int RobotomyRequestForm::execute(Bureaucrat const & executor) const{
	if(AForm::execute(executor) == 1)
	{
		std::srand(std::time(0));
		std::cout << "Make Some Drilling Noisessssss" << std::endl;
		int chance = std::rand() % 2;
		//std::cout << "Number Generated: " << chance << std::endl;

		if(chance)
			std::cout << this->target << " just got Robotomized a new Kind has been Born!!!" << std::endl;
		else
			std::cout << this->target << " just dodged the Robotomization, Viktor cant handle his might" << std::endl;
		return 1;
	}
	return -1;
}