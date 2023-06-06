/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozdemi <buozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 19:16:44 by buozdemi          #+#    #+#             */
/*   Updated: 2023/03/25 14:59:46 by buozdemi         ###   ########.fr       */
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
        Animal(const Animal& a);
        virtual ~Animal(void);
        Animal& operator=(const Animal& a);
        virtual void    makeSound() const = 0;
        std::string getType() const;
};

#endif