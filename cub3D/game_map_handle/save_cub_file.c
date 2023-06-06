/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_cub_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <aoner@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 22:00:19 by aoner             #+#    #+#             */
/*   Updated: 2023/01/03 12:59:09 by aoner            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	save_cub_file(char *path, t_data *data)
{
	size_t	k;
	char	*line;

	k = 0;
	exist_file_ctrl(path, data);
	data->collect_lines = (char **)ft_calloc(sizeof(char *), \
	map_linecount_ctrl(data) + 1);
	if (!data->collect_lines)
	{
		free(data);
		close(data->fd);
		exit(1);
	}
	close(data->fd);
	data->fd = open(path, O_RDONLY);
	line = get_next_line(data->fd);
	while (line)
	{
		data->collect_lines[k++] = line;
		line = get_next_line(data->fd);
	}
	if (!line)
		data->collect_lines[k] = line;
	close(data->fd);
}
