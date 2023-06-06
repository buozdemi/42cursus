/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_image_setup.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozdemi <buozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 22:43:53 by aoner             #+#    #+#             */
/*   Updated: 2023/01/02 19:31:41 by buozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	image_controller(t_map *map, t_data *data)
{
	if (!map->no || !map->so || !map->ea || !map->we)
	{
		ft_putstr_fd("image error!\n", 2);
		close_window(data);
		clear_data(data);
		exit(1);
	}
}

void	ft_image_setup(t_data *data, t_map *map)
{
	map->no = mlx_xpm_file_to_image(data->mlx, data->no, \
	&map->w_sixtyfour, &map->w_sixtyfour);
	map->so = mlx_xpm_file_to_image(data->mlx, data->so, \
	&map->w_sixtyfour, &map->w_sixtyfour);
	map->ea = mlx_xpm_file_to_image(data->mlx, data->ea, \
	&map->w_sixtyfour, &map->w_sixtyfour);
	map->we = mlx_xpm_file_to_image(data->mlx, data->we, \
	&map->w_sixtyfour, &map->w_sixtyfour);
	image_controller(map, data);
	map->no_data = (int *)mlx_get_data_addr(map->no, &data->screen.bbp, \
	&data->screen.line_len, &data->screen.endian);
	map->so_data = (int *)mlx_get_data_addr(map->so, &data->screen.bbp, \
	&data->screen.line_len, &data->screen.endian);
	map->ea_data = (int *)mlx_get_data_addr(map->ea, &data->screen.bbp, \
	&data->screen.line_len, &data->screen.endian);
	map->we_data = (int *)mlx_get_data_addr(map->we, &data->screen.bbp, \
	&data->screen.line_len, &data->screen.endian);
	data->floor_color = (data->f.r << 16) + (data->f.g << 8) + data->f.b;
	data->ceil_color = (data->c.r << 16) + (data->c.g << 8) + data->c.b;
	take_color_code(data);
}
