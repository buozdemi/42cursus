/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozdemi <buozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 16:45:55 by buozdemi          #+#    #+#             */
/*   Updated: 2023/06/06 11:22:58 by buozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

void PhoneBook::index_fill_plus()
{
	index_fill++;
	if (index_fill == 8)
	{
		index_fill = 0;
		full_people = 1;
	}	
}

void PhoneBook::index_write_plus()
{
	index_write++;
}

void PhoneBook::index_write_new_value(int i)
{
	this->index_write = i;
}

int PhoneBook::get_index_fill()
{
	return (this->index_fill);
}

int PhoneBook::get_index_write()
{
	return (this->index_write);
}

Contact	*PhoneBook::getContact_len()
{
	return (&this->contacts[this->index_fill]);
}

Contact PhoneBook::getContact()
{
	return (this->contacts[this->index_write]);
}

Contact PhoneBook::getContact_num(int i)
{
	return (this->contacts[i - 1]);
}

int PhoneBook::get_full_people()
{
	return(this->full_people);
}
