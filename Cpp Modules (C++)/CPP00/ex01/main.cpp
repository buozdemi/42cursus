/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozdemi <buozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 12:38:56 by buozdemi          #+#    #+#             */
/*   Updated: 2023/06/06 12:12:12 by buozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

int main(int argc, char **argv)
{
	PhoneBook phonebook;
	std::string input;
	(void)argc;
	(void)argv;
	
	while (1)
	{
		std::cout << "Hurry Up! ADD, SEARCH or EXIT!" << std::endl << "C'mon bitch I'm waiting for you: " << std::endl;
		std::getline(std::cin, input);
		if(input == "ADD")
		{
			phonebook.getContact_len()->fill_name();
			phonebook.getContact_len()->fill_lastname();
			phonebook.getContact_len()->fill_nickname();
			phonebook.getContact_len()->fill_phonenumber();
			phonebook.getContact_len()->fill_secret();
			phonebook.index_fill_plus();
		}
		else if(input == "SEARCH")
		{
			phonebook.my_search();
		}
		else if(input == "EXIT")
			break ;
		else
			std::cout << "Invalid command\n" << std::endl;
	}
}

void PhoneBook::my_search()
{
	int data_num;
	int number;
	int ctl;
	int index_fil;

	number = 1;
	index_fil = get_index_fill();
	index_write_new_value(0);
	ctl = 0;
	if (get_full_people() == 1)
	{
		ctl = 8;
		index_fil = 0;
	}
	std::cout << "|---------- BITCH'S PHONE NUMBERS ----------|\n";
	std::cout << "|-------------------------------------------|\n";
	std::cout << "|   LIST NO|      NAME|  LASTNAME|  NICKNAME|\n";
	std::cout << "|-------------------------------------------|\n";
	while (number != index_fil + ctl + 1) // index_fill = 0;
	{
		data_num = 0;
		std::cout <<  "|" << std::right << std::setw(10) << number;
		std::cout << "|";
		while (data_num != 3)
		{	
			if ((getContact().getData(data_num)).length() > 10)
				std::cout << std::right << std::setw(9) << getContact().getData(data_num).substr(0, 9) << ".";
			else
				std::cout << std::right << std::setw(10) << getContact().getData(data_num);
			if (data_num != 2)
				std::cout << "|";
			data_num++;
		}
		std::cout << "|" << std::endl;
		number++;
		index_write_plus();
	}
	std::cout << "|-------------------------------------------|\n";
	choose_name();
}

void	PhoneBook::choose_name()
{
	std::string num;
	int data_num;
	int	numm;
	
	data_num = 0;
	while (1)
	{
		std::cout << "Which bitch will you call? Enter number: ";
		std::getline(std::cin, num);
		numm = atoi(num.c_str());
		if (numm > 0 && numm < 9)
		{
			std::cout << "----------" << std::endl;
			while (data_num != 6)
			{
				front_data(data_num);
				if (data_num == 0)
					std::cout << numm << std::endl;
				else
					std::cout << getContact_num(numm).getData(data_num - 1) << std::endl;
				data_num++;
			}
			std::cout << "----------" << std::endl;
			break ;
		}
		else
			std::cout << "Enter the valid number bitch!\n";
	}
}

void	front_data(int data_num)
{
	if (data_num == 0)
		std::cout << "LIST NO  : ";
	if (data_num == 1)
		std::cout << "NAME     : ";
	if (data_num == 2)
		std::cout << "LASTNAME : ";
	if (data_num == 3)
		std::cout << "NICKNAME : ";
	if (data_num == 4)
		std::cout << "PHONE NO : ";
	if (data_num == 5)
		std::cout << "DARKEST SECRET : ";
}
