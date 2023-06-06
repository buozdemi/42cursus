/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_elements_ctrl.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <aoner@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 13:34:32 by aoner             #+#    #+#             */
/*   Updated: 2023/01/04 11:20:55 by aoner            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	is_it_messy_map(t_data *data)
{
	int	i;

	i = data->game_start_line;
	while (data->collect_lines[i] && i != data->game_last_line + 1)
	{
		if (data->collect_lines[i][0] == '\n' || \
			data->collect_lines[i][0] == '\t' || \
			data->collect_lines[i][0] == '\v' || \
			data->collect_lines[i][0] == '\f' || \
			data->collect_lines[i][0] == '\r' || \
			data->collect_lines[i][0] == '\0')
			return (-1);
		i++;
	}
	return (0);
}

int	check_maps_elements(t_data *data)
{
	int		a;
	int		b;
	int		c;
	char	**map;

	map = data->collect_lines;
	c = data->game_start_line;
	a = 1;
	while (a < data->game_line_count - 1)
	{
		b = 1;
		while (b < data->column_length[a] - 1)
		{
			if (cme_control(map[a + c][b]))
			{
				printf("Error\nMap Character Error!\n");
				return (0);
			}
			check_maps_elements_utils(data, a, b, map);
			b++;
		}
		a++;
	}
	return (is_it_one(data));
}

void	check_maps_elements_utils(t_data *data, int a, int b, char **map)
{
	int	c;

	c = data->game_start_line;
	if (map[a + c][b] == 'N')
		data->ncount++;
	else if (map[a + c][b] == 'S')
		data->scount++;
	else if (map[a + c][b] == 'E')
		data->ecount++;
	else if (map[a + c][b] == 'W')
		data->wcount++;
}

int	is_it_one(t_data *data)
{
	if (data->ncount == 1 && data->scount == 0 && \
	data->ecount == 0 && data->wcount == 0)
		return (1);
	else if (data->ncount == 0 && data->scount == 1 && \
	data->ecount == 0 && data->wcount == 0)
		return (1);
	else if (data->ncount == 0 && data->scount == 0 && \
	data->ecount == 1 && data->wcount == 0)
		return (1);
	else if (data->ncount == 0 && data->scount == 0 && \
	data->ecount == 0 && data->wcount == 1)
		return (1);
	printf("Error\nCharacter symbol!\n");
	return (0);
}

int	cme_control(char c)
{
	if (c != '0' && c != '1' && c != 'N' && c != 'W' && c != 'S' && c != 'E')
		return (1);
	return (0);
}
