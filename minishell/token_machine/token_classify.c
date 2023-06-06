/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_classify.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozdemi <buozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 10:26:23 by aoner             #+#    #+#             */
/*   Updated: 2022/11/19 14:33:44 by buozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minish.h"

void	token_classify(char *str)
{
	while (*str)
	{
		if (redir_check(str) == PIPE)
			str += link_the_tokens(&g_ms.token, \
			fill_the_token(ft_strdup("|"), PIPE), 1);
		else if (redir_check(str) == APPEND_BELOW)
			str += link_the_tokens(&g_ms.token, \
			fill_the_token(ft_strdup(">>"), APPEND_BELOW), 2);
		else if (redir_check(str) == OVER_WRITE)
			str += link_the_tokens(&g_ms.token, \
			fill_the_token(ft_strdup(">"), OVER_WRITE), 1);
		else if (redir_check(str) == HERE_DOC)
			str += link_the_tokens(&g_ms.token, \
			fill_the_token(ft_strdup("<<"), HERE_DOC), 2);
		else if (redir_check(str) == RED_INPUT)
			str += link_the_tokens(&g_ms.token, \
			fill_the_token(ft_strdup("<"), RED_INPUT), 1);
		else
			string_handle(&str);
	}
}
