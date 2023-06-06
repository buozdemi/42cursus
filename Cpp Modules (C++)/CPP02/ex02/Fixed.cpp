/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozdemi <buozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 11:23:03 by buozdemi          #+#    #+#             */
/*   Updated: 2023/03/17 17:49:51 by buozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	this->num = 0;
}

Fixed::~Fixed()
{
}

Fixed::Fixed(const float num)
{
	this->num = std::roundf(num * (1 << this->fract));
}

Fixed::Fixed(const int num)
{
	this->num = (num << this->fract);
}

Fixed::Fixed(const Fixed& other)
{
	this->num = other.getRawBits();
}

void Fixed::setRawBits(int const num)
{
	this->num = num;
}

int Fixed::getRawBits(void) const
{
	return(this->num);
}

float Fixed::toFloat(void) const
{
	return ((this->num / (float)(1 << this->fract)));
}

int Fixed::toInt( void ) const
{
	return ((this->num >> this->fract));
}

Fixed& Fixed::operator=(const Fixed& other)
{
	if (this != &other)
		this->setRawBits(other.getRawBits());
	return (*this);
}

float Fixed::operator+(const Fixed& other) const
{
	return (this->toFloat() + other.toFloat()); 
}

float Fixed::operator-(const Fixed& other) const
{
	return (this->toFloat() - other.toFloat()); 
}

float Fixed::operator*(const Fixed& other) const
{
	return (this->toFloat() * other.toFloat()); 
}

float Fixed::operator/(const Fixed& other) const
{
	return (this->toFloat() / other.toFloat()); 
}

bool	Fixed::operator>(const Fixed& other) const
{
	return (this->toFloat() > other.toFloat());
}

bool	Fixed::operator<(const Fixed& other) const
{
	return (this->toFloat() < other.toFloat());
}

bool	Fixed::operator>=(const Fixed& other) const
{
	return (this->toFloat() >= other.toFloat());
}

bool	Fixed::operator<=(const Fixed& other) const
{
	return (this->getRawBits() <= other.getRawBits());
}

bool	Fixed::operator==(const Fixed& other) const
{
	return (this->getRawBits() == other.getRawBits());
}

bool	Fixed::operator!=(const Fixed& other) const
{
	return (this->getRawBits() != other.getRawBits());
}

std::ostream& operator<<(std::ostream &_my_cout, Fixed const &right)
{
	_my_cout << right.toFloat();
	return(_my_cout);
}

Fixed Fixed::operator++(void)
{
	this->setRawBits(this->getRawBits() + 1);
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed temp;

	this->setRawBits(this->getRawBits() + 1);
	temp.setRawBits(this->getRawBits() - 1);
	return (temp);
}

Fixed Fixed::operator--(void)
{
	this->setRawBits(this->getRawBits() - 1);
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed temp;

	this->setRawBits(this->getRawBits() - 1);
	temp.setRawBits(this->getRawBits() + 1);
	return (temp);
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	if (a.toFloat() > b.toFloat())
		return (a);
	return (b);
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	if (a.toFloat() > b.toFloat())
		return (b);
	return (a);
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	if (a.toFloat() > b.toFloat())
		return (a);
	return (b);
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	if (a.toFloat() > b.toFloat())
		return (b);
	return (a);
}
