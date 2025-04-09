#ifndef P_MERGE_ME_HPP
#define P_MERGE_ME_HPP

#include <iostream>
#include <list>
#include <cstdlib>
#include <algorithm>
#include <deque>
#include <ctime>
#include <exception>
#include <sys/time.h>

class PmergeMe {

	private:
	std::list<int> _list;
	std::deque<int> _deque;

	public:
	PmergeMe(char **av);
	~PmergeMe();
	PmergeMe(const PmergeMe &other);
	PmergeMe &operator=(const PmergeMe &copy);

	void merge_insert();
	void mergeInsertDeque(std::deque<int> &dq);
	void mergeInsertList(std::list<int> &lst);
	void print_deque(std::deque<int> &dq);
	void print_list();
};

#endif