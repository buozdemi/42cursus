/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozdemi <buozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 16:28:11 by buozdemi          #+#    #+#             */
/*   Updated: 2022/08/10 14:48:05 by buozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	action(int sig)
{
	static char	c = 0;
	static int	m = 0;

	c <<= 1;
	if (sig == SIGUSR1)
	{
		c |= 1;
	}
	m++;
	if (m == 8)
	{
		write(1, &c, 1);
		c = 0;
		m = 0;
	}
}

int	main(void)
{
	ft_printf("Server PID: %d\n", getpid());
	signal(SIGUSR1, action);
	signal(SIGUSR2, action);
	while (1)
	{
		pause();
	}
}
