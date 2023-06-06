/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozdemi <buozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 16:31:38 by aoner             #+#    #+#             */
/*   Updated: 2022/11/16 15:49:44 by buozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minish.h"

void	remove_env(char **input)
{
	int		i;
	int		j;
	char	**new_env;
	char	*data;

	i = 0;
	j = 0;
	data = ft_strjoin(*input, "=");
	new_env = ft_calloc(sizeof(char *), env_len() + 1);
	while (g_ms.envcopy[i])
	{
		if (ft_strncmp(g_ms.envcopy[i], data, ft_strlen(data)))
		{
			new_env[j] = ft_strdup(g_ms.envcopy[i]);
			j++;
		}
		i++;
	}
	new_env[j] = 0;
	free(data);
	free_array(g_ms.envcopy);
	g_ms.envcopy = new_env;
}

void	remove_export(char **input)
{
	int		i;
	int		j;
	char	**new_exp;
	int		i_line;

	i = 0;
	j = 0;
	i_line = already_exists_in_exp(*input);
	new_exp = ft_calloc(sizeof(char *), export_len() + 1);
	while (g_ms.expcopy[i])
	{
		if (i != i_line)
		{
			new_exp[j] = ft_strdup(g_ms.expcopy[i]);
			j++;
		}
		i++;
	}
	new_exp[j] = 0;
	free_array(g_ms.expcopy);
	g_ms.expcopy = new_exp;
}

void	ft_unset(char **input)
{
	errno = 0;
	input++;
	while (*input && is_valid_unset(*input) > 0)
	{
		remove_env(input);
		remove_export(input);
		input++;
	}
	split_paths();
	if (!is_parent())
		exit (EXIT_SUCCESS);
}
