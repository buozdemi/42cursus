/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirs_classify.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozdemi <buozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 10:23:01 by aoner             #+#    #+#             */
/*   Updated: 2022/11/16 15:43:06 by buozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minish.h"

void	redir_output_type(t_process *process)
{
	int		i;
	char	**redirs;

	i = 0;
	redirs = process->redirs;
	while (redirs[i])
	{
		if (redir_check(redirs[i]) == OVER_WRITE)
			output_type_handle(redirs[i + 1], 1);
		else if (redir_check(redirs[i]) == APPEND_BELOW)
			output_type_handle(redirs[i + 1], 0);
		i += 2;
	}
}

void	redir_input_type(t_process *process)
{
	int		i;
	char	**redirs;

	i = 0;
	redirs = process->redirs;
	while (redirs[i])
	{
		if (redir_check(redirs[i]) == RED_INPUT)
			input_type_handle(redirs[i + 1]);
		else if (redir_check(redirs[i]) == HERE_DOC)
			dup2(process->heredoc_fd[0], 0);
		i += 2;
	}
}
