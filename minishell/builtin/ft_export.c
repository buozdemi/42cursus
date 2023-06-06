/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozdemi <buozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 16:33:41 by aoner             #+#    #+#             */
/*   Updated: 2022/11/18 18:28:37 by buozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minish.h"

void	only_export(void)
{
	char	**exp;

	exp = g_ms.expcopy;
	while (*exp)
	{
		printf("%s\n", *exp);
		exp++;
	}
}

void	redefine_in_env(char *execute, int line)
{
	free(g_ms.envcopy[line]);
	g_ms.envcopy[line] = ft_strdup(execute);
}

void	redefine_in_exp(char *execute, int line)
{
	char	*total;

	total = make_export_fit(execute);
	free(g_ms.expcopy[line]);
	g_ms.expcopy[line] = ft_strjoin("declare -x ", total);
	free(total);
}

void	ft_export_part_one(char **execute, int *exp_line, int *env_line)
{
	*exp_line = already_exists_in_exp(*execute);
	*env_line = already_exists_in_env(*execute);
	if (*exp_line != -1 && *env_line == -1)
	{
		redefine_in_exp(*execute, *exp_line);
		add_env(*execute);
	}
	else if (*exp_line != -1 && *env_line != -1)
	{
		redefine_in_exp(*execute, *exp_line);
		redefine_in_env(*execute, *env_line);
	}
	else if (*exp_line == -1 && *env_line == -1)
	{
		add_export(*execute, 0);
		add_env(*execute);
	}
}

void	ft_export(char **execute)
{
	int		exp_line;
	int		env_line;

	errno = 0;
	if ((execute++) && !(*execute))
		only_export();
	while (*execute)
	{
		if (is_valid_export(*execute) == 1)
			ft_export_part_one(execute, &exp_line, &env_line);
		else if (is_valid_export(*execute) == 2 && \
		already_exists_in_exp(*execute) == -1)
			add_export(*execute, 1);
		if (is_valid_export(*execute) == 0 || is_valid_export(*execute) == -2)
		{
			wrong_char_export(*execute);
			break ;
		}
		execute++;
	}
	split_paths();
	if (!is_parent())
		exit (EXIT_SUCCESS);
}
