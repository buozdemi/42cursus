/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gamerule.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozdemi <buozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 18:10:28 by buozdemi          #+#    #+#             */
/*   Updated: 2022/04/29 14:58:08 by buozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	swapa(t_allnum *allnum)
{
	int	p;

	if (2 <= allnum->intnumbersa)
	{
		p = allnum->a[allnum->intnumbersa - 1];
		allnum->a[allnum->intnumbersa - 1] = allnum->a[allnum->intnumbersa - 2];
		allnum->a[allnum->intnumbersa - 2] = p;
		if (allnum->info != 1)
		{
			ft_printf("sa\n");
			allnum->info = 0;
		}
	}
}

void	swapb(t_allnum *allnum)
{
	int	t;

	if (2 <= allnum->intnumbersb)
	{
		t = allnum->b[allnum->intnumbersb - 1];
		allnum->b[allnum->intnumbersb - 1] = allnum->b[allnum->intnumbersb - 2];
		allnum->b[allnum->intnumbersb - 2] = t;
		if (allnum->info != 1)
		{
			ft_printf("sb\n");
			allnum->info = 0;
		}
	}
}

void	pusha(t_allnum *allnum)
{
	int	p;

	if (allnum->intnumbersb != 0)
	{
		p = allnum->b[allnum->intnumbersb - 1];
		--allnum->intnumbersb;
		allnum->a[allnum->intnumbersa] = p;
		++allnum->intnumbersa;
		ft_printf("pa\n");
	}
}

void	pushb(t_allnum *allnum)
{
	int	p;
	int	m;

	m = 0;
	if (allnum->intnumbersa != 0)
	{
		p = allnum->a[allnum->intnumbersa - 1];
		--allnum->intnumbersa;
		allnum->b[allnum->intnumbersb] = p;
		++allnum->intnumbersb;
		ft_printf("pb\n");
	}
}

void	sssw(t_allnum *allnum)
{
	allnum->info = 1;
	swapa(allnum);
	allnum->info = 1;
	swapb(allnum);
	ft_printf("ss\n");
}
