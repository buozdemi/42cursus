/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozdemi <buozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 16:35:19 by buozdemi          #+#    #+#             */
/*   Updated: 2023/06/06 12:05:24 by buozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "A brain without an idea was created" << std::endl;
}

Brain::~Brain()
{
	std::cout << "Brain is destroyed" << std::endl;
}

Brain::Brain(const Brain& b)
{
	std::cout << "Brain copy constructor called" << std::endl;
	*this = b;
}

Brain& Brain::operator=(const Brain& b)
{
	std::cout << "Brain copy assignment operator called" << std::endl;
	if (this != &b)
	{
		for(int i=0; i<100; i++)
			this->ideas[i] = b.ideas[i];
	}
	return *this;
}
