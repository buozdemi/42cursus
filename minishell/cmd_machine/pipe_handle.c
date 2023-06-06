/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_handle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozdemi <buozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:53:09 by aoner             #+#    #+#             */
/*   Updated: 2022/11/16 15:58:58 by buozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minish.h"

void	pipe_for_all_others(t_process *process)
{
	if (process->back == NULL)
		dup2(process->fd[1], 1);
	else if (process->next == NULL)
		dup2(process->back->fd[0], 0);
	else
	{
		dup2(process->back->fd[0], 0);
		dup2(process->fd[1], 1);
	}
}

void	pipe_for_heredoc(t_process *process)
{
	dup2(process->heredoc_fd[0], 0);
	if (process->next != NULL)
		dup2(process->fd[1], 1);
}

void	pipe_handle(t_process *process)
{
	if (g_ms.parscount > 1)
	{
		if (is_there_heredoc(process))
			pipe_for_heredoc(process);
		else
			pipe_for_all_others(process);
	}
	redir_input_type(process);
	redir_output_type(process);
	close_all_fd();
}
