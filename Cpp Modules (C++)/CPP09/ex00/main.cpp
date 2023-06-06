/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozdemi <buozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 11:35:59 by buozdemi          #+#    #+#             */
/*   Updated: 2023/06/06 10:48:25 by buozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char *argv[])
{	
	if (argc != 2)
	{
		std::cout << "Error: could not open file." << std::endl;
		exit(EXIT_FAILURE);
	}
	std::ifstream file(argv[1]);
	try
	{
		BitcoinExchange exchange;
		std::string line;
		std::string returned;
		
		for (int i = 3; i > 0; i-=2) // Burada önce input.txt'mizi okuyup container'ımıza yazıyoruz, sonrasında ise data.csv'yi okuyup diğer containerımıza yazıyoruz.
		{
			if(!file.is_open())
				throw BitcoinExchange::FileNotOpened();
			while(std::getline(file, line))
				exchange.separate_date_value(line, i);
			line.clear();
			file.close();
			if (i != 1)
				file.open("data.csv");
		}

		std::vector<std::pair<std::string, std::string> >::iterator it_n = exchange._n.begin();
		std::vector<std::pair<std::string, std::string> >::iterator it_last = exchange._n.end();
		for (; it_n != it_last; it_n++)
			exchange.dv_control_and_push(it_n);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
