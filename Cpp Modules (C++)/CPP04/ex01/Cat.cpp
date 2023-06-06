/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozdemi <buozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 19:25:16 by buozdemi          #+#    #+#             */
/*   Updated: 2023/06/06 12:04:59 by buozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void)
{
    std::cout << "Default(cat) constructor called" << std::endl;
    this->type = "Cat";
	this->brain = new Brain();
}

Cat::~Cat(void)
{
    std::cout << this->type << " I'm deleting my Brain" << std::endl;
	delete this->brain;
}

void    Cat::makeSound() const
{
    std::cout << "Cat: Meoowwww" << std::endl;
}

Cat::Cat(const Cat& c)
{
	std::cout << "Cat copy constructor called" << std::endl;
	this->brain = new Brain(*c.brain);
	*this = c;
}

Cat& Cat::operator=(const Cat& c)
{
	std::cout << "Cat's copy assignment operator called" << std::endl;
	if (this != &c)
	{
		delete this->brain;
		this->brain = new Brain();
		*this->brain = *c.brain;
		this->type = c.type;
	}
	return (*this);
}

Brain*	Cat::getBrain() const
{
	return (this->brain);
}
