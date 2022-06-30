/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapwrite.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozdemi <buozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 16:03:21 by buozdemi          #+#    #+#             */
/*   Updated: 2022/06/20 13:41:53 by buozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	whpicturewr(t_map *map, char c, int m, int i)
{
	if (c == '1')
		mlx_put_image_to_window(map->mlx, map->win, map->wall, m, i);
	if (c == 'E')
	{
		mlx_put_image_to_window(map->mlx, map->win, map->b, m, i);
		mlx_put_image_to_window(map->mlx, map->win, map->escape, m, i);
	}
	if (c == '0')
		mlx_put_image_to_window(map->mlx, map->win, map->b, m, i);
	if (c == 'C')
	{
		mlx_put_image_to_window(map->mlx, map->win, map->b, m, i);
		mlx_put_image_to_window(map->mlx, map->win, map->bellick, m, i);
	}
	if (c == 'P')
	{
		mlx_put_image_to_window(map->mlx, map->win, map->b, m, i);
		mlx_put_image_to_window(map->mlx, map->win, map->scofield, m, i);
		map->i = i / 64;
		map->m = m / 64;
	}
}

void	mapwrite(t_map *map)
{
	int	i;
	int	m;

	i = 0;
	while (map->line[i] != NULL)
	{
		m = 0;
		while (map->line[i][m] != '\0')
		{
			whpicturewr(map, map->line[i][m], m * 64, i * 64);
			m++;
		}
		i++;
	}
}

int	whtouch(int keycode, void *p)
{
	t_map	*a;

	a = p;
	if (keycode == 2)
		key_press_r(a);
	if (keycode == 0)
		key_press_l(a);
	if (keycode == 13)
		key_press_u(a);
	if (keycode == 1)
		key_press_d(a);
	if (keycode == 53)
		parttwofree(a);
	return (0);
}
