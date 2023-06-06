/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozdemi <buozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 17:39:29 by buozdemi          #+#    #+#             */
/*   Updated: 2023/03/16 13:02:38 by buozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	std::cout << "Creating zombie on the heap." << std::endl;
	Zombie *zombie2 = newZombie("Harl");
	zombie2->announce();
	delete zombie2;
	
	std::cout << "Creating zombie on the stack." << std::endl;
	Zombie zombie1("Frankeinstein");
	zombie1.announce();

	std::cout << "Calling randomChamp()." << std::endl;
	randomChump("Michael");
	return 0;
}
