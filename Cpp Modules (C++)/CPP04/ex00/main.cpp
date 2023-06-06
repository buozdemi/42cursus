/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozdemi <buozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 19:05:32 by buozdemi          #+#    #+#             */
/*   Updated: 2023/03/25 14:43:59 by buozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main() 
{
    const Animal* meta = new Animal();
    const Animal* dog = new Dog();
    const Animal* cat = new Cat();
    std::cout << dog->getType() << " " << std::endl; 
    std::cout << cat->getType() << " " << std::endl; 
    dog->makeSound(); //will output the dog sound! 
    cat->makeSound();
    meta->makeSound();
	delete meta;
	delete dog;
	delete cat;

	std::cout << "\ntest wrong's\n" << std::endl;

    const WrongAnimal* k = new WrongCat();
    k->makeSound();
	delete k;
	
	const WrongCat* m = new WrongCat();
    m->makeSound();
	delete k;

    return 0;
}
