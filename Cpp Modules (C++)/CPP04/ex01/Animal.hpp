/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozdemi <buozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 19:16:44 by buozdemi          #+#    #+#             */
/*   Updated: 2023/03/25 00:56:04 by buozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

# include <iostream>
# include "Brain.hpp"

class Animal
{
    protected:
        std::string type;
    public:
        Animal(void);
        virtual ~Animal(void);
        Animal(const Animal& a);
        Animal& operator=(const Animal& a);
        virtual void    makeSound() const;
        std::string getType() const;
};

#endif