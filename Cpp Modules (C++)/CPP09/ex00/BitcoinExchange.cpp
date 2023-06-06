/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozdemi <buozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 11:36:32 by buozdemi          #+#    #+#             */
/*   Updated: 2023/05/29 20:41:30 by buozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

void	BitcoinExchange::my_multiplication(float closest_date_val, std::vector<std::pair<std::string, std::string> >::iterator &it_n)
{
	char *endptr = NULL;
	float f_value = std::strtof(it_n->second.c_str(), &endptr);
	
	if (!isdigit(it_n->second[0]) && it_n->second[0] != '+')
	{
		std::cout << "Error: bad value => " << it_n->second << std::endl;
		return;
	}
	std::cout << it_n->first << " => " << f_value << " = " << (closest_date_val * f_value) << std::endl;
}

float BitcoinExchange::find_date(std::vector<std::pair<std::string, std::string> >::iterator &it_n)
{
	std::map<std::string, float>::const_iterator it_v = _v.find(it_n->first);
	if (it_v != _v.end()) {
		return it_v->second;
	}
	std::map<std::string, float>::iterator it = _v.lower_bound(it_n->first);
	it--;
	return it->second;
}

void	BitcoinExchange::add_to_vector(std::string &date, std::string &value, int csv)
{
	if(csv == 1)
	{
		char *endptr = NULL;
		float f_val = std::strtof(value.c_str(), &endptr);
		this->_v.insert(std::make_pair(date, f_val));
	}
	else
	{
		this->_n.push_back(std::make_pair(date, value));
	}
}

void	BitcoinExchange::separate_date_value(std::string &one_line, int csv)
{
	std::string str_date;
	std::string str_value;
	std::string delimiter;
	std::string empty_value;
	std::string empty_date;

	if (csv == 1)
		delimiter = ",";
	else
		delimiter = " | ";
	int pos_delimiter = one_line.find(delimiter);
	if (pos_delimiter == -1)
	{
		add_to_vector(empty_date, empty_value, 3);
		return;
	}
	str_date = one_line.substr(0, pos_delimiter);
	str_value = one_line.substr(pos_delimiter + csv, one_line.size() - 1);

	if (csv == 1)
		add_to_vector(str_date, str_value, 1);
	else
		add_to_vector(str_date, str_value, 3);
	
}

bool BitcoinExchange::is_valid_date(int &year, int &month, int &day)
{
    if (month < 1 || month > 12 || day < 1 || day > 31 || year > 9999)
        return false;
    int days_in_month[] = {31, 28 + is_leap_year(year), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (day > days_in_month[month - 1])
        return false;
	if (year <= 2009)
	{
		if (year == 2009)
		{
			if (month == 1)
			{
				if (day < 2)
					return false;
			}
		}
		else
			return false;
	}
    return true;
}

int BitcoinExchange::is_leap_year(int &year)
{
    if (year % 4 != 0)
        return 0;
    else if (year % 100 != 0)
        return 1;
    else if (year % 400 != 0)
        return 0;
    else
        return 1;
}

void	BitcoinExchange::value_control_and_write(std::vector<std::pair<std::string, std::string> >::iterator &it_n)
{
	if (it_n->second.empty())
	{
		std::cout << "Error: empty value => EMPTY" << std::endl;
		return ;
	}
	char* endptr = NULL;
	long l_value = std::strtol(it_n->second.c_str(), &endptr, 10);
	if (*endptr == '\0')
	{
		if (l_value <= 0)
			std::cerr << "Error: not a positive number." << std::endl;
		else if(l_value >= 1000)
			std::cerr << "Error: too large number." << std::endl;
		else
			my_multiplication(find_date(it_n), it_n);
	}
	else
	{
		endptr = NULL;
		float f_value = std::strtof(it_n->second.c_str(), &endptr);
		if (((endptr[0] == 'f' && endptr[1] == '\0') || (endptr[0] == '\0')) && !(it_n->second[0] == 'f' && it_n->second[1] == '\0'))
		{
			if (f_value <= 0)
				std::cerr << "Error: not a positive number." << std::endl;
			if (f_value >= 1000)
				std::cerr << "Error: too large number." << std::endl;
			else
				my_multiplication(find_date(it_n), it_n);
		}
		else
			std::cerr << "Error: bad value => " << it_n->second << std::endl;
	}
}

void BitcoinExchange::dv_control_and_push(std::vector<std::pair<std::string, std::string> >::iterator &it_n)
{
    int year, month, day;
    
	if (std::sscanf(it_n->first.c_str(), "%d-%d-%d", &year, &month, &day) != 3 || !isdigit(it_n->first[0]))
	{
		std::cout << "Error: bad input => " << it_n->first << std::endl;
        return;
	}
	if (!is_valid_date(year, month, day))
	{
		std::cout << "Error: bad input => " << it_n->first << std::endl;
        return;
	}
	value_control_and_write(it_n);
}

const char* BitcoinExchange::FileNotOpened::what() const _NOEXCEPT
{
	return ("Error: The file you entered could not be opened.");
}

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::~BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy)
{
	this->_v = copy._v;
	this->_n = copy._n;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &copy)
{
	if (this == &copy)
		return (*this);
	this->_v = copy._v;
	this->_n = copy._n;
	return (*this);
}