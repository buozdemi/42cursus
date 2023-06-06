/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozdemi <buozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 14:29:00 by buozdemi          #+#    #+#             */
/*   Updated: 2023/04/26 18:23:55 by buozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T>
void	iter(T *array, int len, void (*func)(const T &))
{
	for (int i = 0; i < len; i++)
	{
		func(array[i]);
	}
}

template <typename T>
void	print_i(const T &val)
{
	std::cout << val << " ";
}

#endif