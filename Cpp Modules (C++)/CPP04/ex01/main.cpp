/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozdemi <buozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 19:05:32 by buozdemi          #+#    #+#             */
/*   Updated: 2023/06/06 11:54:10 by buozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"


int main() 
{
	std::cout << "==================   BASIC TEST   ==================\n" << std::endl;

	Dog *dog = new Dog();
	Cat *cat = new Cat();

	std::cout << std::endl;

	std::cout << dog->getType() << std::endl;
	std::cout << cat->getType() << std::endl;

	std::cout << std::endl;

	dog->makeSound();
	cat->makeSound();


	std::cout << std::endl;

	// TEST DEEP COPY
	std::cout << "================== TEST DEEP COPY ==================\n" << std::endl;

	cat->getBrain()->ideas[0] = "I have to eat my food now";
	cat->getBrain()->ideas[1] = "I have to sleep in my warm bed now";
	cat->getBrain()->ideas[2] = "I have to pee";
	
	std::cout << "Cat ideas:" << std::endl;
	for (int i = 0; i < 3; i++) 
		std::cout << "Idea: " << cat->getBrain()->ideas[i] << std::endl;
	std::cout << std::endl;

	std::cout << "Create cat2" << std::endl;
	Cat *cat2 = new Cat();
	std::cout << std::endl;

	std::cout << "Cat2 ideas" << std::endl;
	for (int i = 0; i < 2; i++) std::cout << "(Should empty)Idea: " << cat2->getBrain()->ideas[i] << std::endl;
	std::cout << std::endl;

	std::cout << "*Cat2 = *Cat // Deep Copy" << std::endl;
	*cat2 = *cat;
	std::cout << std::endl;
	
	std::cout << "Just one pointer named Cat3 and Cat3 = Cat // Shallow Copy" << std::endl;
	Cat *cat3;
	cat3 = cat;
	std::cout << std::endl;

	std::cout << "Cat ideas:" << std::endl;
	for (int i = 0; i < 2; i++) std::cout << "Idea: " << cat->getBrain()->ideas[i] << std::endl;
	std::cout << std::endl;

	std::cout << "Cat2 ideas" << std::endl;
	for (int i = 0; i < 2; i++) std::cout << "Idea: " << cat2->getBrain()->ideas[i] << std::endl;
	std::cout << std::endl;

	std::cout << "Cat ideas (now he hates ice cream)" << std::endl;
	cat->getBrain()->ideas[1] = "I hate ice cream";
	for (int i = 0; i < 2; i++) std::cout << "Idea: " << cat->getBrain()->ideas[i] << std::endl;
	std::cout << std::endl;

	std::cout << "Cat2 ideas" << std::endl;
	for (int i = 0; i < 2; i++) std::cout << "(We changed the mind of the 1. Cat. Has that changed too?) Idea: " << cat2->getBrain()->ideas[i] << std::endl;
	std::cout << std::endl;

	std::cout << "Cat3 ideas" << std::endl;
	for (int i = 0; i < 2; i++) std::cout << "(We changed the mind of the 1. Cat. Has that changed too?) Idea: " << cat3->getBrain()->ideas[i] << std::endl;
	std::cout << std::endl;

	std::cout << "==================   CLEAN ALL    ==================\n" << std::endl;

	delete dog;
	delete cat;
	delete cat2;

	std::cout << std::endl;

	std::cout << "================ SUBJECT ARRAY TEST ================\n" << std::endl;

	Animal *animals[100];

	for (int i = 0; i < 100; i++) {
		if (i < 100 / 2) {
			animals[i] = new Cat();
		} else {
			animals[i] = new Dog();
		}
	}

	std::cout << std::endl;

	for (int i = 0; i < 100; i++) {
		animals[i]->makeSound();
	}

	std::cout << std::endl;

	for (int i = 0; i < 100; i++) {
		delete animals[i];
	}

	std::cout << "\ntest wrong's\n" << std::endl;

    const WrongAnimal* k = new WrongCat();
    k->makeSound();
	delete k;
	
	const WrongCat* m = new WrongCat();
    m->makeSound();
	delete k;

	system("leaks Animal");

}
		/* const Animal *Animals[2] = {new Dog(), new Cat()};

		delete Animals[0]; //should not create a leak delete i;
		delete Animals[1];
		system("leaks Animal");
		const WrongAnimal *Animal = new WrongCat();
		delete Animal;
		system("leaks Animal");
		return 0; */
