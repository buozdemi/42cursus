/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozdemi <buozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 00:22:31 by buozdemi          #+#    #+#             */
/*   Updated: 2023/05/29 21:21:53 by buozdemi         ###   ########.fr       */
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
Container merge_sort(Container& m) {

	int middle = m.size() / 2;
	Container left, right;
	typename Container::iterator it = m.begin();
	for (int i = 0; i < middle; i++) {
		left.push_back(*it);
		++it;
	}
	for (int i = middle; i < (int)m.size(); i++) {
		right.push_back(*it);
		++it;
	}
	if (left.size() > 1)
		left = merge_sort(left);
	if (left.size() > 1)
		right = merge_sort(right);

	std::merge(left.begin(), left.end(), right.begin(), right.end(), m.begin());
	return (m);
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
	
	Container sorted;
	start = std::clock();
	if (size > 250)
		sorted = merge_sort(container);
	else
		sorted = insertionSort(container);
	end = std::clock();
	if (pos == 1)
	{
		std::cout << "After: ";
		for (typename Container::const_iterator it = sorted.begin(); it != sorted.end(); ++it) {
			std::cout << *it << " ";
		}
		std::cout << std::endl;
	}
	
	double elapsed = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;
    std::cout << "Time to process a range of " << size << " elements with std::" << type_container << "<int> : " << elapsed << " us" << std::endl;
}

#endif