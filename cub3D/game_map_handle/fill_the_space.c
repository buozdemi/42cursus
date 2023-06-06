/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_the_space.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <aoner@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 20:28:41 by aoner             #+#    #+#             */
/*   Updated: 2023/01/03 14:07:38 by aoner            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	change_space_to_wall(t_data *data)
{
	int	i;
	int	y;

	i = data->game_start_line;
	while (data->collect_lines[i] && i != data->game_last_line + 1)
	{
		y = 0;
		while (data->collect_lines[i][y])
		{
			if (is_space(data->collect_lines[i][y]))
				data->collect_lines[i][y] = '1';
			y++;
		}
		i++;
	}
}

void	column_counter(t_data *data)
{
	int	i;
	int	y;
	int	z;

	z = 0;
	i = data->game_start_line;
	data->game_line_count = data->game_last_line - data->game_start_line;
	data->column_length = ft_calloc(sizeof(int), data->game_line_count + 1);
	if (!data->column_length)
		malloc_error(data);
	while (data->collect_lines[i] && i != data->game_last_line + 1)
	{
		y = 0;
		while (data->collect_lines[i][y] != '\0')
			y++;
		if (data->collect_lines[i][y] == '\0')
		{
			data->column_length[z] = y;
			z++;
		}
		i++;
	}
}
