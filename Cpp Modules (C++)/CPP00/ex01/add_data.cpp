/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_data.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozdemi <buozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 14:14:26 by buozdemi          #+#    #+#             */
/*   Updated: 2023/06/06 11:23:08 by buozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

void	Contact::fill_name()
{
	std::string input;
	
	while (1)
	{
		std::cout << "Okey bitch. Enter the new bitch's Name: ";
		std::getline(std::cin, input);
		setData(input);
		if (is_full_data() == 0)
			std::cout << "What a waste you're, you entered the values wrong. Try again now!" << std::endl;
		else
			break ;
	}
}

void	Contact::fill_lastname()
{
	std::string input;

	while (1)
	{
		std::cout << "Go bitch go! Enter the bitch's Lastname: ";
		std::getline(std::cin, input);
		setData(input);
		if (is_full_data() == 0)
			std::cout << "What a waste you're, you entered the values wrong. Try again now!" << std::endl;
		else
			break ;
	}
}

void	Contact::fill_nickname()
{
	std::string input;
	
	while (1)
	{
		std::cout << "Puffff... Enter the bitch's Nickname: ";
		std::getline(std::cin, input);
		setData(input);
		if (is_full_data() == 0)
			std::cout << "What a waste you're, you entered the values wrong. Try again now!" << std::endl;
		else
			break ;
	}
}

void	Contact::fill_phonenumber()
{
	std::string input;
	
	while (1)
	{
		std::cout << "You're too slow! Enter the bitch's Phone Number: ";
		std::getline(std::cin, input);
		setData(input);
		if (is_digit() == 0)
			std::cout << "Idiot! Enter only numbers!" << std::endl;
		else
			break ;
	}
}

void	Contact::fill_secret()
{
	std::string input;
	
	while (1)
	{
		std::cout << "Finish, you can do it! Enter the bitch's Secret: ";
		std::getline(std::cin, input);
		setData(input);
		if (is_full_data() == 0)
			std::cout << "What a waste you're, you entered the values wrong. Try again now!" << std::endl;
		else
		{
			this->i = 0;
			break ;
		}
	}
}
