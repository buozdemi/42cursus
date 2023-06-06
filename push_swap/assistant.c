/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assistant.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozdemi <buozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 16:24:25 by buozdemi          #+#    #+#             */
/*   Updated: 2022/05/13 16:30:36 by buozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

size_t	ft_strlenline(char **s)
{
	int	i;

	i = 0;
	while (s[i] != NULL)
	{
		i++;
	}
	return (i);
}

int	ft_whichdigit(int c)
{
	if ((c >= 48 && c <= 57) || c == '-' || c == '+')
		return (1);
	if (c == ' ')
		return (2);
	return (0);
}

void	contiguous(t_allnum *allnum)
{
	ft_printf("Error\nThe numbers were sent contiguous.");
	free(allnum->a);
	free(allnum);
	exit(1);
}

void	rescontrol(long res, t_allnum *allnum)
{
	if (res > 2147483647)
	{
		ft_printf("Error\nIt was entered that a larger value than max integer.");
		free(allnum->a);
		free(allnum);
		exit(1);
	}
	if (res < -2147483648)
	{
		ft_printf("Error\nIt was entered that a less value than min integer.");
		free(allnum->a);
		free(allnum);
		exit(1);
	}
}

int	ft_atoi(const char *str, t_allnum *allnum)
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
		rescontrol(res, allnum);
		c++;
	}
	if (str[c] == '-' || str[c] == '+')
		contiguous(allnum);
	return (res);
}
