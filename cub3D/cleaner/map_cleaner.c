/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_cleaner.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <aoner@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 17:46:13 by aoner             #+#    #+#             */
/*   Updated: 2023/01/04 11:11:42 by aoner            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	clear_arg(char **arg)
{
	int	i;

	i = 0;
	while (arg && arg[i])
	{
		free(arg[i]);
		i++;
	}
	if (arg)
		free(arg);
	return (0);
}

int	clear_data(t_data *data)
{
	if (!data)
		return (1);
	if (data->no)
		free(data->no);
	if (data->so)
		free(data->so);
	if (data->we)
		free(data->we);
	if (data->ea)
		free(data->ea);
	if (data->column_length)
		free(data->column_length);
	clear_arg(data->collect_lines);
	clear_arg(data->map);
	free(data);
	exit(EXIT_FAILURE);
	return (0);
}

void	close_window(t_data *data)
{
	if (data->mlx_win)
		mlx_destroy_window(data->mlx, data->mlx_win);
	if (data->mlx)
		free(data->mlx);
}

int	xbutton(t_data *data)
{
	printf("Game closed by player!\n");
	if (data->t_map->no_data)
		free(data->t_map->no_data);
	if (data->t_map->so_data)
		free(data->t_map->so_data);
	if (data->t_map->ea_data)
		free(data->t_map->ea_data);
	if (data->t_map->we_data)
		free(data->t_map->we_data);
	if (data->screen.img)
		free(data->screen.img);
	if (data->screen.addr)
		free(data->screen.addr);
	close_window(data);
	clear_data(data);
	exit(1);
}
