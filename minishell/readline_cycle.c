/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline_cycle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozdemi <buozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 16:23:23 by aoner             #+#    #+#             */
/*   Updated: 2022/11/19 12:56:22 by buozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minish.h"

void	init_readline(char *str)
{
	g_ms.token = NULL;
	g_ms.process = NULL;
	g_ms.parscount = 0;
	token_classify(str);
	if (!lexer())
		return ;
	start_cmd();
	free_process();
}

void	readline_cycle(void)
{
	char	*str;
	char	*promptline;
	char	*proline;

	proline = ft_strdup("@007-> ");
	promptline = ft_strjoin(getenv("USER"), proline);
	while (1)
	{
		g_ms.ignore = 0;
		signal(SIGINT, &ctrl_c);
		signal(SIGQUIT, SIG_IGN);
		str = readline(promptline);
		ctrl_d(str);
		if (g_ms.ignore)
		{
			free(str);
			str = malloc(1);
		}
		if (*str)
		{
			init_readline(str);
			add_history(str);
		}
		free(str);
	}
}
