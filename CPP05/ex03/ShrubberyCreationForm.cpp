/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajorge-p <ajorge-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 22:29:50 by ajorge-p          #+#    #+#             */
/*   Updated: 2025/02/19 12:29:54 by ajorge-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm("Shrubbery Form", 145, 137), target(target){
	std::cout << "ShrubberyCreationForm Constructor" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm(){
	std::cout << "ShrubberyCreationForm Shredder" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other), target(other.target){
	std::cout << "ShrubberyCreationForm Copy Constructor" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &copy){
	if(this != &copy)
	{
		std::cout << "ShrubberyCreationForm Copy Operator" << std::endl;
		AForm::operator=(copy);
		this->target = copy.target;
	}
	return *this;
}

std::string ShrubberyCreationForm::getTarget() const{
	return this->target;
}

int ShrubberyCreationForm::execute(Bureaucrat const &executor) const{
	if(AForm::execute(executor) == 1)
	{
		std::string shrub = this->target + "_shrubbery";
		std::ofstream file(shrub.c_str());
		if(!file)
		{
			std::cerr << "Error on File Creation" << std::endl;
			return -1;
		}
		if(file.is_open())
		{
			file << "          ^\n"
        			"		 ^*^\n"
       				"		*^o^*\n"
      				"	   ^*o@o*^\n"
     				"	  *@o@o@o@*\n"
    				"	 ^o@o#@o@o^*\n"
   					"	*o@o#o@o#o@**\n"
  					"   ^@o#o@o#o@o#o^*\n"
 					"  *@o#o@o#o@o#o@o**\n"
        			"		 |||\n"
        			"		 |||" << std::endl;
		}
		file.close();
		return 1;
	}
	return -1;
}