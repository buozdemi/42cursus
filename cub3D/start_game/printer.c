/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <aoner@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 17:17:29 by buozdemi          #+#    #+#             */
/*   Updated: 2023/01/04 11:27:52 by aoner            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	print_roof(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	while (x < WIN_WIDTH)
	{
		y = 0;
		while (y < WIN_HEIGHT / 2)
		{
			data->screen.addr[y * WIN_WIDTH + x] = data->ceilling;
			y++;
		}
		x++;
	}
}

void	print_ground(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = WIN_HEIGHT / 2;
	while (x < WIN_WIDTH && y < WIN_HEIGHT)
	{
		data->screen.addr[y * WIN_WIDTH + x] = data->floor;
		x++;
		if (x == WIN_WIDTH)
		{
			x = 0;
			y++;
		}
	}
}

void	print_img(t_data *data, t_map *map)
{
	int	i;

	i = 0;
	while (i < WIN_WIDTH)
	{
		map->camx = (2 * i / (double)WIN_WIDTH - 1);
		map->raydirx = map->dirx + map->viewx * map->camx;
		map->raydiry = map->diry + map->viewy * map->camx;
		map->mapx = (int)map->px;
		map->mapy = (int)map->py;
		map->deltadist_x = fabs(1 / map->raydirx);
		map->deltadist_y = fabs(1 / map->raydiry);
		map->hit = 0;
		wallcheck(map);
		hitcheck(map, data);
		get_dist(map);
		set_image_values(map);
		draw_image(map, data, i);
		i++;
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->screen.img, 0, 0);
}
