/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozdemi <buozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 13:32:27 by buozdemi          #+#    #+#             */
/*   Updated: 2023/03/16 14:56:15 by buozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fstream.hpp"

int main(int argc, char *argv[])
{
	if (argc != 4)
	{
		std::cout << "Error: Usage: ./program [fileName] [search] [replace]" << std::endl;
		return (1);
	}
	std::string fileName = argv[1];
	std::string tofind = argv[2];
	std::string toreplace = argv[3];
	if (error(fileName, tofind, toreplace))
		return (2);
	
	std::string str;
	std::ifstream ifs(fileName);
	if (!ifs.is_open())
	{
		std::cout << "Error: File cannot be opened" << std::endl;
		return (3);
	}

	std::getline(ifs, str, '\0');
	ifs.close();
	str = replace(str, tofind, toreplace);
	std::ofstream ofs(fileName + ".replace");
	ofs << str;
	ofs.close();
	return (0);
}
