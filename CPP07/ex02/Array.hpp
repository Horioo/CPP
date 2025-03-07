#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <ostream>
#include <ctime>
#include <cstdlib>
#include <sstream>

template <typename T>
class Array{

	private:
	T *array;
	size_t len;

	public:
	Array();
	Array(unsigned int n);
	~Array();
	Array(const Array &other);
	Array &operator=(const Array &copy);
	T& operator[](size_t index);

	size_t size();
};

#include "Array.tpp"

#endif