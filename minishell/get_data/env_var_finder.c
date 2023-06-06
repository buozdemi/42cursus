/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_var_finder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozdemi <buozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 16:15:09 by aoner             #+#    #+#             */
/*   Updated: 2022/11/19 13:31:18 by buozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minish.h"

char	*after_equal_sign(char *str)
{
	while (*str != '=')
		str++;
	str++;
	return (ft_strdup(str));
}

char	*find_and_pull(char *str)
{
	size_t	len;
	char	**env;
	char	*new_str;

	env = g_ms.envcopy;
	new_str = ft_strjoin(str, "=");
	len = ft_strlen(new_str);
	while (*env)
	{
		if (!ft_strncmp(*env, new_str, len))
		{
			free(new_str);
			return (after_equal_sign(*env));
		}
		env++;
	}
	free(new_str);
	return (ft_calloc(sizeof(char *), 1));
}
