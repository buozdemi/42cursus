/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozdemi <buozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 12:44:42 by buozdemi          #+#    #+#             */
/*   Updated: 2022/08/10 15:02:15 by buozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	action(int pid, char str)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if ((str >> i) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i--;
		usleep(100);
	}
}

int	main(int argc, char **argv)
{
	int		pid;
	int		j;

	j = 0;
	pid = 0;
	if (argc != 3)
	{
		ft_printf("Not enough arguments.\n");
		return (0);
	}
	pid = ft_atoi(argv[1]);
	if (pid <= 0)
	{
		ft_printf("PID cannot be negative or zero.\n");
		return (0);
	}
	while (argv[2][j])
	{
		action(pid, argv[2][j++]);
	}
	action(pid, '\n');
}
