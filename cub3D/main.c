/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <aoner@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 13:51:10 by aoner             #+#    #+#             */
/*   Updated: 2023/01/04 11:25:05 by aoner            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static	void	open_window(t_data *data, t_map *map)
{
	data->t_map = map;
	data->mlx = mlx_init();
	ft_image_setup(data, map);
	setupgame(map);
	data->mlx_win = mlx_new_window(data->mlx, WIN_WIDTH, WIN_HEIGHT, "CUKUR");
	data->screen.img = mlx_new_image(data->mlx, WIN_WIDTH, WIN_HEIGHT);
	data->screen.addr = (int *)mlx_get_data_addr(data->screen.img, \
	&data->screen.bbp, &data->screen.line_len, &data->screen.endian);
	only_map(data);
	get_pos(data, map);
	set_values(map);
	mlx_hook(data->mlx_win, 17, 0, xbutton, data);
	mlx_loop_hook(data->mlx, main_loop, data);
	mlx_hook(data->mlx_win, 2, 0, move, data);
	mlx_hook(data->mlx_win, 3, 0, move2, data);
	mlx_loop(data->mlx);
}

int	part_two(t_data *data)
{
	data->last_element_line = classify_the_elements(data);
	if (data->last_element_line == -1 || data->c.f == -1 || data->f.f == -1)
	{
		ft_putstr_fd("Error\ntype1:Map Error\n", 2);
		clear_data(data);
	}
	if (between_value_and_map(data) < 0)
	{
		ft_putstr_fd("Error\ntype2:Map Error\n", 2);
		clear_data(data);
	}
	delete_enter_from_map(data);
	if (find_bottom_line(data) < 0)
	{
		printf("Error\nUnder of map include wrong character.\n");
		clear_data(data);
	}
	if (is_it_messy_map(data) < 0)
	{
		printf("Error\nThe map is messy.\n");
		clear_data(data);
	}
	change_space_to_wall(data);
	column_counter(data);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	*data;
	t_map	*map;

	argc_ctrl(argc);
	map_name_ctrl(argv);
	data = ft_calloc(sizeof(t_data), 1);
	save_cub_file(argv[1], data);
	part_two(data);
	if (check_map(data))
	{
		map = ft_calloc(sizeof(t_map), 1);
		open_window(data, map);
	}
	else
	{
		clear_data(data);
		return (0);
	}
	return (0);
}

int	main_loop(t_data *data)
{
	mlx_clear_window(data->mlx, data->mlx_win);
	print_roof(data);
	print_ground(data);
	print_img(data, data->t_map);
	move_norm(data, data->t_map);
	return (0);
}
