/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozdemi <buozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 11:23:14 by buozdemi          #+#    #+#             */
/*   Updated: 2023/03/16 15:25:42 by buozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char const *argv[])
{
	Harl	harl;

	if (argv[1] && argc == 2)
		harl.complain(argv[1]);
	else
		std::cout << "Usage: ./harlfilter [DEBUG|INFO|WARNING|ERROR]" << std::endl;
	return 0;
}
