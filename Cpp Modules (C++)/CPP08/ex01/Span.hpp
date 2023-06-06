/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozdemi <buozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 12:13:08 by buozdemi          #+#    #+#             */
/*   Updated: 2023/04/28 13:03:15 by buozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <numeric>

class Span
{
	private:
		std::vector<int> _v;
		unsigned int _n;
	
	public:
		Span();
		Span (unsigned int n);
		Span(const Span &copy);
		Span &operator=(const Span &copy);
		~Span();

		void	addNumber(int val);
		int		shortestSpan();
		int		longestSpan();
		void	print_span();
		void	fill_all( std::vector<int>::iterator begin, std::vector<int>::iterator end);

		class AlreadyStoredElement: public std::exception
		{
			public:
				virtual const char* what() const _NOEXCEPT;
		};

		class TooFewCount: public std::exception
		{
			public:
				virtual const char* what() const _NOEXCEPT;
		};
};

#endif
