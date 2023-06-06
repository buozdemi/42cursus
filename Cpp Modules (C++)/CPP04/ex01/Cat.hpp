/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozdemi <buozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 19:25:18 by buozdemi          #+#    #+#             */
/*   Updated: 2023/03/25 01:31:45 by buozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat: public Animal
{
	private:
		Brain *brain;
    public:
        Cat(void);
       	virtual ~Cat(void);
		Cat(const Cat& c);
        Cat& operator=(const Cat& c);
        void    makeSound() const;
		Brain*	getBrain() const;
};

#endif