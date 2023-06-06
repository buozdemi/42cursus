/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozdemi <buozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 18:29:10 by buozdemi          #+#    #+#             */
/*   Updated: 2023/03/16 13:29:44 by buozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

void	HumanA::attack()
{
	if (this->weapon.getType() != "")
		std::cout << this->name <<  " attacks with their " << weapon.getType() << std::endl;
	else
		std::cout << this->name << " doesn't have a weapon to attack." << std::endl;
}

HumanA::HumanA(std::string str, Weapon& weapon): name(str), weapon(weapon){
}

HumanA::~HumanA(){
}