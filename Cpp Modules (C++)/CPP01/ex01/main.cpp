/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozdemi <buozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 13:41:35 by buozdemi          #+#    #+#             */
/*   Updated: 2023/03/16 11:53:56 by buozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	Zombie *we = zombieHorde(4, "Hortkuluk");

	for (size_t i = 0; i < 4; i++) {
        we[i].announce();
    }

	delete [] we;
	return 0;
}
