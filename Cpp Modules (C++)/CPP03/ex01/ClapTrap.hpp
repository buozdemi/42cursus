/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozdemi <buozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 15:34:54 by buozdemi          #+#    #+#             */
/*   Updated: 2023/03/21 18:44:29 by buozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class ClapTrap
{
	protected:
        std::string name;
        int hitpoints;
        int energypoints;
        int attackdamage;
    public:
        ClapTrap();
        ClapTrap(const std::string name);
        ClapTrap(const ClapTrap& c);
        ~ClapTrap();
        ClapTrap& operator=(const ClapTrap& c);
        
        void setName(std::string name);
        void setHitpoints(int points);
        void setEnergypoints(int points);
        void setAttackdamage(int attackdamage);
        
        std::string getName();
        int getHitpoints();
        int getEnergypoints();
        int getAttackdamage();
        
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
};

#endif