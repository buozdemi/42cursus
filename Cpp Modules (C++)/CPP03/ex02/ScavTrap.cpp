/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozdemi <buozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 14:38:12 by buozdemi          #+#    #+#             */
/*   Updated: 2023/03/22 14:54:16 by buozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap:: ScavTrap(std::string name): ClapTrap(name)
{
    this->hitpoints = 100;
    this->energypoints = 50;
    this->attackdamage = 20;
    std::cout << "ScavTrap " << this->name << " constructor called" << std::endl;
}

ScavTrap:: ScavTrap()
{
	this->name = "unnamed+ScavTrap";
	this->hitpoints = 100;
    this->energypoints = 50;
    this->attackdamage = 20;
    std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap:: ~ScavTrap()
{
	std::cout << "ScavTrap " << this->name << " destructor called" << std::endl;
}

void    ScavTrap::attack(const std::string& target)
{
	if (this->hitpoints <= 0)
    {
    	std::cout << "ScavTrap " << this->name << " not living." << std::endl;
        return ;
    }
    if (this->energypoints > 0)
    {
        std::cout << this->name << " ScavTrap attacks " << target << std::endl;
        this->energypoints--;
    }
    else
    	std::cout << "ScavTrap " << this->name << " empty energy!" << std::endl;
}

void    ScavTrap::guardGate(void)
{
    std::cout << "ScavTrap " << this->name << ": is in Gate keeper mode" << std::endl;
}
