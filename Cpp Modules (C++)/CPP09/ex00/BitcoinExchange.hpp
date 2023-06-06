/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozdemi <buozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 11:36:34 by buozdemi          #+#    #+#             */
/*   Updated: 2023/05/16 18:50:12 by buozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <cstdlib>
#include <fstream>
#include <cstdio>

class BitcoinExchange
{	
	public:
		std::map<std::string, float> _v;
		std::vector<std::pair<std::string, std::string> > _n;

		void	separate_date_value(std::string &one_line, int csv);
		void	dv_control_and_push(std::vector<std::pair<std::string, std::string> >::iterator &it_n);
		bool	is_valid_date(int &year, int &month, int &day);
		int		is_leap_year(int &year);
		void	value_control_and_write(std::vector<std::pair<std::string, std::string> >::iterator &it_n);
		void	add_to_vector(std::string &date, std::string &value, int csv);
		float	find_date(std::vector<std::pair<std::string, std::string> >::iterator &it_n);
		void	my_multiplication(float closest_date_val, std::vector<std::pair<std::string, std::string> >::iterator &it_n);
		
		BitcoinExchange();
		~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &copy);
		BitcoinExchange &operator=(const BitcoinExchange &copy);

		class FileNotOpened : public std::exception
		{
			public:
				virtual const char* what() const _NOEXCEPT;
		};
	
};

#endif