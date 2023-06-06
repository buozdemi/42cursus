/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_export.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozdemi <buozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:54:28 by aoner             #+#    #+#             */
/*   Updated: 2022/11/17 20:46:43 by buozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minish.h"

void	add_export(char *str, int flag)
{
	int		i;
	char	**exp;
	char	**new_exp;
	char	*total;

	i = 0;
	exp = g_ms.expcopy;
	new_exp = ft_calloc(sizeof(char **), export_len() + 2);
	while (exp[i])
	{
		new_exp[i] = ft_strdup(exp[i]);
		i++;
	}
	if (flag == 0)
	{
		total = make_export_fit(str);
		new_exp[i] = ft_strjoin("declare -x ", total);
		free(total);
	}
	else
		new_exp[i] = ft_strjoin("declare -x ", str);
	free_array(g_ms.expcopy);
	g_ms.expcopy = NULL;
	g_ms.expcopy = new_exp;
}
