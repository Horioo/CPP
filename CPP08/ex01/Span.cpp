/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajorge-p <ajorge-p@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 12:48:10 by ajorge-p          #+#    #+#             */
/*   Updated: 2025/03/21 12:34:07 by ajorge-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int n){
  std::cout << "Span Constructor" << std::endl;
  this->N = n;
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

void Span::addNumber(int n){
  if(this->deq.size() < this->N)
    this->deq.push_back(n);
  else
      throw std::runtime_error("Tried to enter more than the Deq is allowed to store");
}

int Span::shortestSpan(){
	
	//Check if Deque is empty or if its only 1
	if(this->deq.size() == 1 || this->deq.size() == 0)
		throw std::runtime_error("The Size of the Array has to be 2 or More");
	
	//Sort the Deque so we have the lower numbers first and we can find the first Span
	std::sort(this->deq.begin(), this->deq.end());

	//Find first Span
	int minSpan = this->deq[1] - this->deq[0];

	//Iterate threw the Deque and check if any of the new Spans is smaller than the minSpan
	for(size_t i = 1; i < this->deq.size() - 1; i++){
		int difference = this->deq[i + 1] - this->deq[i];
		if(difference < minSpan)
			minSpan = difference;
	}

	//Check if minSpan is equal to 0 if so throw exception
	if(minSpan == 0)
		throw std::runtime_error("No Span Detected");
	
	return minSpan;
}

int Span::longestSpan(){
	
	//Check if Deque is empty or if its only 1
	if(this->deq.size() == 1 || this->deq.empty())
		throw std::runtime_error("The Size of the Array has to be 2 or More");
	
	//Find Min and Max value inside Deque
	int minVal = *std::min_element(this->deq.begin(), this->deq.end());
	int maxVal = *std::max_element(this->deq.begin(), this->deq.end());
	
	//Check if max and Min are equal if so throw exception
	if(maxVal == minVal)
		throw std::runtime_error("No Span detected");
	
	return maxVal - minVal;
}

void	Span::addManyNumbers(){
	for(size_t i = 0; i < this->N; i++){
		//Fazer Random Generator de 0 a N e inserir no lugar do 40
		this->deq.insert(this->deq.end(), 10, 40);
	}
}

void Span::display(){
	for (std::deque<int>::iterator it = this->deq.begin(); it != deq.end(); ++it)
		std::cout << *it << " ";
}
