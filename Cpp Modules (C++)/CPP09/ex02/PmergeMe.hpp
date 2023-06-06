/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozdemi <buozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 00:22:31 by buozdemi          #+#    #+#             */
/*   Updated: 2023/05/31 14:24:19 by buozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define	PMERGEME_HPP

#include <iostream>
#include <deque>
#include <list>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <sstream>

void	add_number_to_container(int argc, char **argv, std::deque<int> &my_deq, std::list<int> &my_lst);
bool	is_valid_ctrl(std::string str);

template<typename Container>
Container& insertionSort(Container& container) {
    typename Container::iterator i = container.begin();
    ++i;

    for (; i != container.end(); ++i) {
	
        typename Container::value_type key = *i;
        typename Container::iterator j = i;        
        while (j != container.begin() && *(std::prev(j)) > key) {
            typename Container::iterator prevJ = std::prev(j);
            *j = *prevJ;
            --j;
        }
        *j = key;
    }
	return (container);
}

template<typename Container>
void merge_sort(Container& m) {

	if (m.size() <= 50)
	{
		insertionSort(m);
		return ;
	}
	typename Container::iterator begin = m.begin();
	typename Container::iterator mid = m.begin();
	std::advance(mid, m.size() / 2);
	typename Container::iterator end = m.end();
	Container left(begin, mid);
	Container right(mid, end);
	merge_sort(left);
	merge_sort(right);
	std::merge(left.begin(), left.end(), right.begin(), right.end(), m.begin());
}

template<typename Container>
void	write_output(Container& container, std::string type_container, int pos)
{
	size_t size = container.size();
	std::clock_t start = 0;
	std::clock_t end = 0;
	if (pos == 1)
	{
		std::cout << "Before: ";
		for (typename Container::const_iterator it = container.begin(); it != container.end(); ++it) {
			std::cout << *it << " ";
		}
		std::cout << std::endl;
	}
	
	start = std::clock();
	if (size > 50)
		merge_sort(container);
	else
		insertionSort(container);
	end = std::clock();
	if (pos == 1)
	{
		std::cout << "After: ";
		for (typename Container::const_iterator it = container.begin(); it != container.end(); ++it) {
			std::cout << *it << " ";
		}
		std::cout << std::endl;
	}
	
	double elapsed = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;
    std::cout << "Time to process a range of " << size << " elements with std::" << type_container << "<int> : " << elapsed << " us" << std::endl;
}

#endif