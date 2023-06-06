/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozdemi <buozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 13:41:24 by buozdemi          #+#    #+#             */
/*   Updated: 2023/03/16 12:05:07 by buozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
# include <iostream>

class Zombie
{
	std::string name;

	public:
		Zombie(void);
		~Zombie(void);
		void	announce();
		void 	setName(std::string z_name);
};

Zombie *zombieHorde(int N, std::string name);

#endif