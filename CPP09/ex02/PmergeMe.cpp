/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajorge-p <ajorge-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 13:45:41 by ajorge-p          #+#    #+#             */
/*   Updated: 2025/04/15 15:53:56 by ajorge-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

bool isInvalidChar(char c) {
    return !std::isdigit(c) && c != ' ';
}

bool hasInvalidChars(const std::string& str) {
    return std::find_if(str.begin(), str.end(), isInvalidChar) != str.end();
}

PmergeMe::PmergeMe(char **av){
	std::cout << "PmergeMe Default Constructor" << std::endl;

	//Code
	for(size_t i = 1; av[i]; i++)
	{
		if(hasInvalidChars(av[i]))
			throw std::runtime_error("Error");
		int value = std::atoi(av[i]);
		if(value < 0)
			throw std::runtime_error("Error");
		if((std::find(this->_deque.begin(),this->_deque.end(), value) == this->_deque.end()))
			this->_deque.push_back(value);
		else
			std::cout << "\033[1;31mDuplicate Detected: Action: Ignored\033[0m" << std::endl;
		if((std::find(this->_list.begin(),this->_list.end(), value) == this->_list.end()))
			this->_list.push_back(value);
		else
			std::cout << "\033[1;31mDuplicate Detected: Action: Ignored\033[0m" << std::endl;
	}
}

PmergeMe::~PmergeMe(){
	std::cout << "PmergeMe Destructor" << std::endl;
}

PmergeMe::PmergeMe(const PmergeMe &other){
	std::cout << "PmergeMe Copy Constructor" << std::endl;
	this->_deque = other._deque;
	this->_list = other._list;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &copy){
	std::cout << "PmergeMe Assignment Operator" << std::endl;
	if(this != &copy)
	{
		this->_deque = copy._deque;
		this->_list = copy._list;
	}
	return *this;
}

void PmergeMe::print_deque(std::deque<int> &dq){
	std::deque<int>::const_iterator it;
    for (it = dq.begin(); it != dq.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

void PmergeMe::print_list(){
	std::list<int>::const_iterator it;
    for (it = this->_list.begin(); it != this->_list.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

/***********************************************/
/*********			DEQUE		****************/
/***********************************************/

std::deque<int> generateJacobsthal(int maxVal){
	std::deque<int> seq;
	seq.push_back(0);
	seq.push_back(1);

	while(1)
	{
		int prox = seq[seq.size() - 1] + 2 * seq[seq.size() - 2];
		if(prox > maxVal)
			break;
		seq.push_back(prox);	
	}
	return seq;
}

void insertBinary(std::deque<int> &dq, int value){
	std::deque<int>::iterator it = std::lower_bound(dq.begin(), dq.end(), value);
	dq.insert(it, value);
}

std::deque<int> PmergeMe::fordJohnsonSort(const std::deque<int> &dq){
	size_t n = dq.size();
	if(n < 1)
		return dq;

	std::deque<int> bigger, smaller;

	for(size_t i = 0; i + 1 < n; i += 2){
		if(dq[i] < dq[i + 1])
		{
			smaller.push_back(dq[i]);
			bigger.push_back(dq[i + 1]);	
		}
		else
		{
			smaller.push_back(dq[i + 1]);
			bigger.push_back(dq[i]);		
		}
	}

	if(n % 2 != 0)
		smaller.push_back(dq[n - 1]);

	std::deque<int> order_deq = fordJohnsonSort(bigger);
	std::deque<int> result;

	if(!bigger.empty())
		result.push_back(order_deq[0]);
	if(!smaller.empty())
		insertBinary(result, smaller[0]);

	for(size_t i = 1; i < order_deq.size(); ++i)
		insertBinary(result, order_deq[i]);

	std::deque<int> insertionOrder = generateJacobsthal(smaller.size() - 1);
	std::deque<bool> inserted(smaller.size(), false);
	inserted[0] = true;

	for(size_t i = 0; i < insertionOrder.size(); ++i)
	{
		unsigned int idx = insertionOrder[i];
		if(idx < smaller.size() && !inserted[idx])
		{
			insertBinary(result, smaller[idx]);
			inserted[idx] = true;
		}
	}

	for(size_t i = 0; i < smaller.size(); ++i)
	{
		if(!inserted[i])
			insertBinary(result, smaller[i]);
	}
	return result;
}

