/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozdemi <buozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 19:03:00 by aoner             #+#    #+#             */
/*   Updated: 2022/11/16 14:47:09 by buozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minish.h"

void	free_process(void)
{
	t_process	*tmp;
	t_process	*process;

	process = g_ms.process;
	if (!process)
		return ;
	while (process)
	{
		free_array(process->execute);
		free_array(process->redirs);
		tmp = process;
		process = process->next;
		free(tmp);
	}
}
