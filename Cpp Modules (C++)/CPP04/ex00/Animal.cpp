/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozdemi <buozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 19:16:32 by buozdemi          #+#    #+#             */
/*   Updated: 2023/06/06 12:06:14 by buozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void)
{
    std::cout << "Animal: Default constructor called" << std::endl;
    this->type = "Animal";
}

Animal::~Animal(void)
{
    this->type = "Animal";
    std::cout << this->type << " is destroyed" << std::endl;
}

void    Animal::makeSound() const
{
    std::cout << this->type << ": WRAGGG WRAGGG! Error" << std::endl;
}

std::string Animal::getType() const
{
    return (this->type);
}

Animal& Animal::operator=(const Animal& a)
{
		
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &a)
		this->type = a.type;
	return (*this);
}

Animal::Animal(const Animal& a)
{
	std::cout << "Animal copy constructor called" << std::endl;
	*this = a;
}
