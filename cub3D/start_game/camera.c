/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <aoner@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 16:55:00 by buozdemi          #+#    #+#             */
/*   Updated: 2023/01/04 11:27:52 by aoner            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	cam_left(t_map *map)
{
	map->old = map->dirx;
	map->dirx = map->dirx * cos(-map->rotate_speed) - map->diry * \
	sin(-map->rotate_speed);
	map->diry = map->old * sin(-map->rotate_speed) + map->diry * \
	cos(-map->rotate_speed);
	map->old2 = map->viewx;
	map->viewx = map->viewx * cos(-map->rotate_speed) - map->viewy * \
	sin(-map->rotate_speed);
	map->viewy = map->old2 * sin(-map->rotate_speed) + map->viewy * \
	cos(-map->rotate_speed);
}

void	cam_right(t_map *map)
{
	map->old = map->dirx;
	map->dirx = map->dirx * cos(map->rotate_speed) - \
	map->diry * sin(map->rotate_speed);
	map->diry = map->old * sin(map->rotate_speed) + \
	map->diry * cos(map->rotate_speed);
	map->old2 = map->viewx;
	map->viewx = map->viewx * cos(map->rotate_speed) - \
	map->viewy * sin(map->rotate_speed);
	map->viewy = map->old2 * sin(map->rotate_speed) + \
	map->viewy * cos(map->rotate_speed);
}
