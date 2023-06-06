/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozdemi <buozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 18:29:12 by buozdemi          #+#    #+#             */
/*   Updated: 2023/03/14 13:36:59 by buozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP
# include "Weapon.hpp"
# include <iostream>

class HumanA
{
	private:
		std::string name;
		Weapon& weapon;
	public:
		void	attack();
		HumanA(std::string name, Weapon& weapon);
		~HumanA();
};

#endif