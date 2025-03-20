/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajorge-p <ajorge-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 12:48:10 by ajorge-p          #+#    #+#             */
/*   Updated: 2025/03/19 12:48:11 by ajorge-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int n){
  std::cout << "Span Constructor" << std::endl;
  this.N = n;
}

Span::~Span(){
  std::cout << "Span Destructor" << std::endl;
}

Span::Span(const Span &other){
  std::cout << "Span Copy Constructor" << std::endl;
  this->deq = other.deq;
  this->N = other.N;
}

Span &Span::operator=(const Span &copy){
  std::cout << "Span Copy Assignment" << std::endl;
  if(this != &copy){
      this->deq = copy.deq;
      this->N = copy.N;
  }
  return *this;
}

Span::addNumber(unsigned int n){
  if(deq.size() < this.N){
    this->deq.push_back(n);
  else
      throw std::runtime_error("Tried to enter more than the Deq can store");
}
