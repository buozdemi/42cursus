/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozdemi <buozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 13:41:33 by buozdemi          #+#    #+#             */
/*   Updated: 2023/03/16 12:09:33 by buozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void	Zombie::announce()
{
	std::cout << this->name << " : BraiiiiiiinnnzzzZ..." << std::endl;
}

void 	Zombie::setName(std::string z_name)
{
	this->name = z_name;
}

Zombie:: Zombie(void)
{
	std::cout << "A Zombie is created." << std::endl;
}

Zombie:: ~Zombie(void)
{
	std::cout << "Zombie " << this->name << " has been destroyed." << std::endl;	
}
