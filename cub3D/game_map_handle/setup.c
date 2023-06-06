/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <aoner@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 20:53:57 by aoner             #+#    #+#             */
/*   Updated: 2023/01/04 11:27:52 by aoner            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	setupgame(t_map *map)
{
	map->move_speed = 0.03;
	map->rotate_speed = 0.032;
	map->w_sixtyfour = 64;
	map->h_sixtyfour = 64;
}

void	get_pos(t_data *data, t_map *map)
{
	int	x;
	int	y;

	x = 0;
	while (data->map[x])
	{
		y = 0;
		while (data->map[x][y])
		{
			if (data->map[x][y] == 'E' || data->map[x][y] == 'W' \
			|| data->map[x][y] == 'S' || data->map[x][y] == 'N')
			{
				map->px = x;
				map->py = y;
				map->orientation = data->map[x][y];
				return ;
			}
			y++;
		}
		x++;
	}
}

void	set_values(t_map *map)
{
	if (map->orientation == 'S')
	{
		map->dirx = 1;
		map->viewy = 0.66;
	}
	else if (map->orientation == 'N')
	{
		map->dirx = -1;
		map->viewy = -0.66;
	}
	else if (map->orientation == 'W')
	{
		map->diry = 1;
		map->viewx = -0.66;
	}
	else if (map->orientation == 'E')
	{
		map->diry = -1;
		map->viewx = 0.66;
	}
}

void	get_dist(t_map *map)
{
	if (map->side == 0)
		map->wall_dist = map->sidedist_x - map->deltadist_x;
	else
		map->wall_dist = map->sidedist_y - map->deltadist_y;
	map->line_height = (int)(WIN_HEIGHT / map->wall_dist);
	map->draw_start = -map->line_height / 2 + WIN_HEIGHT / 2;
	if (map->draw_start < 0)
		map->draw_start = 0;
	map->draw_end = map->line_height / 2 + WIN_HEIGHT / 2;
	if (map->draw_end >= WIN_HEIGHT)
		map->draw_end = WIN_HEIGHT - 1;
}
