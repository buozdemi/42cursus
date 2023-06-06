/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozdemi <buozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 18:51:46 by buozdemi          #+#    #+#             */
/*   Updated: 2023/03/22 14:50:48 by buozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(const std::string& name): ClapTrap(name)
{
    this->hitpoints = 100;
    this->energypoints = 100;
    this->attackdamage = 30;
    std::cout << "FragTrap " << this->name << " constructor called" << std::endl;
}

FragTrap::FragTrap()
{
	this->name = "unnamed+FragTrap";
	this->hitpoints = 100;
    this->energypoints = 100;
    this->attackdamage = 30;
    std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap " << this->name << " destructer called" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
    std::cout << this->name << ": Guys! High Five" << std::endl;
}