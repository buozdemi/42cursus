/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozdemi <buozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 10:15:50 by aoner             #+#    #+#             */
/*   Updated: 2022/11/19 14:07:10 by buozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minish.h"

void	wait_cmd(void)
{
	t_process	*process;

	process = g_ms.process;
	close_all_fd();
	while (process)
	{
		if (process->pid != -1)
		{
			waitpid(process->pid, &errno, 0);
			errno = WEXITSTATUS(errno);
		}
		process = process->next;
	}
}

void	start_cmd(void)
{
	t_process	*process;

	process = g_ms.process;
	if (!process)
		return ;
	fill_the_heredocs();
	if (g_ms.ignore)
		return (close_all_fd());
	if (builtin_check(process->execute[0]) && g_ms.parscount == 1)
	{
		get_builtin(process);
		process = process->next;
	}
	while (process)
	{
		run_cmd(process);
		process = process->next;
	}
	wait_cmd();
}
