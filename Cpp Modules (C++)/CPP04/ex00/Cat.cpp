/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozdemi <buozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 19:25:16 by buozdemi          #+#    #+#             */
/*   Updated: 2023/03/25 00:41:36 by buozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void)
{
    std::cout << "Default(cat) constructor called" << std::endl;
    this->type = "Cat";
}

Cat::~Cat(void)
{
    std::cout << this->type << " is destroyed" << std::endl;
}

void    Cat::makeSound() const
{
    std::cout << "Cat: Meoowwww" << std::endl;
}
