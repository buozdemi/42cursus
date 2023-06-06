/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozdemi <buozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 15:33:04 by buozdemi          #+#    #+#             */
/*   Updated: 2023/03/23 15:15:46 by buozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main(void)
{
    DiamondTrap Salvador("Salvador");
    std::cout << "HitPoints:" << Salvador.getHitpoints() << std::endl;
    std::cout << "EnergyPoints:" << Salvador.getEnergypoints() << std::endl;
    std::cout << "AttackDamage:" << Salvador.getAttackdamage() << std::endl;
    Salvador.highFivesGuys();
    Salvador.attack("Samuel");
    std::cout << "After Attack to Samuel: " << Salvador.getEnergypoints() << std::endl;
    Salvador.takeDamage(3);
    std::cout << "After Take 3 Damage: " << Salvador.getHitpoints() << std::endl;
    Salvador.beRepaired(4);
    std::cout << "After Repaired 4 Damage: " << Salvador.getHitpoints() << std::endl;
    Salvador.whoAmI();

	Salvador.takeDamage(200);
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

	DiamondTrap unnamed_class;
	std::cout << "(Name must be unnamed+DiamondTrap) -> " << unnamed_class.getDiamondName() << std::endl;
	unnamed_class = Salvador;
	std::cout << "(Name must be Salvador) -> " << unnamed_class.getDiamondName() << std::endl;
	unnamed_class.setDiamondName("Jacky");
	std::cout << "(Name must be Jacky) -> " << unnamed_class.getDiamondName() << std::endl;
	
    return 0;
}
