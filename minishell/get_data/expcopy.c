/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expcopy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozdemi <buozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 10:08:20 by aoner             #+#    #+#             */
/*   Updated: 2022/11/16 14:55:59 by buozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minish.h"

void	expcopy(char **env)
{
	int		line;
	int		i;
	char	*total;

	i = 0;
	line = line_len(env);
	g_ms.expcopy = ft_calloc(sizeof(char **), line + 1);
	while (env[i])
	{
		total = make_export_fit(env[i]);
		g_ms.expcopy[i] = ft_strjoin("declare -x ", total);
		free(total);
		i++;
	}
}
