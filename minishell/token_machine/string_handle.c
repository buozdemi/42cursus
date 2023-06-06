/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_handle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozdemi <buozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 16:51:28 by aoner             #+#    #+#             */
/*   Updated: 2022/11/17 16:22:41 by buozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minish.h"

void	find_other_quote(char **str, char quote_type)
{
	(*str)++;
	while (**str)
	{
		if (**str == quote_type)
		{
			(*str)++;
			if (**str == ' ' || **str == '\t' || redir_check(*str))
				break ;
			else
				while (**str && **str != ' ' && **str != '\t' && \
				!redir_check(*str))
					(*str)++;
			return ;
		}
		(*str)++;
	}
}

void	without_quote_string(char **str)
{
	while (**str)
	{
		if (**str == ' ' || **str == '\t')
			break ;
		if (redir_check(*str))
			break ;
		(*str)++;
	}
}

void	string_handle(char **str)
{
	int		len;
	char	*head;
	char	*token_str;

	while (**str && (**str == ' ' || **str == '\t'))
		(*str)++;
	head = *str;
	if (**str && **str == '"')
		find_other_quote(str, '"');
	else if (**str && **str == '\'')
		find_other_quote(str, '\'');
	else
		without_quote_string(str);
	len = *str - head;
	if (len > 0)
	{
		token_str = ft_substr(head, 0, len);
		link_the_tokens(&g_ms.token, fill_the_token(token_str, STRING), 0);
	}
}
