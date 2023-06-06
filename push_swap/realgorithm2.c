/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realgorithm2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozdemi <buozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 14:24:54 by buozdemi          #+#    #+#             */
/*   Updated: 2022/05/14 17:58:49 by buozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	smallgorithm2(t_allnum *allnum)
{
	while (allnum->intnumbersb != 0)
	{
		thebiggestnum(allnum);
		if (allnum->thebiggestnumindexi > (allnum->intnumbersb / 2))
		{
			while (allnum->intnumbersb - 1 != allnum->thebiggestnumindexi)
			{
				rotateb(allnum);
				thebiggestnum(allnum);
			}
			pusha(allnum);
		}
		else
		{
			while (allnum->intnumbersb - 1 != allnum->thebiggestnumindexi)
			{
				reverserotateb(allnum);
				thebiggestnum(allnum);
			}
			pusha(allnum);
		}
	}
}

void	thebiggestnum(t_allnum *allnum)
{
	size_t	i;
	int		thebignum;

	i = 0;
	thebignum = 0;
	allnum->thebiggestnumindexi = 0;
	while (i != allnum->intnumbersb)
	{
		if (thebignum <= allnum->b[i])
		{
			allnum->thebiggestnumindexi = i;
			thebignum = allnum->b[i];
		}
		i++;
	}
}

void	minialgorithm2(t_allnum *allnum)
{
	if (allnum->intnumbersa == 2)
	{
		if (allnum->a[allnum->intnumbersa - 1] > \
		allnum->a[allnum->intnumbersa - 2])
			swapa(allnum);
	}
	while (allnum->intnumbersb != 0)
		pusha(allnum);
}

void	minialgorithm(t_allnum *allnum)
{
	toconvertindex(allnum);
	onlythreenum(allnum);
	while (allnum->intnumbersa > 2 && allnum->mark != 1)
	{
		if (allnum->malgminindex < (allnum->intnumbersa / 2))
		{
			while (allnum->a[allnum->intnumbersa - 1] != allnum->malgminnumber)
			{
				reverserotatea(allnum);
				malgminnumber(allnum);
			}
			pushb(allnum);
		}
		else
		{
			while (allnum->a[allnum->intnumbersa - 1] != allnum->malgminnumber)
			{
				rotatea(allnum);
				malgminnumber(allnum);
			}
			pushb(allnum);
		}
		malgminnumber(allnum);
	}
	minialgorithm2(allnum);
}

void	malgminnumber(t_allnum *allnum)
{
	size_t	i;

	i = 0;
	allnum->malgminindex = i;
	allnum->malgminnumber = allnum->a[i];
	while (i < allnum->intnumbersa)
	{
		if (allnum->malgminnumber > allnum->a[i])
		{
			allnum->malgminnumber = allnum->a[i];
			allnum->malgminindex = i;
		}
		i++;
	}
}
