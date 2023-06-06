/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozdemi <buozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 16:27:57 by buozdemi          #+#    #+#             */
/*   Updated: 2023/06/06 11:23:04 by buozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void	Contact::setData(std::string data)
{
	this->data[i] = data;
}

std::string	Contact::getData(int i)
{
	return (this->data[i]);
}

int	Contact::is_full_data()
{
	int	i;
	int	letter_num;

	letter_num = 0;
	i = 0;
	while (data[this->i][i])
	{
		if (std::iswalnum(data[this->i][i]))
			letter_num++;
		i++;
	}
	if (letter_num != 0)
	{
		this->i++;
		return (1);
	}
	return (0);
}

int	Contact::is_digit()
{
	int	i;

	i = 0;
	while (data[this->i][i])
	{
		if (!std::isdigit(data[this->i][i]))
			return (0);
		i++;
	}
	if (data[this->i].empty())
		return (0);
	this->i++;
	return (1);
}
