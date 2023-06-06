/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozdemi <buozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 18:29:15 by buozdemi          #+#    #+#             */
/*   Updated: 2023/03/16 13:27:15 by buozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP
# include "Weapon.hpp"
# include <iostream>

class HumanB
{
	private:
		std::string name;
		Weapon *weapon;
	public:
		void	attack();
		void	setWeapon(Weapon& weapon);
		HumanB(std::string name);
		~HumanB();
};

#endif