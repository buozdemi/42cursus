/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozdemi <buozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 11:45:53 by buozdemi          #+#    #+#             */
/*   Updated: 2023/06/06 10:56:09 by buozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(ScalarConverter const &) {}

ScalarConverter	& ScalarConverter::operator=(ScalarConverter const &){return *this;
}

ScalarConverter::~ScalarConverter() {}

void	printDouble(double d)
{
	char c = static_cast<char>(d);
	if (std::isnan(d) || std::isinf(d) || d < CHAR_MIN || d > CHAR_MAX)
		std::cout << "char:	impossible" << std::endl;
	else if (std::isprint(c))
		std::cout << "char:	'" << c << "'" << std::endl;
	else
		std::cout << "char:	Non displayable" << std::endl;
	if (std::isnan(d) || std::isinf(d) || d > (double)INT_MAX || d < (double)INT_MIN)
		std::cout << "int:	impossible" << std::endl;
	else
		std::cout << "int:	" << static_cast<int>(d) << std::endl;
	std::cout << "float:	" << static_cast<float>(d) << 'f' << std::endl;
	std::cout << "double:	" << d << std::endl;
}

void	printFloat(float f)
{
	char c = static_cast<char>(f);
	if (std::isnan(f) || std::isinf(f) || f < CHAR_MIN || f > CHAR_MAX)
		std::cout << "char:	impossible" << std::endl;
	else if (std::isprint(c))
		std::cout << "char:	'" << c << "'" << std::endl;
	else
		std::cout << "char:	Non displayable" << std::endl;
	if (std::isnan(f) || std::isinf(f) || f > (float)INT_MAX || f < (float)INT_MIN)
		std::cout << "int:	impossible" << std::endl;
	else
		std::cout << "int:	" << static_cast<int>(f) << std::endl;
	std::cout << "float:	" << f << 'f' << std::endl;
	std::cout << "double:	" << static_cast<double>(f) << std::endl;
}

void	printInt(long i)
{
	char c = static_cast<char>(i);
	if (i < CHAR_MIN || i > CHAR_MAX)
		std::cout << "char:	impossible" << std::endl;
	else if (std::isprint(c))
		std::cout << "char:	'" << c << "'" << std::endl;
	else
		std::cout << "char:	Non displayable" << std::endl;
	if (i > INT_MAX || i < INT_MIN)
		std::cout << "int:	impossible" << std::endl;
	else
		std::cout << "int:	" << i << std::endl;
	std::cout << "float:	" << static_cast<float>(i) << 'f' << std::endl;
	std::cout << "double:	" << static_cast<double>(i) << std::endl;
}

void	printChar(char c)
{	
	if (std::isprint(c))
		std::cout << "char:	'" << c << "'" << std::endl;
	else
		std::cout << "char:	Non displayable" << std::endl;
	std::cout << "int:	" << static_cast<int>(c) << std::endl;
	std::cout << "float:	" << static_cast<float>(c) << 'f' << std::endl;
	std::cout << "double:	" << static_cast<double>(c) << std::endl;
}

std::string	getType(const std::string input)
{
	if (input.empty())
		return "empty";
	else if (input.length() == 1 && !std::isdigit(input[0]))
		return "char";
	else
	{
		char* endptr = NULL;
		std::strtol(input.c_str(), &endptr, 10);
		if (*endptr == '\0') {
			return "int";
		}
		else
		{
			endptr = NULL;
			std::strtod(input.c_str(), &endptr);
			if (*endptr == '\0') {
				return "double";
			}
			else
			{
				endptr = NULL;
				std::strtof(input.c_str(), &endptr);
				if ((endptr[0] == 'f' && endptr[1] == 0)) {
					return "float";
				}
				else
					return "unknown";
			}
		}
	}
}

void ScalarConverter::convert(const std::string input)
{	
	std::string type = getType(input);
	if (type == "char") {
		char c = input[0];
		printChar(c);
	} else if (type == "int") {
		long l = std::atol(input.c_str());
		printInt(l);
	} else if (type == "float") {
		float f = std::strtof(input.c_str(), NULL);
		printFloat(f);
	} else if (type == "double") {
		double d = std::strtod(input.c_str(), NULL);
		printDouble(d);
	} else
	{
		if (errno){
			std::perror("Error");
		}else
			std::cout << "type: " + type << std::endl;
	}
}
