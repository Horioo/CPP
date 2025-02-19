/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajorge-p <ajorge-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 12:19:10 by ajorge-p          #+#    #+#             */
/*   Updated: 2025/02/19 13:15:49 by ajorge-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main(){

	try
	{
		Intern I;
		Bureaucrat Horio("Horio", 1);
		AForm* rrf;

		std::cout << std::endl;
		rrf = I.makeForm("robotomy request", "Bender");

		if(rrf != NULL)
		{
			Horio.signForm(*rrf);
			Horio.executeForm(*rrf);
			delete rrf;
		}
		std::cout << std::endl;
		rrf = I.makeForm("presidential pardon", "Bender");

		if(rrf != NULL)
		{
			Horio.signForm(*rrf);
			Horio.executeForm(*rrf);
			delete rrf;
		}
		std::cout << std::endl;
		rrf = I.makeForm("shrubbery creation", "Bender");

		if(rrf != NULL)
		{
			Horio.signForm(*rrf);
			Horio.executeForm(*rrf);
			delete rrf;
		}
		std::cout << std::endl;
		rrf = I.makeForm("Some bullshit", "Bender");

		if(rrf != NULL)
		{
			Horio.signForm(*rrf);
			Horio.executeForm(*rrf);
			delete rrf;
		}
	}
	catch(const Bureaucrat::GradeTooHighException& e){
		std::cerr << "\033[31m"<<"Exception: " << e.what() << "\033[0m" << std::endl;
	}
	catch(const Bureaucrat::GradeTooLowException& e){
		std::cerr << "\033[31m"<<"Exception: " << e.what() << "\033[0m" << std::endl;
	}
	catch(const AForm::GradeTooHighException& e){
		std::cerr << "\033[31m"<<"Exception: " << e.what() << "\033[0m" << std::endl;
	}
	catch(const AForm::GradeTooLowException& e){
		std::cerr << "\033[31m"<<"Exception: " << e.what() << "\033[0m" << std::endl;
	}
	catch(const AForm::NotSignedException& e){
		std::cerr << "\033[31m"<<"Exception: " << e.what() << "\033[0m" << std::endl;
	}
}