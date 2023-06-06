/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <aoner@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 16:34:38 by buozdemi          #+#    #+#             */
/*   Updated: 2023/01/04 11:27:52 by aoner            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	utils_move_forward(t_map *map, t_data *data)
{
	if (data->map[(int)(map->px - map->dirx * \
	map->move_speed)][(int)map->py] == '0' \
	|| data->map[(int)(map->px - map->dirx * \
	map->move_speed)][(int)map->py] == map->orientation)
		map->px -= map->dirx * map->move_speed;
	if (data->map[(int)map->px][(int)(map->py - map->diry * \
	map->move_speed)] == '0' \
	|| data->map[(int)map->px][(int)(map->py - map->diry * \
	map->move_speed)] == map->orientation)
		map->py -= map->diry * map->move_speed;
}

void	move_forward_backward(t_data *data, t_map *map)
{
	if (map->key_w)
	{
		if (data->map[(int)(map->px + map->dirx * \
		map->move_speed)][(int)map->py] == '0' \
		|| data->map[(int)(map->px + map->dirx * \
		map->move_speed)][(int)map->py] == map->orientation)
			map->px += map->dirx * map->move_speed;
		if (data->map[(int)map->px][(int)(map->py + \
		map->diry * map->move_speed)] == '0' \
		|| data->map[(int)map->px][(int)(map->py + \
		map->diry * map->move_speed)] == map->orientation)
			map->py += map->diry * map->move_speed;
	}
	else if (map->key_s)
		utils_move_forward(map, data);
}
