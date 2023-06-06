/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozdemi <buozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 17:54:00 by buozdemi          #+#    #+#             */
/*   Updated: 2023/03/16 12:36:54 by buozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
	this->Name = name;
}

Zombie::~Zombie()
{
	std::cout << "Zombie " << this->getName() << " has been destroyed." << std::endl;
}

void	Zombie::announce(void)
{
	std::cout << this->Name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

std::string Zombie::getName()
{
	return (this->Name);
}
