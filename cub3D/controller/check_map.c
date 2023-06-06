/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <aoner@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 10:54:25 by aoner             #+#    #+#             */
/*   Updated: 2023/01/04 11:14:34 by aoner            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	check_map(t_data *data)
{
	int	a;
	int	i;

	a = 0;
	i = data->game_start_line;
	while (a < data->column_length[0])
	{
		if (data->collect_lines[i][a] != '1')
		{
			printf("Error\nMap: Top Wall Error!\n");
			return (0);
		}
		a++;
	}
	a = 0;
	while (a < data->column_length[data->game_line_count])
	{
		if (data->collect_lines[data->game_last_line][a] != '1')
		{
			printf("Error\nMap: Bot Wall Error!\n");
			return (0);
		}
		a++;
	}
	return (check_maps_column(data));
}

int	check_maps_column(t_data *data)
{	
	int	a;
	int	m;

	m = 0;
	a = data->game_start_line;
	while (a <= data->game_last_line)
	{
		if (data->collect_lines[a][0] != '1' || \
		data->collect_lines[a][data->column_length[m] - 1] != '1')
		{
			printf("Error\nMap: Right & Left Wall Error!\n");
			return (0);
		}
		m++;
		a++;
	}
	return (check_maps_inside(data));
}

int	check_maps_inside(t_data *data)
{
	int	i;
	int	y;
	int	gap;

	i = 0;
	while (i < data->game_line_count - 1)
	{
		if (data->column_length[i] < data->column_length[i + 1])
		{
			gap = (data->column_length[i + 1] - data->column_length[i]);
			y = (data->column_length[i + 1] - 1);
			if (check_maps_inside_utils1(data, gap, i, y) == 0)
				return (0);
		}
		else
		{
			gap = (data->column_length[i] - data->column_length[i + 1]);
			y = (data->column_length[i] - 1);
			if (check_maps_inside_utils2(data, gap, i, y) == 0)
				return (0);
		}
		i++;
	}
	return (check_maps_elements(data));
}

int	check_maps_inside_utils1(t_data *data, int gap, int i, int y)
{
	int	c;

	c = data->game_start_line;
	while (gap > 0)
	{
		if (data->collect_lines[c + i + 1][y] != '1')
		{
			printf("Error\nMap Error!\n");
			return (0);
		}
		y--;
		gap--;
	}
	return (1);
}

int	check_maps_inside_utils2(t_data *data, int gap, int i, int y)
{
	int	c;

	c = data->game_start_line;
	while (gap > 0)
	{
		if (data->collect_lines[i + c][y] != '1')
		{
			printf("Error\nMap Error!\n");
			return (0);
		}
		y--;
		gap--;
	}
	return (1);
}
