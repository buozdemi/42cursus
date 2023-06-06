/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozdemi <buozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 12:10:11 by buozdemi          #+#    #+#             */
/*   Updated: 2022/06/29 15:45:46 by buozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int		c;
	int		s;
	long	res;

	c = 0;
	s = 1;
	res = 0;
	while (str[c] == ' ' || (str[c] >= 9 && str[c] <= 13))
		c++;
	if (str[c] == '-' || str[c] == '+')
	{
		if (str[c] == '-')
			s = -1;
		c++;
	}
	while (str[c] >= '0' && str[c] <= '9')
	{
		res = (res * 10) + (str[c] - '0') * s;
		if (res > 2147483647)
			return (-1);
		else if (res < -2147483648)
			return (0);
		c++;
	}
	return (res);
}
