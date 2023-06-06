/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gamerule2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozdemi <buozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 13:59:18 by buozdemi          #+#    #+#             */
/*   Updated: 2022/05/11 15:27:22 by buozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	rotatea(t_allnum *allnum)
{
	size_t	i;
	int		m;
	int		last;

	i = 0;
	last = allnum->a[allnum->intnumbersa - 1];
	if (allnum->intnumbersa >= 2)
	{
		while (i + 1 != allnum->intnumbersa)
		{
			allnum->a[allnum->intnumbersa - 1 - i] = \
			allnum->a[allnum->intnumbersa - 2 - i];
			i++;
		}
		allnum->a[0] = last;
		m = 0;
		if (allnum->info != 1)
		{
			ft_printf("ra\n");
			allnum->info = 0;
		}	
	}
}

void	rotateb(t_allnum *allnum)
{
	int		last;
	size_t	i;
	int		m;

	m = 0;
	i = 0;
	last = allnum->b[allnum->intnumbersb - 1];
	if (allnum->intnumbersb >= 2)
	{
		while (i + 1 != allnum->intnumbersb)
		{
			allnum->b[allnum->intnumbersb - 1 - i] = \
			allnum->b[allnum->intnumbersb - 2 - i];
			i++;
		}
		allnum->b[0] = last;
		if (allnum->info != 1)
		{
			ft_printf("rb\n");
			allnum->info = 0;
		}
	}
}

void	reverserotatea(t_allnum *allnum)
{
	int		first;
	size_t	i;

	i = 0;
	first = allnum->a[0];
	if (2 <= allnum->intnumbersa)
	{
		while (i != allnum->intnumbersa - 1)
		{
			allnum->a[i] = allnum->a[i + 1];
			i++;
		}
		allnum->a[allnum->intnumbersa - 1] = first;
		if (allnum->info != 1)
		{
			ft_printf("rra\n");
			allnum->info = 0;
		}
	}
}

void	reverserotateb(t_allnum *allnum)
{
	int		first;
	size_t	i;

	i = 0;
	first = allnum->b[0];
	if (2 <= allnum->intnumbersb)
	{
		while (i != allnum->intnumbersb - 1)
		{
			allnum->b[i] = allnum->b[i + 1];
			i++;
		}
		allnum->b[allnum->intnumbersb - 1] = first;
		if (allnum->info != 1)
		{
			ft_printf("rrb\n");
			allnum->info = 0;
		}
	}
}

void	rrab(t_allnum *allnum)
{
	allnum->info = 1;
	rotatea(allnum);
	allnum->info = 1;
	rotateb(allnum);
	ft_printf("rr\n");
}
