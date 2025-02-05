/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajorge-p <ajorge-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 17:21:15 by ajorge-p          #+#    #+#             */
/*   Updated: 2025/02/05 11:27:56 by ajorge-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void ) {
	Fixed a;
	Fixed const b( 10 );
	Fixed const c( 42.42f );
	Fixed const d( b );

	a = Fixed( 1234.4321f );
	
	std::cout << std::endl << "Show Numbers and FixedPoint Number" << std::endl;
	std::cout << "a is " << a << std::endl;
	std::cout << "a FixedPoint Number is " << a.getRawBits() << std::endl; 
	std::cout << "b is " << b << std::endl;
	std::cout << "b FixedPoint Number is " << b.getRawBits() << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "c FixedPoint Number is " << c.getRawBits() << std::endl;
	std::cout << "d is " << d << std::endl;
	std::cout << "d FixedPoint Number is " << d.getRawBits() << std::endl;
	
	std::cout << std::endl << "To Int Conversions" << std::endl;
	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;
	
	std::cout << std::endl << "To Float Conversions" << std::endl;
	std::cout << "a is " << a.toFloat() << " as Float" << std::endl;
	std::cout << "b is " << b.toFloat() << " as Float" << std::endl;
	std::cout << "c is " << c.toFloat() << " as Float" << std::endl;
	std::cout << "d is " << d.toFloat() << " as Float" << std::endl;
	std::cout << std::endl;

}	
