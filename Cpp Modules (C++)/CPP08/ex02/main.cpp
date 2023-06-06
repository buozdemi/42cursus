/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozdemi <buozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 20:48:23 by buozdemi          #+#    #+#             */
/*   Updated: 2023/04/28 13:19:25 by buozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int main(void)
{
	std::cout << " ---- MutantStack ---- " << std::endl;
	
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << "top: " << mstack.top() << std::endl;
	
	mstack.pop();
	std::cout << "size must be 1 : " << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(8);
	mstack.push(737);
	mstack.push(0);
	
	MutantStack<int>::iterator it1 = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	std::cout << "it1 : " << *it1 << std::endl;
	++it1;
	std::cout << "after ++it1 : " << *it1 << std::endl;
	--it1;

	while (it1 != ite)
	{
		std::cout << *it1 << std::endl;
		++it1;
	}
	std::cout << std::endl;
	std::stack<int> s(mstack);
	
	/* MutantStack<int>::iterator its = s.begin();
	std::cout << "its : " << *its << std::endl; */
	
	/* -------------------------------------------------------------------- */

	std::cout << std::endl;
	std::cout << " ---- List ---- " << std::endl;

	std::list<int> lst;
	lst.push_back(5);
	lst.push_back(17);
	std::cout << "back : " << lst.back() << std::endl;
	
	lst.pop_back();
	std::cout << "size must be 1: " << lst.size() << std::endl;

	lst.push_back(3);
	lst.push_back(8);
	lst.push_back(737);
	lst.push_back(0);
	
	std::list<int>::iterator lst_it1 = lst.begin();
	std::list<int>::iterator lst_ite = lst.end();
	
	std::cout << "lst_it1 : " << *lst_it1 << std::endl;
	++lst_it1;
	std::cout << "after ++lst_it1 : " << *lst_it1 << std::endl;
	--lst_it1;
	
	while (lst_it1 != lst_ite)
	{
		std::cout << *lst_it1 << std::endl;
		++lst_it1;
	}
	std::cout << std::endl;
	std::list<int> l(lst);

	return 0;
}
