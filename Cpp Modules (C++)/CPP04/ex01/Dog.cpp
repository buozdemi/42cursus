/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozdemi <buozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 19:25:03 by buozdemi          #+#    #+#             */
/*   Updated: 2023/06/06 12:05:11 by buozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void)
{
    std::cout << "Default(dog) constructor called" << std::endl;
    this->type = "Dog";
	this->brain = new Brain();
}

Dog::~Dog(void)
{
    std::cout << this->type << " I'm deleting my Brain" << std::endl;
	delete this->brain;
}

void    Dog::makeSound() const
{
    std::cout << "Dog: Haw Haw Haw" << std::endl;
}

Dog:: Dog(const Dog& d){
    std::cout << "Dog's copy constructor called" << std::endl;
	this->brain = new Brain(*d.brain);
    *this = d;
}

Dog& Dog::operator=(const Dog& d){
    std::cout << "Dog's copy assingnment operator called" << std::endl;
    if (this != &d)	
	{
		delete this->brain;
		this->brain = new Brain();
		*this->brain = *d.brain;
		this->type = d.type;
	}
    return *this;
}

Brain*	Dog::getBrain() const
{
	return (this->brain);
}