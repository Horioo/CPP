#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <deque>


class Span{

	private:
	unsigned int N;
	std::deque<int> deq;

	public:
	Span(unsigned int n);
	~Span();
	Span(const Span &other);
	Span &operator=(const Span &copy);

	void addNumber();
	unsigned int shortestSpan();
	unsigned int longestSpan();
	void addManyNumbers();
};


#endif