/***********************************************/
/*********			LIST		****************/
/***********************************************/

std::list<int> lst_generateJacobsthal(int maxVal){
    std::list<int> seq;
    seq.push_back(0);
    seq.push_back(1);

    std::list<int>::iterator it1 = seq.begin();
    std::list<int>::iterator it2 = ++seq.begin();

    while(1)
    {
        int prox = *it2 + 2 * *it1;
        if(prox > maxVal)
            break;
        seq.push_back(prox);
        it1 = seq.end();
		--it1;
		--it1;
        it2 = seq.end();
		--it2;
    }
    return seq;
}

void insertBinary(std::list<int> &lst, int value)
{
	std::list<int>::iterator it = std::lower_bound(lst.begin(), lst.end(), value);
    lst.insert(it, value);
}

std::list<int> PmergeMe::fordJohnsonSort(const std::list<int> &lst)
{
	size_t n = lst.size();
	if(n < 1)
		return lst;

	std::list<int> bigger, smaller;

	std::list<int>::const_iterator it = lst.begin();

	for(size_t i = 0; i + 1 < n; i +=2, std::advance(it, 2))
	{
		std::list<int>::const_iterator next_it = ++it;
		--it;
		if(*it < *next_it)
		{
			smaller.push_back(*it);
			bigger.push_back(*next_it);
		}
		else
		{
			bigger.push_back(*it);
			smaller.push_back(*next_it);
		}
	}

	if(n % 2 != 0)
		smaller.push_back(*it);

	std::list<int> order_lst = fordJohnsonSort(bigger);
	std::list<int> result;

	if(!bigger.empty())
		result.push_back(order_lst.front());
	if(!smaller.empty())
		insertBinary(result, smaller.front());
	
	std::list<int>::const_iterator order_it = ++order_lst.begin();
	for(; order_it != order_lst.end(); ++order_it)
		insertBinary(result, *order_it);

	std::list<int> insertionOrder = lst_generateJacobsthal(smaller.size() - 1);
	std::deque<bool> inserted(smaller.size(), false);
	inserted.front() = true;

	std::list<int>::iterator order_idx_it = insertionOrder.begin();
	for(; order_idx_it != insertionOrder.end(); ++order_idx_it)
	{
		unsigned int idx = *order_idx_it;
		if(idx < smaller.size() && !inserted[idx])
		{
			std::list<int>::iterator sm_it = smaller.begin();
			std::advance(sm_it, idx);
			insertBinary(result, *sm_it);
			inserted[idx] = true;
		}
	}

	std::list<int>::iterator sm_it = smaller.begin();
	for(size_t i = 0; i < smaller.size(); ++i, ++sm_it)
	{
		if(!inserted[i])
			insertBinary(result, *sm_it);
	}
	return result;
	
}

/***********************************************/
/*************	  Main Function		************/
/***********************************************/


void PmergeMe::merge_insert()
{
	struct timeval start, end;
	
		
	std::cout << "Before: ";
	this->print_deque(this->_deque);
	
	gettimeofday(&start, NULL);
	this->_deque_result = fordJohnsonSort(this->_deque);
	gettimeofday(&end, NULL);
	
	std::cout << "After: ";
	this->print_deque(this->_deque_result);
	
	long seconds = end.tv_sec - start.tv_sec;
	long microseconds = end.tv_usec - start.tv_usec;
	long totalMicroseconds = seconds * 1000000 + microseconds;
	std::cout << "Time to process a range of " << this->_deque.size() << " elements with std::deque : " << totalMicroseconds << " μs" << std::endl;

	gettimeofday(&start, NULL);
	this->_list_result = fordJohnsonSort(this->_list);
	gettimeofday(&end, NULL);

	seconds = end.tv_sec - start.tv_sec;
	microseconds = end.tv_usec - start.tv_usec;
	totalMicroseconds = seconds * 1000000 + microseconds;
	std::cout << "Time to process a range of " << this->_list.size() << " elements with std::list : " << totalMicroseconds << " μs" << std::endl;
}
