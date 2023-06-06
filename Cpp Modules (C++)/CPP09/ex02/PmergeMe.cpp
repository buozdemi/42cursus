/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozdemi <buozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 00:22:17 by buozdemi          #+#    #+#             */
/*   Updated: 2023/05/29 18:50:17 by buozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void	add_number_to_container(int argc, char **argv, std::deque<int> &my_deq, std::list<int> &my_lst)
{
	std::stringstream ss;
    for (int i = 1; i < argc; i++)
        ss << argv[i] << " ";
	
    std::string word;
    while (ss >> word)
    {
        char *ptr = NULL;
        int l;
        l = strtol(word.c_str(), &ptr, 10);
        if (*ptr == '\0' && (l > 0 && l <= INT_MAX))
		{
            my_lst.push_back(l);
			my_deq.push_back(l);
		}
        else
        {
            std::cerr << "Error: You entered wrong value as argument." << std::endl;
			exit(EXIT_FAILURE);
        }
    }
}

bool	is_valid_ctrl(std::string str)
{
	for (int i = 0; str[i]; i++)
	{
		if (str[0] == '+' || str[0] == ' ' || str[0] == '\t' || str[0] == '\n')
			i++;
		if (!isdigit(str[i]))
			return false;
	}
	return true;
}
