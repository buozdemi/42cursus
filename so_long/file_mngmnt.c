/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_mngmnt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozdemi <buozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 17:51:07 by buozdemi          #+#    #+#             */
/*   Updated: 2022/06/20 13:48:11 by buozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	extension(t_map *map, char *berfile)
{
	int	i;

	i = ft_strlen(berfile) - 1;
	if (!(berfile[i] == 'r' && berfile[i - 1] == 'e' && \
	berfile[i - 2] == 'b' && berfile[i - 3] == '.'))
	{
		ft_printf("Error\nBer: The Ber file does not exist.");
		earlyfree(map);
	}
	map->imgident = 0;
	read_map(map);
}

void	free_map(t_map *map, int i)
{
	if (i == 0)
		free_map_work(map);
	if (i == 3)
	{
		ft_printf("Error\nGet_next_line function returned NULL or\n\
The map is wrong.\n");
		earlyfree(map);
	}
	if (i == 1)
	{
		ft_printf("Error\nMap: Exit-Collectible-Player or Vitamin deficiency.\n");
		free_map_work(map);
	}
	if (i == 2)
	{
		ft_printf("Error\nMap: It could be one of the following:\n\
1.The map isn't rectangular.\n\
2.Fault in upper and lower walls.\n\
3.Get_next_line function returned NULL.\n");
		free_map_work(map);
	}
	if (i == 4)
	{
		ft_printf("Error\nMap: There isn't only 1 player or 1 exit.\n");
		free_map_work(map);
	}
}

void	free_map_work(t_map *map)
{
	int	i;

	i = 0;
	while (map->line && map->line[i] != NULL)
		free(map->line[i++]);
	free(map->line);
	if (map->imgident == 1)
	{
		mlx_destroy_image(map->mlx, map->scofield);
		mlx_destroy_image(map->mlx, map->bellick);
		mlx_destroy_image(map->mlx, map->wall);
		mlx_destroy_image(map->mlx, map->escape);
		mlx_destroy_image(map->mlx, map->scorig);
		mlx_destroy_image(map->mlx, map->scolef);
		mlx_destroy_image(map->mlx, map->scob);
		mlx_destroy_image(map->mlx, map->b);
		mlx_clear_window(map->mlx, map->win);
		mlx_destroy_window(map->mlx, map->win);
	}
	close(map->fd);
	free(map);
	exit(EXIT_SUCCESS);
}

void	earlyfree(t_map *map)
{
	close(map->fd);
	free(map);
	exit(1);
}

void	parttwofree(t_map *map)
{
	int	i;

	i = 0;
	while (map->line && map->line[i] != NULL)
		free(map->line[i++]);
	free(map->line);
	if (map->imgident == 1)
	{
		mlx_destroy_image(map->mlx, map->scofield);
		mlx_destroy_image(map->mlx, map->bellick);
		mlx_destroy_image(map->mlx, map->wall);
		mlx_destroy_image(map->mlx, map->escape);
		mlx_destroy_image(map->mlx, map->scorig);
		mlx_destroy_image(map->mlx, map->scolef);
		mlx_destroy_image(map->mlx, map->scob);
		mlx_destroy_image(map->mlx, map->b);
		mlx_clear_window(map->mlx, map->win);
		mlx_destroy_window(map->mlx, map->win);
	}
	free(map);
	exit(EXIT_SUCCESS);
}
/* 	if (!berfile)
	{
		ft_printf("Error\nBer: The Ber file was not sent with the program.");
		system("leaks so_long");
		earlyfree(map);
	} */