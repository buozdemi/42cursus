/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fstream.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozdemi <buozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 14:53:10 by buozdemi          #+#    #+#             */
/*   Updated: 2023/03/16 14:53:49 by buozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fstream.hpp"

std::string replace(std::string str, std::string tofind, std::string toreplace)
{
    size_t	found = str.find(tofind);
    while (found != std::string::npos)
    {
        str.erase(found , tofind.length());
       	str.insert(found, toreplace);
        found = str.find(tofind);
    }
    return (str);
}

int error(std::string fileName, std::string search, std::string replace)
{
	if (fileName.empty() || search.empty() || replace.empty())
	{
		std::cout << "Arguments cannot be empty" << std::endl;
		return (1);
	}
	return (0);
}
