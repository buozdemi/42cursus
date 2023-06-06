/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_export_fit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozdemi <buozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:45:11 by aoner             #+#    #+#             */
/*   Updated: 2022/11/17 17:07:09 by buozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minish.h"

char	*add_marked(char *equalafterequal)
{
	int		i;
	int		c;
	char	*marked;

	c = 0;
	i = 1;
	marked = ft_calloc(sizeof(char), ft_strlen(equalafterequal) + 2 + 1);
	marked[c++] = '=';
	marked[c++] = '\"';
	while (equalafterequal[i])
		marked[c++] = equalafterequal[i++];
	marked[c] = '\"';
	return (marked);
}

char	*untilequal_i(char *env)
{
	char	*new;
	int		c;
	int		i;

	i = 0;
	c = 0;
	new = ft_calloc(sizeof(char), equal_len(env) + 2);
	while (env[i])
	{
		if (env[i] == '=')
			break ;
		new[c] = env[i];
		i++;
		c++;
	}
	new[c] = '\0';
	return (new);
}

char	*make_export_fit(char *env_line)
{
	char	*equalafterequal;
	char	*untilequal;
	char	*marked_afterequal;
	char	*unified;

	equalafterequal = ft_strnstr(env_line, "=", ft_strlen(env_line));
	untilequal = untilequal_i(env_line);
	marked_afterequal = add_marked(equalafterequal);
	unified = ft_strjoin(untilequal, marked_afterequal);
	free(marked_afterequal);
	free(untilequal);
	return (unified);
}
