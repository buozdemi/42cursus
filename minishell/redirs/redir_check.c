/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozdemi <buozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 16:31:38 by aoner             #+#    #+#             */
/*   Updated: 2022/11/16 15:22:05 by buozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minish.h"

int	redir_check(char *str)
{
	if (!str)
		return (0);
	if (str[0] == '|')
		return (PIPE);
	if (str[0] == '>' && str[1] == '>')
		return (APPEND_BELOW);
	if (str[0] == '>')
		return (OVER_WRITE);
	if (str[0] == '<' && str[1] == '<')
		return (HERE_DOC);
	if (str[0] == '<')
		return (RED_INPUT);
	return (0);
}
