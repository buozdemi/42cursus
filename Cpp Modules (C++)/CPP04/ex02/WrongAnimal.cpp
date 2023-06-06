/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozdemi <buozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 14:31:48 by buozdemi          #+#    #+#             */
/*   Updated: 2023/06/06 12:07:22 by buozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
    std::cout << "WrongAnimal: Default constructor called" << std::endl;
    this->type = "WrongAnimal";
}
    
WrongAnimal::~WrongAnimal()
{
	this->type = "WrongAnimal";
    std::cout << this->type << " is destroyed" << std::endl;
}

void    WrongAnimal::makeSound() const
{
    std::cout << this->type << ": WRAGGG WRAGGG! Error" << std::endl;
}

std::string WrongAnimal::getType() const
{
    return (this->type);
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& a)
{
	std::cout << "WrongAnimal copy assignment operator called" << std::endl;
	if (this != &a)
		this->type = a.type;
	return (*this);
}

WrongAnimal::WrongAnimal(const WrongAnimal& a)
{
	std::cout << "WrongAnimal copy constructor called" << std::endl;
	*this = a;
}
