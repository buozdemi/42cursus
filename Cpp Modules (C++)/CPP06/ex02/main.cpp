/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozdemi <buozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 16:59:23 by buozdemi          #+#    #+#             */
/*   Updated: 2023/04/26 11:22:54 by buozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <iostream>

Base* generate(void)
{
	int	random;

	random = rand() % 3;
	if (random == 0)
		return (new A);
	else if (random == 1) 
		return (new B);
	else if (random == 2)
		return (new C);
	else
		return (NULL);
}

void identify(Base* p)
{
	if (dynamic_cast<A* >(p) != NULL)
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B* >(p) != NULL)
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C* >(p) != NULL)
		std::cout << "C" << std::endl;
}

void	identify(Base &p)
{
	Base	ptr;
	try
	{
		ptr = dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
	}
	catch(std::exception& e) {}
	try
	{
		ptr = dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
	}
	catch(std::exception& e) {}
	try
	{
		ptr = dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
	}
	catch(std::exception& e) {}
}

int main()
{
	Base	*base;

	srand(time(NULL));
	std::cout << "Identifying with pointers\n" << std::endl;

	base = generate();
	identify(base);
	delete base;

	base = generate();
	identify(base);
	delete base;

	base = generate();
	identify(base);
	delete base;

	base = generate();
	identify(base);
	delete base;
	
	base = generate();
	identify(base);
	delete base;

	std::cout << "\nIdentifying with references\n" << std::endl;

	base = generate();
	identify(*base);
	delete base;

	base = generate();
	identify(*base);
	delete base;

	base = generate();
	identify(*base);
	delete base;

	base = generate();
	identify(*base);
	delete base;

	base = generate();
	identify(base);
	delete base;
	
	return 0;
}

