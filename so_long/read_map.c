/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozdemi <buozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 13:55:56 by buozdemi          #+#    #+#             */
/*   Updated: 2022/06/20 13:30:43 by buozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	ctrltopbot(t_map *map)
{
	int			i;
	int			m;

	i = 0;
	m = 0;
	while (map->line[m][i] == '1')
	{
		i++;
		if (map->line[m][i] != '1' && map->line[m][i] != '\0')
			free_map(map, 2);
	}
	i = 0;
	m = ft_strlenline(map->line) - 1;
	while (map->line[m][i] == '1')
	{
		i++;
		if (map->line[m][i] != '1' && map->line[m][i] != '\0')
			free_map(map, 2);
	}
	if (map->line[0][0] != '1' || map->line[m][0] != '1')
		free_map(map, 2);
}

void	ctrlecp(char *s, char *set, t_map *map)
{
	int	i;
	int	m;

	m = 0;
	i = 0;
	while (s[m] != set[i] && s[m] != '\0')
	{
		m++;
		if (s[m] == set[i])
		{
			if (set[i + 1] == '\0')
				break ;
			m = 0;
			i++;
		}
	}
	if (s[m] == '\0')
		free_map(map, 1);
	cnumber(s, map);
	onlyp(s, map);
	quadrictl(map);
	checkmap(map);
}

void	checkmap(t_map *map)
{
	int	i;

	i = 0;
	while (map->line[i + 1] != NULL)
	{
		if (!(ft_ctrlinwall(map->line[i + 1], "1")))
		{
			ft_printf("Error\nMap: Fault in side walls.");
			free_map(map, 0);
		}
		i++;
	}
	i = 0;
	while (map->line[i + 1] != NULL)
	{
		if (!ft_midarea(map->line[i + 1]))
		{
			ft_printf("Error\nMap: Undefined character in middle area.\n");
			free_map(map, 0);
		}
		i++;
	}
}

void	read_map(t_map *map)
{
	char	*lines;
	char	*gnl;
	char	*temp;

	gnl = get_next_line(map->fd, map);
	if (!gnl)
		free_map(map, 3);
	lines = ft_strdup("");
	map->line = NULL;
	while (gnl != NULL)
	{
		if (*gnl == '\n')
		{
			free(lines);
			free(gnl);
			free_map(map, 3);
		}
		temp = lines;
		lines = ft_strjoin(temp, gnl);
		free(temp);
		free(gnl);
		gnl = get_next_line(map->fd, map);
	}
	read_map2(map, lines);
}

void	read_map2(t_map *map, char *lines)
{
	map->line = ft_split(lines, '\n');
	if (map->line == NULL)
	{
		free(lines);
		earlyfree(map);
	}
	ctrltopbot(map);
	ctrlecp(lines, "ECP", map);
	free(lines);
	close(map->fd);
}
