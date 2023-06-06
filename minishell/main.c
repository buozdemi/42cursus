/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozdemi <buozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 14:59:48 by aoner             #+#    #+#             */
/*   Updated: 2022/11/19 12:46:45 by buozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minish.h"

t_minish	g_ms;

void	ctrl_c(int sig)
{
	(void)sig;
	g_ms.ignore = 1;
	ioctl(STDIN_FILENO, TIOCSTI, "\n");
	write(1, "\033[A", 3);
}

void	ctrl_d(char *input)
{
	if (!input)
	{
		printf("exit\n");
		exit(errno);
	}
}

int	main(int argc, char **argv, char **env)
{
	(void)argc;
	(void)argv;
	errno = 0;
	g_ms.split_path = NULL;
	g_ms.parent_pid = getpid();
	envcopy(env);
	expcopy(env);
	split_paths();
	readline_cycle();
}
