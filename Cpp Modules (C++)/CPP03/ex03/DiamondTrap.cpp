/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozdemi <buozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 23:50:37 by buozdemi          #+#    #+#             */
/*   Updated: 2023/03/22 18:11:30 by buozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name): FragTrap(name), ScavTrap(name)
{
    this->name = name;
    ClapTrap::setName(name + "_clap_name");
    FragTrap::setHitpoints(100);
    ScavTrap::setEnergypoints(50);
    FragTrap::setAttackdamage(30);
    std::cout << "DiamondTrap " << this->name << " constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(): FragTrap(), ScavTrap()
{
	this->name = "unnamed+DiamondTrap";
	ClapTrap::setName(this->name + "_clap_name");
    FragTrap::setHitpoints(100);
    ScavTrap::setEnergypoints(50);
    FragTrap::setAttackdamage(30);
    std::cout << "Default DiamondTrap constructor called" << std::endl;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap " << this->name << " destructor called" << std::endl;
}

void DiamondTrap::whoAmI()
{
    std::cout << "ClapTrap Name: " << this->ClapTrap::getName() << std::endl;
    std::cout << "Diamond Name:" << this->name << std::endl;
}

std::string DiamondTrap::getDiamondName()
{
    return (this->name);
}

void DiamondTrap::setDiamondName(std::string name)
{
    this->name = name;
}
