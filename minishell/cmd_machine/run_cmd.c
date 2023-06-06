/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <aoner@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 18:19:48 by aoner             #+#    #+#             */
/*   Updated: 2022/11/04 18:19:48 by aoner            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minish.h"

void	run_cmd(t_process *process)
{
	pid_t	pid;
	char	*path;

	pid = fork();
	if (pid == 0)
	{
		signal(SIGQUIT, SIG_DFL);
		signal(SIGINT, SIG_DFL);
		pipe_handle(process);
		run_builtin(process->execute);
		path = is_valid_cmd_path(process->execute[0]);
		execve(path, process->execute, g_ms.envcopy);
		command_err(process->execute[0]);
		exit(errno);
	}
	else
		process->pid = pid;
}
