/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozdemi <buozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 19:20:49 by aoner             #+#    #+#             */
/*   Updated: 2022/11/19 16:32:10 by buozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minish.h"

int	wr_new(t_token **token)
{
	if ((*token)->type == PIPE)
	{
		*token = (*token)->next;
		if (*token == NULL)
		{
			free_token();
			free_process();
			token_err(0);
			return (1);
		}
	}
	return (0);
}

int	lexer(void)
{
	t_token		*token;
	t_process	*last_process;

	token = g_ms.token;
	while (token)
	{
		if (token->type == PIPE || token->back == NULL)
		{
			if (wr_new(&token))
				return (0);
			last_process = fill_the_process();
			link_the_process(&g_ms.process, last_process);
			g_ms.parscount++;
		}
		if (!token)
			break ;
		if (!fix_up_the_arguments(&token, last_process))
			return (0);
		if (token)
			token = token->next;
	}
	free_token();
	return (1);
}
