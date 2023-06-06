/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozdemi <buozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 19:25:03 by buozdemi          #+#    #+#             */
/*   Updated: 2023/03/25 00:41:44 by buozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void)
{
    std::cout << "Default(dog) constructor called" << std::endl;
    this->type = "Dog";
}

Dog::~Dog(void)
{
    std::cout << this->type << " is destroyed" << std::endl;
}

void    Dog::makeSound() const
{
    std::cout << "Dog: Haw Haw Haw" << std::endl;
}
