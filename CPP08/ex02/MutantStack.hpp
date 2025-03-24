#ifndef	MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <list>
#include <vector>

// A Stack é baseado em outro container neste caso o std::deque por isso é que podemos usar o iterator
// do deque sem dar problemas
template <typename T>
class MutantStack : public std::stack<T>{

	public:
	MutantStack();
	~MutantStack();
	MutantStack(const MutantStack &other);
	MutantStack &operator=(const MutantStack &copy);

	typedef typename std::deque<T>::iterator iterator;

	iterator begin();
	iterator end();

};

#include "MutantStack.tpp"

#endif