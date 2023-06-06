/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozdemi <buozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 15:04:33 by buozdemi          #+#    #+#             */
/*   Updated: 2022/09/02 12:01:29 by buozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

int	onlynum(char **argv)
{
	int	i;
	int	m;

	m = 1;
	while (argv[m])
	{
		i = 0;
		while (argv[m][i])
		{
			if (i == 0 && (argv[m][i] == '-' || argv[m][i] == '+'))
				i++;
			if (argv[m][i] < 48 || argv[m][i] > 57)
				return (1);
			i++;
		}
		m++;
	}
	return (0);
}

int	argvcontrol(int argc, char **argv)
{
	if (argc != 5 && argc != 6)
	{
		printf("Error\nNot enough arguments.\n");
		return (1);
	}
	if (onlynum(argv))
	{
		printf("Error\nArguments are not numbers.\n");
		return (1);
	}
	if (ft_atoi(argv[1]) > 250 || ft_atoi(argv[1]) < 1 || \
	ft_atoi(argv[2]) < 0 || ft_atoi(argv[3]) < 0 || ft_atoi(argv[4]) < 0)
	{
		printf("Error\nYou cannot enter these arguments.\n");
		return (1);
	}
	if (argv[5])
	{
		if (ft_atoi(argv[5]) <= 0)
		{
			printf("Error\nTarget number of meals is wrong.\n");
			return (1);
		}
	}
	return (0);
}
