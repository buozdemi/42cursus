/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argconv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozdemi <buozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 18:52:32 by buozdemi          #+#    #+#             */
/*   Updated: 2022/05/11 23:23:51 by buozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	stringstate(char **argv, t_allnum *allnum, int i, int m)
{
	if (!(argv[i][m + 1] >= 48 && argv[i][m + 1] <= 57))
	{
		ft_printf("Error\nNo number is entered after the symbol.\n");
		free(allnum->allchar);
		free(allnum);
		exit(1);
	}
}

void	stringstate2(t_allnum *allnum)
{
	if (allnum->emptystring != 1)
	{
		ft_printf("Error\nThere is no number in the string.\n");
		free(allnum->allchar);
		free(allnum);
		exit(1);
	}
}

int	intnumberfunc(char **argv, t_allnum *allnum)
{
	int		i;
	int		m;
	int		ii;

	i = 1;
	ii = 0;
	while (argv[i] != NULL)
	{
		m = 0;
		while (argv[i][m] != '\0')
		{
			if (argv[i][m] >= 48 && argv[i][m] <= 57)
				allnum->emptystring = 1;
			if (argv[i][m] == '-' || argv[i][m] == '+')
				stringstate(argv, allnum, i, m);
			m++;
		}
		stringstate2(allnum);
		allnum->emptystring = 0;
		i++;
	}
	writehowmchar(argv, allnum);
	intnumberfunc2(allnum);
	return (allnum->intnumbersa);
}

void	intnumberfunc2(t_allnum *allnum)
{
	int		i;
	char	**turnsplit;

	i = 0;
	turnsplit = ft_split(allnum->allchar, ' ');
	if (turnsplit == NULL)
	{
		ft_printf("Error\n");
		free(allnum->allchar);
		free(allnum);
		exit(1);
	}
	allnum->intnumbersa = ft_strlenline(turnsplit);
	free(allnum->allchar);
	while (turnsplit[i])
		free(turnsplit[i++]);
	free(turnsplit);
}

int	argconv(char **argv, t_allnum *allnum)
{
	int		i;

	i = 1;
	allnum->m = allnum->intnumbersa;
	if (allnum->intnumbersa == 0)
		return (0);
	while (argv[i] != NULL)
	{
		if (digitordigits(argv, i) == 1)
			convonlydigit(argv[i++], allnum);
		else if (digitordigits(argv, i) == 2)
			spacedigit(argv[i++], allnum);
	}
	return (1);
}
