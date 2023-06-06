/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_prep.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozdemi <buozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 16:07:08 by buozdemi          #+#    #+#             */
/*   Updated: 2022/12/26 19:46:06 by buozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	set_image_values(t_map *map)
{
	if (map->side == 0)
		map->wallx = map->py + map->wall_dist * map->raydiry;
	else
		map->wallx = map->px + map->wall_dist * map->raydirx;
	map->wallx -= floor(map->wallx);
	map->mx = (int)(map->wallx * (double)map->w_sixtyfour);
	if (map->side == 0 && map->raydirx > 0)
		map->mx = map->w_sixtyfour - map->mx - 1;
	if (map->side == 1 && map->raydiry < 0)
		map->mx = map->w_sixtyfour - map->mx - 1;
	map->pixel_cal = 1.0 * map->h_sixtyfour / map->line_height;
	map->pixel_nbr = (map->draw_start - WIN_HEIGHT / 2 + map->line_height \
	/ 2) * map->pixel_cal;
}

void	draw_image(t_map *map, t_data *data, int i)
{
	int	a;

	a = map->draw_start;
	while (a < map->draw_end)
	{
		map->my = (int)map->pixel_nbr & (map->h_sixtyfour - 1);
		map->pixel_nbr += map->pixel_cal;
		if (map->raydirx > 0 && map->side != 1)
			map->colour = map->so_data[map->h_sixtyfour * \
			map->my + map->mx];
		else if (map->raydirx < 0 && map->side != 1)
			map->colour = map->no_data[map->h_sixtyfour * \
			map->my + map->mx];
		else if ((map->raydirx <= 2 && map->raydiry >= 0) && map->side == 1)
			map->colour = map->ea_data[map->h_sixtyfour * \
			map->my + map->mx];
		else
			map->colour = map->we_data[map->h_sixtyfour * \
			map->my + map->mx];
		data->screen.addr[a * WIN_WIDTH + i] = map->colour;
		a++;
	}
}
