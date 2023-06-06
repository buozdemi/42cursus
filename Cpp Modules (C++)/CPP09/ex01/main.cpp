/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozdemi <buozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 14:22:21 by buozdemi          #+#    #+#             */
/*   Updated: 2023/05/24 20:26:14 by buozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cerr << "Not enough argument." << std::endl;
		return EXIT_FAILURE;
	}
	std::stack<int> my_stack;
		
	get_value_to_list(my_stack, argv[1]);
	std::cout << my_calculate(my_stack) << std::endl;
}
