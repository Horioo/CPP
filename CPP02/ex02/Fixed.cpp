/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajorge-p <ajorge-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 17:30:16 by ajorge-p          #+#    #+#             */
/*   Updated: 2025/01/28 11:51:33 by ajorge-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : fp_number(0){
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int number) : fp_number(number << bits){
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float number) : fp_number(number * (1 << bits)){
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &copy){
	std::cout << "Copy constructor called" << std::endl;
	this->fp_number = copy.getRawBits();
}

Fixed::~Fixed(){
	std::cout << "Destructor Called" << std::endl;
}

/*Operator overload*/

Fixed &Fixed::operator=(const Fixed &other){
	std::cout << "Copy assignment operator called" << std::endl;
	if(this != &other)
		this->fp_number = other.getRawBits();
	return *this;
}

bool Fixed::operator>(const Fixed &other) const{
	return (this->fp_number > other.fp_number);
}

bool Fixed::operator<(const Fixed &other) const{
	return (this->fp_number < other.fp_number);
}

bool Fixed::operator>=(const Fixed &other) const{
	return (this->fp_number >= other.fp_number);
}

bool Fixed::operator<=(const Fixed &other) const{
	return (this->fp_number <= other.fp_number);
}

bool Fixed::operator==(const Fixed &other) const{
	return (this->fp_number == other.fp_number);
}

bool Fixed::operator!=(const Fixed &other) const{
	return (this->fp_number != other.fp_number);
}

Fixed Fixed::operator+(const Fixed &other) const{
	return (this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed &other) const{
	return (this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed &other) const{
	return (this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed &other) const{
	return (this->toFloat() / other.toFloat());
}

Fixed Fixed::operator++(){
	this->fp_number++;
	return(*this);
}

Fixed Fixed::operator++(int){
	Fixed tmp(*this);
	this->fp_number++;
	return(tmp);
}

Fixed Fixed::operator--(){
	this->fp_number--;
	return(*this);
}

Fixed Fixed::operator--(int){
	Fixed tmp(*this);
	this->fp_number--;
	return(tmp);
}

std::ostream &operator<<(std::ostream &out, const Fixed &obj){
	out << obj.toFloat();
	return (out);
}



/*Member Functions*/

int Fixed::getRawBits(void) const{
	return(this->fp_number);
}

void Fixed::setRawBits(int const raw){
	this->fp_number = raw;
}

float Fixed::toFloat(void) const{
	return ((float)(this->fp_number) / (1 << bits));
}

int Fixed::toInt(void) const{
	return (this->fp_number >> bits);
}

Fixed Fixed::min(Fixed &n1, Fixed &n2){
	return (n1 > n2 ? n2 : n1);
}

const Fixed Fixed::min(const Fixed &n1, const Fixed &n2){
	return (n1 > n2 ? n2 : n1);
}

Fixed Fixed::max(Fixed &n1, Fixed &n2){
	return (n1 > n2 ? n1 : n2);
}

const Fixed Fixed::max(const Fixed &n1, const Fixed &n2){
	return (n1 > n2 ? n1 : n2);
}