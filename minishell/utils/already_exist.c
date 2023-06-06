/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   already_exist.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozdemi <buozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:51:42 by aoner             #+#    #+#             */
/*   Updated: 2022/11/17 17:10:58 by buozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minish.h"

int	already_exists_in_exp(char *str)
{
	int		i;
	int		j;
	char	**exp;
	char	*exp2;

	i = 0;
	exp = g_ms.expcopy;
	while (exp[i])
	{
		j = 0;
		exp2 = (exp[i] + 11);
		while (exp2[j] && str[j])
		{
			if (exp2[j] != str[j])
				break ;
			if (exp2[j] == '=' && str[j] == '=')
				return (i);
			j++;
			if ((exp2[j] == '=' && !str[j]) || (!exp2[j] && \
			str[j] == '=') || (!exp2[j] && !str[j]))
				return (i);
		}
		i++;
	}
	return (-1);
}

int	already_exists_in_env(char *str)
{
	int		i;
	char	**env;
	int		j;

	i = 0;
	env = g_ms.envcopy;
	while (env[i])
	{
		j = 0;
		while (env[i][j] && str[j])
		{
			if (str[j] == '=' && env[i][j] == '=')
				return (i);
			if (str[j] != env[i][j])
				break ;
			j++;
		}
		i++;
	}
	return (-1);
}
