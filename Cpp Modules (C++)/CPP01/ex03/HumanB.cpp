/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozdemi <buozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 18:28:54 by buozdemi          #+#    #+#             */
/*   Updated: 2023/03/16 13:29:19 by buozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

void	HumanB::attack()
{
	if (this->weapon != NULL && this->weapon->getType() != "")
		std::cout << this->name <<  " attacks with their " << this->weapon->getType() << std::endl;
	else
		std::cout << this->name << " doesn't have a weapon to attack." << std::endl;
}

void	HumanB::setWeapon(Weapon& weapon)
{
	this->weapon = &weapon;
}

HumanB::HumanB(std::string name): name(name){
	this->weapon = NULL;
}

HumanB::~HumanB(){
}