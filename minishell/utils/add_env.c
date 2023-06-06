/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozdemi <buozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:55:00 by aoner             #+#    #+#             */
/*   Updated: 2022/11/17 20:45:22 by buozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minish.h"

void	add_env(char *str)
{
	int		i;
	char	**env;
	char	**new_env;

	i = 0;
	env = g_ms.envcopy;
	new_env = ft_calloc(sizeof(char **), env_len() + 2);
	while (env[i])
	{
		new_env[i] = ft_strdup(env[i]);
		i++;
	}
	new_env[i] = ft_strdup(str);
	free_array(g_ms.envcopy);
	g_ms.envcopy = NULL;
	g_ms.envcopy = new_env;
}
