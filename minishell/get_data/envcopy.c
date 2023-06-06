/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envcopy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozdemi <buozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 15:55:10 by aoner             #+#    #+#             */
/*   Updated: 2022/11/16 14:50:24 by buozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minish.h"

size_t	line_len(char **s)
{
	int	i;

	i = 0;
	while (s[i] != NULL)
		i++;
	return (i);
}

/* env'i structta tuttuğum envcopy'nin içine yazdırdım. */
void	envcopy(char **env)
{
	int	line;
	int	i;

	i = 0;
	line = line_len(env);
	g_ms.envcopy = ft_calloc(sizeof(char **), line + 1);
	while (env[i])
	{
		g_ms.envcopy[i] = ft_strdup(env[i]);
		i++;
	}
}
