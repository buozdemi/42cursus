/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozdemi <buozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 15:35:03 by buozdemi          #+#    #+#             */
/*   Updated: 2023/03/23 13:54:16 by buozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(const std::string name): name(name), hitpoints(10), energypoints(10), attackdamage(0)
{
    std::cout << "Created ClapTrap " << this->name << "..." << std::endl;
}

ClapTrap::ClapTrap(): name("unnamed+ClapTrap"), hitpoints(10), energypoints(10), attackdamage(0)
{
    std::cout << "Default ClapTrap constructor called" << std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap " << this->name << " is destroyed." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& c)
{
	std::cout << "ClapTrap copy constructer called" << std::endl;
    *this = c;
}

void ClapTrap::attack(const std::string& target)
{
    if (this->hitpoints <= 0)
    {
    	std::cout << "ClapTrap " << this->name << " not living." << std::endl;
        return ;
    }
    if (this->energypoints > 0)
    {
        std::cout << "ClapTrap " << this->name << " attacks ";
        std::cout << target << ", causing ";
        std::cout << this->attackdamage << " points of damage!" << std::endl;
        this->energypoints--;
    }
    else
    	std::cout << "ClapTrap " << this->name << " empty energy!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (this->hitpoints > 0)
    {
        std::cout << this->name << " has been attacked!" << std::endl;
        this->hitpoints = this->hitpoints - amount;
    }
	else
        std::cout << this->name << " can't take any more damage because it's dead." << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->hitpoints <= 0)
    {
        std::cout << this->name << " cannot be repaired because it is not living." << std::endl;
        return ;
    }
    if (this->energypoints > 0)
    {
        std::cout << this->name << " has been repaired " << amount << "." << std::endl;
        this->energypoints--;
        this->hitpoints = this->hitpoints + amount;
    }
    else
        std::cout << this->name << " empty energy!" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& c)
{
	if (this != &c)
	{
	    this->attackdamage = c.attackdamage;
	    this->energypoints = c.energypoints;
	    this->hitpoints = c.hitpoints;
	    this->name = c.name;
	}
    return (*this);
}

void ClapTrap::setName(std::string name)
{
    this->name = name;
}

void ClapTrap::setHitpoints(int points)
{
    this->hitpoints = points;
}

void ClapTrap::setEnergypoints(int points)
{
    this->energypoints = points;
}

void ClapTrap::setAttackdamage(int attackdamage)
{
    this->attackdamage = attackdamage;
}

std::string ClapTrap::getName()
{
    return (this->name);
}

int ClapTrap::getHitpoints()
{
    return (this->hitpoints);
}

int ClapTrap::getEnergypoints()
{
    return (this->energypoints);
}

int ClapTrap::getAttackdamage()
{
    return (this->attackdamage);
}
