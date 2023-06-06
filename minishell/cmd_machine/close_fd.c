/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_fd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozdemi <buozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 13:08:59 by aoner             #+#    #+#             */
/*   Updated: 2022/11/16 15:42:09 by buozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minish.h"

int	is_there_heredoc(t_process *process)
{
	int	i;

	i = 0;
	while (process->redirs[i])
	{
		if (redir_check(process->redirs[i]) == HERE_DOC)
			return (1);
		i++;
	}
	return (0);
}

void	close_heredoc_fd(t_process *process)
{
	if (process->heredoc_fd[0] > 2)
		close(process->heredoc_fd[0]);
}

void	close_all_fd(void)
{
	t_process	*process;

	process = g_ms.process;
	while (process)
	{
		if (is_there_heredoc(process))
			close_heredoc_fd(process);
		if (process->fd[0] > 2)
			close(process->fd[0]);
		if (process->fd[1] > 2)
			close(process->fd[1]);
		process = process->next;
	}
}
