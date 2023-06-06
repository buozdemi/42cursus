/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_game_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <aoner@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 18:28:19 by aoner             #+#    #+#             */
/*   Updated: 2023/01/03 13:50:25 by aoner            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	find_bottom_line(t_data *data)
{
	int	i;
	int	m;

	i = data->tot_line_count - 2;
	while (i > data->game_start_line)
	{
		m = 0;
		while (data->collect_lines[i][m])
		{
			if (data->collect_lines[i][m] == '1')
			{
				data->game_last_line = i;
				return (1);
			}
			if (data->collect_lines[i][m] && (data->collect_lines[i][m] != '\n' \
			&& data->collect_lines[i][m] != '\t' && data->collect_lines[i][m] \
			!= '\r' && data->collect_lines[i][m] != '\v' && \
			data->collect_lines[i][m] != '\f'))
				return (-1);
			m++;
		}
		i--;
	}
	return (-1);
}

int	between_value_and_map(t_data *data)
{
	int	i;
	int	m;
	int	c;

	m = 0;
	i = data->last_element_line;
	while (data->collect_lines[i])
	{
		m = 0;
		while (data->collect_lines[i][m])
		{
			c = data->collect_lines[i][m];
			if (!ft_strchr(" \v\f\t\r\n", c) && c != '1')
				return (-1);
			if (c == '1')
			{
				data->game_start_line = i;
				return (1);
			}
			m++;
		}
		i++;
	}
	return (-1);
}
