/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajorge-p <ajorge-p@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 14:45:10 by ajorge-p          #+#    #+#             */
/*   Updated: 2025/03/07 16:20:40 by ajorge-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template <typename T>
Array<T>::Array() : array(NULL) , len(0){
	std::cout << "Array Default Constructor" << std::endl;
}

template <typename T>
Array<T>::Array(unsigned int n) : len(n){
	std::cout << "Array Constructor with size" << std::endl;
	if(n > 0)
		this->array = new T[n]();
	else
		this->array = NULL;
}

template <typename T>
Array<T>::~Array(){
	std::cout << "Array Destructor" << std::endl;
	delete[] this->array;
}

template <typename T>
Array<T>::Array(const Array &other){ 
	std::cout << "Array Constructor with Other Array" << std::endl;
	if(other.len == 0)
	{
		this->array = NULL;
		this->len = 0;
	}
	else
	{
		this->len = other.len;
		this->array = new T[other.len]();
		for(size_t i = 0; i < other.len; i++)
			this->array[i] = other.array[i];		
	}
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &copy){
	std::cout << "Array Constructor with Copy" << std::endl;
	if(this != &copy)
	{
		if(copy.len == 0)
			this->array = NULL;
		else
		{
			this->array = new T[copy.len]();
			this->len = copy.len;
			for(size_t i = 0; i < copy.len; i++)
				this->array[i] = copy.array[i];
		}
			
	}
	return *this;
}


template <typename T>
T& Array<T>::operator[](size_t index){
	if(index < this->len)
		return this->array[index];
	else
		throw std::exception();
}

template <typename T>
size_t Array<T>::size(){
	return this->len;
}