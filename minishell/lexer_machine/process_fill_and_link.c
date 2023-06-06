/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_fill_and_link.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozdemi <buozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 20:13:56 by aoner             #+#    #+#             */
/*   Updated: 2022/11/16 15:29:52 by buozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minish.h"

void	link_the_process(t_process **process, t_process *last_process)
{
	t_process	*each_process;

	each_process = *process;
	if (!(each_process))
		*process = last_process;
	else
	{
		while (each_process->next)
			each_process = each_process->next;
		each_process->next = last_process;
		last_process->back = each_process;
	}
}

t_process	*fill_the_process(void)
{
	t_process	*process;

	process = ft_calloc(sizeof(t_process), 1);
	pipe(process->fd);
	process->pid = -1;
	process->execute = ft_calloc(sizeof(char *), 1);
	process->redirs = ft_calloc(sizeof(char *), 1);
	process->back = NULL;
	process->next = NULL;
	return (process);
}
