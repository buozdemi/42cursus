/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_line_count_ctrl.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozdemi <buozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 21:18:37 by aoner             #+#    #+#             */
/*   Updated: 2022/12/24 15:04:15 by buozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	map_linecount_ctrl(t_data *data)
{
	char	*nline;
	int		count;

	nline = get_next_line(data->fd);
	if (nline == NULL)
	{	
		printf("Error\nThere are only NULL characters inside the map!");
		free(nline);
		free(data);
		close(data->fd);
		exit(1);
	}
	count = 1;
	while (nline != NULL)
	{
		free(nline);
		nline = get_next_line(data->fd);
		count++;
	}
	data->tot_line_count = count;
	return (count);
}
