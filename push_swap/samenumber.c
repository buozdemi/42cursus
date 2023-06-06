/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   samenumber.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozdemi <buozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 16:55:34 by buozdemi          #+#    #+#             */
/*   Updated: 2022/05/14 18:10:11 by buozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	samenumber(int a, t_allnum *allnum)
{
	size_t	b;

	b = allnum->m;
	if (allnum->thebiggestnumber < a)
		allnum->thebiggestnumber = a;
	while (b != allnum->intnumbersa)
	{
		if (allnum->a[b] == a)
		{
			ft_printf("Error\nStack-A has the same digit more than once.");
			free(allnum->a);
			free(allnum);
			exit(0);
		}
		b++;
	}
}

void	secondpartfree(t_allnum *allnum)
{
	free(allnum->b);
	free(allnum->a);
	free(allnum);
	exit(1);
}

void	afterbiggestnum(t_allnum *allnum)
{
	size_t	i;
	int		thebignum;

	i = 0;
	thebignum = 0;
	while (i != allnum->intnumbersa)
	{
		if (thebignum <= allnum->a[i])
			thebignum = allnum->a[i];
		i++;
	}
	allnum->afterbiggestnum = thebignum;
}
