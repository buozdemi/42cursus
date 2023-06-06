/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realgorithm.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozdemi <buozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 18:16:11 by buozdemi          #+#    #+#             */
/*   Updated: 2022/05/14 18:15:44 by buozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	thebiggestbit(int n)
{
	int	count;

	count = 0;
	while (n)
	{
		count++;
		n >>= 1;
	}
	return (count);
}

void	toconvertindex(t_allnum *allnum)
{
	int		i;
	size_t	m;
	size_t	num;

	allnum->ai = ft_calloc(sizeof(int), allnum->intnumbersa);
	if (!(allnum->ai))
		secondpartfree(allnum);
	num = 0;
	while (num < allnum->intnumbersa)
	{
		i = 0;
		m = 0;
		while (m < allnum->intnumbersa)
		{
			if (allnum->a[num] > allnum->a[m])
				i++;
			m++;
		}
		allnum->ai[num] = i;
		num++;
	}
	free(allnum->a);
	allnum->a = allnum->ai;
}

void	radixalgorithm(t_allnum *allnum)
{
	int	index;
	int	first;

	toconvertindex(allnum);
	afterbiggestnum(allnum);
	first = allnum->intnumbersa;
	index = 0;
	while (index != thebiggestbit(allnum->afterbiggestnum))
	{
		while (first != 0)
		{
			if (!((allnum->a[allnum->intnumbersa - 1] >> index) & 1))
				pushb(allnum);
			else
				rotatea(allnum);
			--first;
		}
		while (allnum->intnumbersb != 0)
			pusha(allnum);
		first = allnum->intnumbersa;
		index++;
	}
}

void	smallgorithm(t_allnum *allnum)
{
	int	first;
	int	i;

	i = 0;
	toconvertindex(allnum);
	first = allnum->intnumbersa;
	while (allnum->intnumbersa != 2)
	{
		while (i != first)
		{
			if (allnum->a[allnum->intnumbersa - 1] < arithmean(allnum))
				pushb(allnum);
			else
				rotatea(allnum);
			i++;
		}
		first = allnum->intnumbersa;
		i = 0;
	}
	if (allnum->intnumbersa == 2)
	{
		if (allnum->a[0] < allnum->a[1])
			swapa(allnum);
	}
	smallgorithm2(allnum);
}

int	arithmean(t_allnum *allnum)
{
	size_t	i;
	int		total;
	int		arith;

	total = 0;
	i = 0;
	while (i != allnum->intnumbersa)
	{
		total += allnum->a[i];
		i++;
	}
	arith = total / allnum->intnumbersa;
	return (arith);
}
