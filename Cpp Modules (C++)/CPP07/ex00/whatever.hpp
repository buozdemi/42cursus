/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozdemi <buozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 13:20:25 by buozdemi          #+#    #+#             */
/*   Updated: 2023/04/26 17:59:08 by buozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP
#include <iostream>

template <typename T>
void	swap(T &x, T &y)
{
	T temp;
	temp = x;
	x = y;
	y = temp;
}

template <typename T>
T	min(T const &x, T const &y)
{
	return (x < y ? x : y);
}

template <typename T>
T 	max(T const &x, T const &y)
{
	return (x > y ? x : y);
}

#endif