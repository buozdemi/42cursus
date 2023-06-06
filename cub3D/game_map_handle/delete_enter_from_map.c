/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_enter_from_map.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <aoner@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 13:53:17 by aoner             #+#    #+#             */
/*   Updated: 2023/01/03 13:54:26 by aoner            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	delete_enter_from_map(t_data *data)
{
	int	i;
	int	m;

	i = data->game_start_line;
	while (data->collect_lines[i])
	{
		m = 0;
		while (data->collect_lines[i][m])
		{
			if (data->collect_lines[i][m] == '\n' && \
			data->collect_lines[i][m + 1] == '\0')
			{
				data->collect_lines[i][m] = '\0';
				break ;
			}	
			m++;
		}
		i++;
	}
}
