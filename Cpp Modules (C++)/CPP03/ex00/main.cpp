/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozdemi <buozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 15:33:04 by buozdemi          #+#    #+#             */
/*   Updated: 2023/03/22 18:46:23 by buozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap Salvador("Salvador");
    std::cout << "First Damage:" << Salvador.getAttackdamage() << std::endl;
    Salvador.setAttackdamage(1);
    std::cout << "First Energy:" << Salvador.getEnergypoints() << std::endl;
    std::cout << "First Hit:" << Salvador.getHitpoints() << std::endl;
    Salvador.attack("Jason");
    std::cout << "After Attack Energy:" << Salvador.getEnergypoints() << std::endl;
    Salvador.takeDamage(2);
    std::cout << "After Take Damage Hit:" << Salvador.getHitpoints() << std::endl;
    Salvador.beRepaired(4);
    std::cout << "After 4 Repaired Hit:" << Salvador.getHitpoints() << std::endl;
    std::cout << "Last Energy:" << Salvador.getEnergypoints() << std::endl;
    std::cout << "Last Damage:" << Salvador.getAttackdamage() << std::endl;
	
	Salvador.takeDamage(20);
	std::cout << "Salvador must be died for attack: ";
	Salvador.attack("Norman");
	std::cout << "Salvador must be died for beRepaired: ";
	Salvador.beRepaired(2);
	std::cout << "Salvador must be died for takeDamage: ";
	Salvador.takeDamage(10);
	
	Salvador.setHitpoints(10);
	Salvador.setEnergypoints(0);
	std::cout << "Salvador is living but its energy point zero: "; 
	Salvador.attack("Norman"); 
	std::cout << "Salvador is living but its energy point zero: ";
	Salvador.beRepaired(2);
	
	ClapTrap unnamed_class;
	std::cout << "(Name must be unnamed+ClapTrap) -> " << unnamed_class.getName() << std::endl;
	unnamed_class = Salvador;
	std::cout << "(Name must be Salvador) -> " << unnamed_class.getName() << std::endl;

    return 0;
}
