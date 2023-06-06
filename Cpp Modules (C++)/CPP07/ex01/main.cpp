/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozdemi <buozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 14:25:01 by buozdemi          #+#    #+#             */
/*   Updated: 2023/04/26 18:10:01 by buozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main(void)
{
	std::string my_names[] = {"burak", "jack", "leonard", "fred"};
	int numbers[] = {1, 2, 3, 4, 5};
	double d_numbers[] = {1.1, 2.2, 3.3, 4.4, 5.5};
	char symbols[] = {'a', 'b', 'c', 'd', 'e'};
	
	std::cout << "\nNames:" << std::endl;
	::iter<std::string>(my_names, 4, &print_i<std::string>);
	std::cout << std::endl;

	std::cout << "\nNumbers:" << std::endl;
	::iter<int>(numbers, 5, &print_i<int>);
	std::cout << std::endl;

	std::cout << "\nDoubles:" << std::endl;
	::iter<double>(d_numbers, 5, &print_i<double>);
	std::cout << std::endl;

	std::cout << "\nChars:" << std::endl;
	::iter<char>(symbols, 5, &print_i<char>);
	std::cout << std::endl;
	
	return 0;
}
