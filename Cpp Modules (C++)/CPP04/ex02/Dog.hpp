/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozdemi <buozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 19:25:22 by buozdemi          #+#    #+#             */
/*   Updated: 2023/03/25 15:03:13 by buozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog: public Animal
{
	private:
		Brain *brain;
    public:
        Dog(void);
       	virtual ~Dog(void);
		Dog(const Dog& d);
        Dog& operator=(const Dog& d);
        void    makeSound() const;
		Brain*	getBrain() const;
};

#endif