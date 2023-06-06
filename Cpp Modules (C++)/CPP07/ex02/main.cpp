/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozdemi <buozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 16:10:23 by buozdemi          #+#    #+#             */
/*   Updated: 2023/04/26 19:14:32 by buozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

#define MAX_VAL 750
int main(int, char**)
{
	Array<int> a(10);

	try
	{
		a[6] = 8;
		std::cout << a[6] << std::endl;
		std::cout << a[50] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << "index is out of range" << std::endl;
	}
	
	std::cout << a.size() << std::endl;
	std::cout << "Data : " << a << std::endl;
	a[0] = 534;
	a[1] = 421;
	std::cout << a << std::endl;

	std::cout << "-----------------" << std::endl;
	Array<float> test0;
	Array<float> test1(3);
	Array<float> test2(3);
	test1[0] = 0.1;
	test1[1] = 0.2;
	test1[2] = 0.3;
	test2[0] = 2.1;
	test2[1] = 2.2;
	test2[2] = 2.3;

	test0 = test2;
	test1 = test2;
	
	std::cout << "float test0 :" << test0 << std::endl;
	std::cout << "float test2 :" << test2 << std::endl;


	std::cout << "-----------------" << std::endl;
	std::cout << "-----------------" << std::endl;
	std::cout << "-----------------" << std::endl;

	{
		Array<int> numbers(MAX_VAL);
	    int* mirror = new int[MAX_VAL];
	    srand(time(NULL));
	    for (int i = 0; i < MAX_VAL; i++)
	    {
	        const int value = rand();
	        numbers[i] = value;
	        mirror[i] = value;
	    }
	    //SCOPE
	    {
	        Array<int> tmp = numbers;
	        Array<int> test(tmp);
	    }

	    for (int i = 0; i < MAX_VAL; i++)
	    {
	        if (mirror[i] != numbers[i])
	        {
	            std::cerr << "didn't save the same value!!" << std::endl;
	            return 1;
	        }
	    }
	    try
	    {
	        numbers[-2] = 0;
	    }
	    catch(const std::exception& e)
	    {
	        std::cerr << e.what() << '\n';
	    }
	    try
	    {
	        numbers[MAX_VAL] = 0;
	    }
	    catch(const std::exception& e)
	    {
	        std::cerr << e.what() << '\n';
	    }

	    for (int i = 0; i < MAX_VAL; i++)
	    {
	        numbers[i] = rand();
	    }
	    delete [] mirror;
	}
    return 0;

}
