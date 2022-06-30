/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quadrictl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozdemi <buozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 14:19:26 by buozdemi          #+#    #+#             */
/*   Updated: 2022/06/20 13:22:23 by buozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	satirsaydir(char *berfile)
{
	int	i;

	i = 0;
	while (berfile[i] != '\0' && berfile[i] != '\n')
		i++;
	return (i);
}

void	quadrictl(t_map *map)
{
	size_t		firstline;
	int			i;

	i = 1;
	firstline = ft_strlen(map->line[0]);
	while (map->line[i] != NULL)
	{
		if (ft_strlen(map->line[i]) != firstline)
			free_map(map, 2);
		i++;
	}
}

void	cnumber(char *lines, t_map *map)
{
	int	i;

	i = 0;
	map->existc = 0;
	while (lines[i] != '\0')
	{
		while (lines[i] && lines[i] != '\n')
		{
			if (lines[i] == 'C')
				++map->existc;
			i++;
		}
		if (lines[i] == '\n')
			i += 2;
	}
}

void	onlyp(char *lines, t_map *map)
{
	int	i;
	int	countp;

	countp = 0;
	i = 0;
	while (lines[i] != '\0')
	{
		if (lines[i] == 'P')
			countp++;
		i++;
		if (lines[i] == '\n')
			i++;
	}
	if (countp != 1)
		free_map(map, 4);
}

void	doorandexitfree(t_map *map)
{
	int	i;

	i = 0;
	map->step += 1;
	ft_printf("%d\n", map->step);
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
