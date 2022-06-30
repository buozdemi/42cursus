/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozdemi <buozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 15:11:51 by buozdemi          #+#    #+#             */
/*   Updated: 2022/06/20 13:48:51 by buozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	fillvalue(t_map *map)
{
	map->step = 0;
	map->totalc = 0;
	fillvaluereal(map);
	if (!(map->bellick) || !(map->scofield) || \
	!(map->escape) || !(map->wall) || !(map->b) || !(map->scob) || \
	!(map->scorig) || !(map->scolef))
	{
		ft_printf("Error\nThere is not XPM file.");
		parttwofree(map);
	}
	map->imgident = 1;
	mapwrite(map);
}

void	fillvaluereal(t_map *map)
{
	int	w;
	int	h;

	w = 0;
	h = 0;
	map->bellick = mlx_xpm_file_to_image(map->mlx, \
	"mate/bellick.xpm", &w, &h);
	map->scofield = mlx_xpm_file_to_image(map->mlx, \
	"mate/scofield.xpm", &w, &h);
	map->escape = mlx_xpm_file_to_image(map->mlx, \
	"mate/escape.xpm", &w, &h);
	map->wall = mlx_xpm_file_to_image(map->mlx, \
	"mate/wall.xpm", &w, &h);
	map->b = mlx_xpm_file_to_image(map->mlx, \
	"mate/backr.xpm", &w, &h);
	map->scob = mlx_xpm_file_to_image(map->mlx, \
	"mate/scob.xpm", &w, &h);
	map->scorig = mlx_xpm_file_to_image(map->mlx, \
	"mate/scorig.xpm", &w, &h);
	map->scolef = mlx_xpm_file_to_image(map->mlx, \
	"mate/scolef.xpm", &w, &h);
}

int	on_destroy(void *param)
{
	parttwofree((t_map *)param);
	return (0);
}

int	main(int argc, char **argv)
{
	t_map	*map;

	if (argc != 2)
	{
		ft_printf("Error\nArg:The program hasn't only 1 argument.");
		exit(1);
	}
	map = malloc(sizeof(t_map));
	if (!map)
		exit(1);
	map->fd = open(argv[1], O_RDONLY);
	if (map->fd < 0)
	{
		ft_printf("Error\nThere is no map or map name is wrong.");
		earlyfree(map);
	}
	extension(map, argv[1]);
	map->mlx = mlx_init();
	map->win = mlx_new_window(map->mlx, 64 * ft_strlen(map->line[0]), \
	64 * ft_strlenline(map->line), "so_long");
	fillvalue(map);
	mlx_hook(map->win, 2, 1L << 0, whtouch, map);
	mlx_hook(map->win, 17, 0, on_destroy, map);
	mlx_loop(map->mlx);
	return (0);
}
