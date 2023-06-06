/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_builtin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozdemi <buozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 12:45:03 by aoner             #+#    #+#             */
/*   Updated: 2022/11/16 15:42:49 by buozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minish.h"

void	get_builtin(t_process *process)
{
	int	reading;
	int	writing;

	reading = dup(0);
	writing = dup(1);
	redir_input_type(process);
	redir_output_type(process);
	run_builtin(process->execute);
	dup2(reading, 0);
	dup2(writing, 1);
	close(reading);
	close(writing);
}
