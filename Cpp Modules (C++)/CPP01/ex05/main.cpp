/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozdemi <buozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 16:24:47 by buozdemi          #+#    #+#             */
/*   Updated: 2023/01/15 18:26:14 by buozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main()
{
	Harl	harl;
	std::string str;

	std::cout << "Please enter level: ";
	do
    {
        std::cin >> str;
        harl.complain(str);
    } while (str.compare("EXIT"));
	
	return 0;
}
