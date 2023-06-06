/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_fill_and_link.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozdemi <buozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 20:13:09 by aoner             #+#    #+#             */
/*   Updated: 2022/11/17 16:16:47 by buozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minish.h"

int	link_the_tokens(t_token	**token, t_token *last_token, int plus)
{
	t_token	*each_token;

	each_token = *token;
	if (!each_token)
		*token = last_token;
	else
	{
		while (each_token->next)
			each_token = each_token->next;
		each_token->next = last_token;
		last_token->back = each_token;
	}
	return (plus);
}

t_token	*fill_the_token(char *str, enum e_ttype token_type)
{
	t_token	*token;

	token = (t_token *)ft_calloc(sizeof(t_token), 1);
	token->type = token_type;
	token->str = str;
	token->back = NULL;
	token->next = NULL;
	return (token);
}
