/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajorge-p <ajorge-p@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 12:19:10 by ajorge-p          #+#    #+#             */
/*   Updated: 2025/02/14 20:04:04 by ajorge-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(){

	try
	{
		Bureaucrat Normie;
		Bureaucrat Artur("Artur", 150);
		Bureaucrat Horio("Horio", 1);
		Bureaucrat Koy;
	
		/*
		//		Low Exception
		Bureaucrat Artur_Error("Artur", -1);
		std::cout << Artur << std::endl;
		Artur.lowerGrade();
		std::cout << Artur << std::endl;
		*/

		/*
		//		High Exception
		std::cout << Horio << std::endl;
		Horio.addGrade();
		std::cout << Horio << std::endl;
		*/

		std::cout << Artur;
		Artur.addGrade();
		std::cout << Artur;
		
		std::cout << Normie;
		Normie.addGrade();
		std::cout << Normie;

		std::cout << Horio;
		for(int i = 0; i < 149; i++){
			Horio.lowerGrade();
			std::cout << Horio;
		}
		
		Koy = Horio;
		
		std::cout << Koy;
		for(int i = 0; i < 149; i++){
			Koy.addGrade();
			std::cout << Koy;
		}
	}
	catch(const Bureaucrat::GradeTooHighException& e){
		std::cerr << e.what() << std::endl;
	}
	catch(const Bureaucrat::GradeTooLowException& e){
		std::cerr << e.what() << std::endl;
	}	
}