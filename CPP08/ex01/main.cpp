/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajorge-p <ajorge-p@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 10:56:40 by ajorge-p          #+#    #+#             */
/*   Updated: 2025/03/21 20:46:13 by ajorge-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
	try{
		
		Span sp = Span(100000);

		sp.addManyNumbers();
		
		//sp.display();
		int shortSpan = sp.shortestSpan();
		int longSpan = sp.longestSpan();

		std::cout << "Short Span " << shortSpan << std::endl;
		std::cout << "Long Span " << longSpan << std::endl;

		/*	Throw Exception	*/
		//sp.addNumber(10);
		
	}catch(std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
}