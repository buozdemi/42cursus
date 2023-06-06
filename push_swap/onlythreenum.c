/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   onlythreenum.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozdemi <buozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 20:35:46 by buozdemi          #+#    #+#             */
/*   Updated: 2022/05/10 12:12:01 by buozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	onlythreenum(t_allnum *allnum)
{
	malgminnumber(allnum);
	if (allnum->intnumbersb == 0 && allnum->intnumbersa == 3)
	{
		while (ordinalnum(allnum) != 0)
		{
			ifminindex2(allnum);
			ifminindex1(allnum);
			ifminindex0(allnum);
		}
		allnum->mark = 1;
	}
}

void	ifminindex2(t_allnum *allnum)
{
	if (allnum->malgminindex == 2)
	{
		if (allnum->a[1] > allnum->a[0])
		{
			rotatea(allnum);
			swapa(allnum);
			reverserotatea(allnum);
		}
	}
}

void	ifminindex1(t_allnum *allnum)
{
	if (allnum->malgminindex == 1)
	{
		if (allnum->a[2] > allnum->a[0])
		{
			rotatea(allnum);
			malgminnumber(allnum);
		}
		else
			swapa(allnum);
	}
}

void	ifminindex0(t_allnum *allnum)
{
	if (allnum->malgminindex == 0)
	{
		if (allnum->a[2] > allnum->a[1])
		{
			swapa(allnum);
			reverserotatea(allnum);
		}
		else
			reverserotatea(allnum);
	}
}
