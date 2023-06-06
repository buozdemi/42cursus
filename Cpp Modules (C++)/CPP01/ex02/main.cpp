/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozdemi <buozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 16:40:18 by buozdemi          #+#    #+#             */
/*   Updated: 2023/03/14 13:17:19 by buozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(void)
{
	std::string str = "HI THIS IS BRAIN";
	std::string &stringREF = str;
	std::string *stringPTR;

	stringPTR = &str;
	std::cout << &str << std::endl;
	std::cout << stringPTR << std::endl;
	std::cout << stringREF << std::endl;
	std::cout << str << std::endl;
	std::cout << *stringPTR << std::endl;
	std::cout << &stringREF << std::endl;
	return 0;
}
