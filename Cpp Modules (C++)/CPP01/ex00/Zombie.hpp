/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozdemi <buozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 17:41:44 by buozdemi          #+#    #+#             */
/*   Updated: 2023/03/16 13:10:12 by buozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
# include <iostream>

class Zombie
{
	private:
		std::string Name;
	public:
		Zombie(std::string name);
		~Zombie();
		void	announce(void);
		std::string getName();
};

Zombie* newZombie(std::string name);
void	randomChump(std::string name);

#endif