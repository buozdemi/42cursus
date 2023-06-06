/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   howmchar.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozdemi <buozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 19:11:13 by buozdemi          #+#    #+#             */
/*   Updated: 2022/05/11 22:36:24 by buozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	wrongchar(char **argv, int i, int m, t_allnum *allnum)
{
	if (ft_whichdigit(argv[i][m]) == 0)
	{	
		ft_printf("Error\nNon-digit characters available.");
		free(allnum);
		exit(1);
	}
}

void	howmchar(char **argv, t_allnum *allnum)
{
	int	m;
	int	i;

	i = 1;
	while (argv[i] != NULL)
	{
		m = 0;
		while (argv[i][m] != '\0')
		{
			while (argv[i][m] && argv[i][m] == ' ')
				m++;
			while (argv[i][m] && argv[i][m] != ' ')
			{
				wrongchar(argv, i, m, allnum);
				m++;
				++allnum->charcount;
			}
			while (argv[i][m] && argv[i][m] == ' ')
				m++;
			if (argv[i][m] != '\0')
				++allnum->charcount;
		}
		if (argv[i++ + 1] != NULL)
			++allnum->charcount;
	}
}

void	writehowmchar(char **argv, t_allnum *allnum)
{
	int	m;
	int	i;
	int	ii;

	i = 1;
	ii = 0;
	while (argv[i] != NULL)
	{
		m = 0;
		while (argv[i][m] != '\0')
		{
			while (argv[i][m] && argv[i][m] == ' ')
				m++;
			while (argv[i][m] && argv[i][m] != ' ')
				allnum->allchar[ii++] = argv[i][m++];
			while (argv[i][m] && argv[i][m] == ' ')
				m++;
			if (argv[i][m] != '\0')
				allnum->allchar[ii++] = ' ';
		}
		if (argv[i++ + 1] != NULL)
			allnum->allchar[ii++] = ' ';
	}
	allnum->allchar[ii] = '\0';
}
