/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajorge-p <ajorge-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 13:45:41 by ajorge-p          #+#    #+#             */
/*   Updated: 2025/04/09 18:19:45 by ajorge-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(char **av){
	std::cout << "PmergeMe Default Constructor" << std::endl;

	//Code
	for(size_t i = 1; av[i]; i++)
	{
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

std::deque<int> insertSort(std::deque<int> &dq)
{
	for(size_t i = 1; i < dq.size(); ++i)
	{
		int check = dq[i];
		size_t j = i - 1;
		while(j >= 0 && dq[j] > check)
		{
			dq[j + 1] = dq[j];
			if(j == 0)
			{
				--j;
				break;
			}
			--j;
		}
		dq[j + 1] = check;
	}
	return dq;
}

std::deque<int> merge(const std::deque<int> &left,const std::deque<int> &right)
{
	std::deque<int> result;
	size_t i = 0, j = 0;

	while(i < left.size() && j < right.size())
	{
		if(left[i] < right[j])
		{
			result.push_back(left[i]);
			i++;
		}
		else
		{
			result.push_back(right[j]);
			j++;
		}
	}

	while(i < left.size())
	{
		result.push_back(left[i]);
		i++;
	}
	
	while(j < right.size())
	{
		result.push_back(right[j]);
		j++;
	}

	return result;
}

void PmergeMe::mergeInsertDeque(std::deque<int> &dq)
{
	if(dq.size() <= 1)
		return ;

	size_t mid = dq.size() / 2;

	std::deque<int> left(dq.begin(), dq.begin() + mid);
	std::deque<int> right(dq.begin() + mid, dq.end());

	left = insertSort(left);
	right = insertSort(right);

	dq = merge(left, right);
}

/***********************************************/
/*********			LIST		****************/
/***********************************************/

std::list<int> merge(const std::list<int> &left, const std::list<int> &right)
{
	std::list<int> result;
	std::list<int>::const_iterator itL = left.begin();
	std::list<int>::const_iterator itR = right.begin();

	while(itL != left.end() && itR != right.end())
	{
		if(*itL < *itR)
		{
			result.push_back(*itL);
			++itL;
		}
		else
		{
			result.push_back(*itR);
			++itR;
		}
	}

	while(itL != left.end())
	{
		result.push_back(*itL);
		itL++;
	}
	
	while(itR != right.end())
	{
		result.push_back(*itR);
		++itR;
	}

	return result;
}

std::list<int> insertSort(std::list<int>lst){
	
	if(lst.size() < 2)
		return lst;
	
	std::list<int>::iterator it = lst.begin();
	++it;

	for(; it != lst.end(); ++it)
	{
		int check = *it;
		std::list<int>::iterator j = it;
		--j;
		
		while(j != lst.begin() && *j > check)
			--j;
		
		if(*j > check  && j == lst.begin())
		{
			lst.insert(j, check);
			lst.erase(it++);
		} 
		else 
		{
			std::list<int>::iterator nextIt = it;
			++nextIt;
			lst.insert(++j, check);
			lst.erase(it);
			it = nextIt;
		}
	}
	return lst;
}

void PmergeMe::mergeInsertList(std::list<int> &lst){
	if(lst.size() <= 1)
		return ;
		
	std::list<int> left, right;
	std::list<int>::iterator it = lst.begin();
	size_t mid = lst.size() / 2;

	for(size_t i = 0; i < mid; ++i, it++)
		left.push_back(*it);
	for(; it != lst.end(); ++it)
		right.push_back(*it);

	left = insertSort(left);
	right = insertSort(right);

	lst = merge(left, right);
}

void PmergeMe::merge_insert()
{
	struct timeval start, end;
	
		
	std::cout << "Before: ";
	this->print_deque(this->_deque);
	
	gettimeofday(&start, NULL);
	this->mergeInsertDeque(this->_deque);
	gettimeofday(&end, NULL);
	
	std::cout << "After: ";
	this->print_deque(this->_deque);
	
	long seconds = end.tv_sec - start.tv_sec;
	long microseconds = end.tv_usec - start.tv_usec;
	long totalMicroseconds = seconds * 1000000 + microseconds;
	std::cout << "Time to process a range of " << this->_deque.size() << " elements with std::deque : " << totalMicroseconds << " μs" << std::endl;

	gettimeofday(&start, NULL);
	this->mergeInsertList(this->_list);
	gettimeofday(&end, NULL);
	
	seconds = end.tv_sec - start.tv_sec;
	microseconds = end.tv_usec - start.tv_usec;
	totalMicroseconds = seconds * 1000000 + microseconds;
	std::cout << "Time to process a range of " << this->_list.size() << " elements with std::list : " << totalMicroseconds << " μs" << std::endl;
}
