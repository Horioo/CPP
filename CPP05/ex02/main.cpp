/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajorge-p <ajorge-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 12:19:10 by ajorge-p          #+#    #+#             */
/*   Updated: 2025/02/19 12:34:19 by ajorge-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(){

	try
	{
		Bureaucrat 				Horio("Horio", 1);
		PresidentialPardonForm	E5("Horio");
		RobotomyRequestForm		Varona("Horio");
		ShrubberyCreationForm	GeekCase("Horio");
		
		std::cout << std::endl << "Successful Tests " << std::endl << std::endl;

		std::cout << Horio << std::endl;

		Horio.signForm(E5);
		Horio.executeForm(E5);
		std::cout << std::endl;
		Horio.signForm(Varona);
		Horio.executeForm(Varona);
		std::cout << std::endl;
		Horio.signForm(GeekCase);
		Horio.executeForm(GeekCase);

		std::cout << std::endl << E5 << std::endl;
		std::cout << std::endl << Varona << std::endl;
		std::cout << std::endl << GeekCase << std::endl;

		/*		Grade to Low so it fails	*/
				
		/*	Remove Comment to test the fails			
		for(int i = 0; i < 149; i++){
			Horio.lowerGrade();
		}
		
		std::cout << "Failure Tests " << std::endl << std::endl << std::endl;

		std::cout << Horio << std::endl;
				
		Horio.executeForm(E5);
		Horio.executeForm(Varona);
		Horio.executeForm(GeekCase);

		std::cout << std::endl << E5 << std::endl;
		std::cout << std::endl << Varona << std::endl;
		std::cout << std::endl << GeekCase << std::endl;
		*/
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