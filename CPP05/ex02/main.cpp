/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajorge-p <ajorge-p@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 12:19:10 by ajorge-p          #+#    #+#             */
/*   Updated: 2025/02/14 22:11:40 by ajorge-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(){

	try
	{
		Bureaucrat 	Horio("Horio", 150);
		Form		E5("E5 Contract", 80, 150);
		Form		GC("GC Contract", 2, 2);
		
		/*		Throws Exceptions	*/
		//Form		toHigh("Form 1", 0, 150);
		//Form		toLow("Form 2", 160, 2);
		
		std::cout << Horio << std::endl;
		std::cout << E5 << std::endl;
		
		for(int i = 0; i < 90; i++){
			Horio.addGrade();
		}
		
		std::cout << Horio;
		Horio.signForm(E5);

		std::cout << std::endl << E5 << std::endl;

		/*			Throws Exceptions		*/
		
		/*
		std::cout << "Cant Sign the Form" << std::endl;
		for(int i = 0; i < 50 ; i++){
			Horio.lowerGrade();
		}

		std::cout << Horio;
		Horio.signForm(GC);
		std::cout << std::endl << E5 << std::endl;
		*/
		
	}
	catch(const Bureaucrat::GradeTooHighException& e){
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	catch(const Bureaucrat::GradeTooLowException& e){
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	catch(const Form::GradeTooHighException& e){
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	catch(const Form::GradeTooLowException& e){
		std::cerr << "Exception: " << e.what() << std::endl;
	}
}