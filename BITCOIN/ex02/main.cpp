/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozdemi <buozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 00:22:02 by buozdemi          #+#    #+#             */
/*   Updated: 2023/05/29 18:55:26 by buozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		std::cerr << "Not enough argument." << std::endl;
		return EXIT_FAILURE;
	}
	
	std::deque<int> my_deq;
	std::list<int> my_lst;
	
	add_number_to_container(argc, argv, my_deq, my_lst);
	write_output(my_deq, "deque", 1);
	write_output(my_lst, "list", 2);

	return 0;
}
