/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozdemi <buozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 16:27:23 by buozdemi          #+#    #+#             */
/*   Updated: 2023/01/02 19:54:49 by buozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	move_left(t_data *data, t_map *map)
{	
	if (data->map[(int)(map->px - map->viewx * \
		map->move_speed)][(int)map->py] == '0' \
		|| data->map[(int)(map->px - map->viewx * \
		map->move_speed)][(int)map->py] == map->orientation)
			map->px -= map->viewx * map->move_speed;
	if (data->map[(int)map->px][(int)(map->py - map->viewy * \
		map->move_speed)] == '0' || \
		data->map[(int)map->px][(int)(map->py - map->viewy * \
		map->move_speed)] == map->orientation)
			map->py -= map->viewy * map->move_speed;
}

void	move_right(t_data *data, t_map *map)
{
	if (data->map[(int)(map->px + map->viewx * \
	map->move_speed)][(int)map->py] == '0' \
	|| data->map[(int)(map->px + map->viewx * \
		map->move_speed)][(int)map->py] == map->orientation)
		map->px += map->viewx * map->move_speed;
	if (data->map[(int)map->px][(int)(map->py + \
	map->viewy * map->move_speed)] == '0' \
	|| data->map[(int)map->px][(int)(map->py + \
		map->viewy * map->move_speed)] == map->orientation)
		map->py += map->viewy * map->move_speed;
}

int	move(int key, t_data *data)
{
	if (key == 53)
		xbutton(data);
	if (key == 13)
		data->t_map->key_w = 1;
	if (key == 1)
		data->t_map->key_s = 1;
	if (key == 0)
		data->t_map->key_a = 1;
	if (key == 123)
		data->t_map->key_caml = 1;
	if (key == 2)
		data->t_map->key_d = 1;
	if (key == 124)
		data->t_map->key_camr = 1;
	if (data->t_map->key == 46)
		data->t_map->m = 1;
	if (data->t_map->key == 49)
		data->t_map->key_b = 1;
	if (data->t_map->key == 19)
		data->t_map->key_r = 1;
	return (0);
}

int	move2(int key, t_data *data)
{
	if (key == 53)
		xbutton(data);
	if (key == 13)
		data->t_map->key_w = 0;
	if (key == 1)
		data->t_map->key_s = 0;
	if (key == 0)
		data->t_map->key_a = 0;
	if (key == 123)
		data->t_map->key_caml = 0;
	if (key == 2)
		data->t_map->key_d = 0;
	if (key == 124)
		data->t_map->key_camr = 0;
	if (data->t_map->key == 46)
		data->t_map->m = 0;
	if (data->t_map->key == 49)
		data->t_map->key_b = 0;
	if (data->t_map->key == 19)
		data->t_map->key_r = 0;
	return (0);
}

int	move_norm(t_data *data, t_map *map)
{
	move_forward_backward(data, map);
	if (map->key_a)
		move_left(data, map);
	if (map->key_caml)
		cam_left(map);
	if (map->key_d)
		move_right(data, map);
	if (map->key_camr)
		cam_right(map);
	return (0);
}
