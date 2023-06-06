/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maintheme.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozdemi <buozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 16:03:35 by buozdemi          #+#    #+#             */
/*   Updated: 2022/05/13 16:12:35 by buozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ordinalnum(t_allnum *allnum)
{
	size_t	i;
	int		j;

	j = 0;
	i = 0;
	while (i + 1 <= allnum->intnumbersa - 1)
	{
		if (allnum->a[i] > allnum->a[i + 1])
			i++;
		else
		{
			j = 1;
			break ;
		}
	}
	if (j == 0)
		return (0);
	return (1);
}

int	maintheme(t_allnum *allnum, char **argv)
{
	howmchar(argv, allnum);
	allnum->allchar = ft_calloc(sizeof(char), allnum->charcount + 1);
	if (!allnum->allchar)
	{
		free(allnum);
		exit(1);
	}
	allnum->a = ft_calloc(sizeof(int), intnumberfunc(argv, allnum));
	if (!(allnum->a))
	{
		free(allnum);
		exit(1);
	}
	if (argconv(argv, allnum) == 0 || ordinalnum(allnum) == 0)
		return (0);
	allnum->b = ft_calloc(sizeof(int), allnum->intnumbersa);
	if (!(allnum->b))
	{
		free(allnum->a);
		free(allnum);
		exit(1);
	}
	return (1);
}
