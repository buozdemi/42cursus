/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozdemi <buozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 20:19:44 by buozdemi          #+#    #+#             */
/*   Updated: 2023/03/17 16:14:47 by buozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructer called" << std::endl;
	this->num = 0;
}

Fixed::Fixed(const Fixed& that)
{
	std::cout << "Copy constructer called" << std::endl;
	*this = that;
}

Fixed::Fixed(const int number)
{
	std::cout << "Int constructer called" << std::endl;
	this->num = (number << this->fract);
}

Fixed::Fixed(const float number)
{
	std::cout << "Float constructer called" << std::endl;
	this->num = std::roundf(number * (1 << this->fract));
}

Fixed::~Fixed()
{
	std::cout << "Destructer called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& that) 	
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &that)
		this->setRawBits(that.getRawBits());
	return (*this);
}

int	Fixed::getRawBits(void) const
{
	return(this->num);
}

void Fixed::setRawBits(int const raw)
{
	this->num = raw;
}

float Fixed::toFloat( void ) const
{
	return ((this->num / (float)(1 << this->fract)));
}

int Fixed::toInt( void ) const
{
	 return ((this->num >> this->fract));
}

std::ostream& operator<<(std::ostream &_my_cout, Fixed const &fixed_number)
{
	_my_cout << fixed_number.toFloat();
	return _my_cout;
}
