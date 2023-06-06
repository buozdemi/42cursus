/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozdemi <buozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 20:19:46 by buozdemi          #+#    #+#             */
/*   Updated: 2023/03/17 13:44:12 by buozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
	private:
		int num;
		static const int fract = 8;
	public:
		Fixed();
		Fixed(const Fixed& that);
		Fixed(const float number);
		Fixed(const int number);
		~Fixed();
		Fixed& operator=(const Fixed& that);
		int	getRawBits(void) const;
		void setRawBits(const int raw);
		float toFloat( void ) const;
		int toInt( void ) const;
};

std::ostream& operator<<(std::ostream &_my_cout, Fixed const &fixed_number);

#endif