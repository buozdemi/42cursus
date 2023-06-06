/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozdemi <buozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 12:12:58 by buozdemi          #+#    #+#             */
/*   Updated: 2023/04/28 11:55:02 by buozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main(void)
{
	std::cout << "\n----AaddNumber() TEST-----" << std::endl;
	Span sp1(15);
	sp1.addNumber(10);
	sp1.addNumber(20);
	sp1.addNumber(30);
	sp1.addNumber(40);
	sp1.print_span();

	std::cout << "\n\n----fill all() TEST - 1-----" << std::endl;
	std::vector<int> v1;
	v1.push_back(50);
	v1.push_back(60);
	v1.push_back(70);
	v1.push_back(73);
	v1.push_back(90);
	v1.push_back(100);
	sp1.fill_all(v1.begin(), v1.end());
	sp1.print_span();

	std::cout << "\n\n----range TEST-----" << std::endl;
	std::cout << "short:	" << sp1.shortestSpan() << std::endl;
	std::cout << "long: " << sp1.longestSpan() << std::endl;
	
	std::cout << "\n\n----Empty span range TEST-----" << std::endl;
	Span sp2(23);
	std::cout << "long:	"  << sp2.longestSpan()	<< std::endl;
	std::cout << "short:	" << sp2.shortestSpan() << std::endl;

	return 0;
}
