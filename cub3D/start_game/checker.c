/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <aoner@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 18:06:39 by buozdemi          #+#    #+#             */
/*   Updated: 2023/01/04 11:22:47 by aoner            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	wallcheck(t_map *map)
{
	if (map->raydirx < 0)
	{
		map->step_x = -1;
		map->sidedist_x = (map->px - map->mapx) * map->deltadist_x;
	}
	else
	{
		map->step_x = 1;
		map->sidedist_x = (map->mapx + 1.0 - map->px) * map->deltadist_x;
	}
	if (map->raydiry < 0)
	{
		map->step_y = -1;
		map->sidedist_y = (map->py - map->mapy) * map->deltadist_y;
	}
	else
	{
		map->step_y = 1;
		map->sidedist_y = (map->mapy + 1.0 - map->py) * map->deltadist_y;
	}
}

void	hitcheck(t_map *map, t_data *data)
{
	while (map->hit == 0)
	{
		if (map->sidedist_x < map->sidedist_y)
		{
			map->sidedist_x += map->deltadist_x;
			map->mapx += map->step_x;
			map->side = 0;
		}
		else
		{
			map->sidedist_y += map->deltadist_y;
			map->mapy += map->step_y;
			map->side = 1;
		}
		if (data->map[map->mapx][map->mapy] == '1')
			map->hit = 1;
	}
}

void	only_map(t_data *data)
{
	int	i;
	int	y;

	y = 0;
	data->map = ft_calloc(sizeof(char *), data->game_line_count + 2);
	i = data->game_start_line;
	while (data->collect_lines[i] && i != data->game_last_line + 1)
	{
		data->map[y] = ft_strdup(data->collect_lines[i]);
		i++;
		y++;
	}
	data->map[y] = NULL;
}
