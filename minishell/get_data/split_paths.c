/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_paths.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozdemi <buozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 17:30:15 by aoner             #+#    #+#             */
/*   Updated: 2022/11/16 15:05:18 by buozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minish.h"

void	split_paths(void)
{
	char	*full_path;

	if (g_ms.split_path)
		free_array(g_ms.split_path);
	full_path = find_and_pull("PATH");
	if (!(*full_path))
		g_ms.split_path = NULL;
	else
		g_ms.split_path = ft_split(full_path, ':');
	free(full_path);
}
