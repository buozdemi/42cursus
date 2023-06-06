/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_handle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozdemi <buozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 10:29:24 by aoner             #+#    #+#             */
/*   Updated: 2022/11/16 15:40:22 by buozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minish.h"

void	close_heredoc(int sig)
{
	(void)sig;
	g_ms.ignore = 1;
	ioctl(STDIN_FILENO, TIOCSTI, "\n");
}

void	heredoc(int *hdoc_fd, char *endline)
{
	char		*input;
	static int	start = 0;

	if (start)
	{
		start = 1;
		close(hdoc_fd[0]);
		close(hdoc_fd[1]);
	}
	if (pipe(hdoc_fd) < 0)
		return (perror("minish "));
	while (1)
	{
		signal(SIGINT, &close_heredoc);
		input = readline("> ");
		if (!input || ft_strcmp(input, endline) || g_ms.ignore)
		{
			free(input);
			break ;
		}
		write(hdoc_fd[1], input, ft_strlen(input));
		write(hdoc_fd[1], "\n", 1);
		free(input);
	}
	close(hdoc_fd[1]);
}

void	fill_the_heredocs(void)
{
	int			i;
	char		**redirs;
	t_process	*process;

	process = g_ms.process;
	while (process)
	{
		i = 0;
		redirs = process->redirs;
		while (redirs[i] && !(g_ms.ignore))
		{
			if (redir_check(redirs[i]) == HERE_DOC)
				heredoc(process->heredoc_fd, redirs[i + 1]);
			i += 2;
		}
		process = process->next;
	}
}
