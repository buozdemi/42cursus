/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exist_file_ctrl.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <aoner@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 21:11:16 by aoner             #+#    #+#             */
/*   Updated: 2022/11/24 09:33:29 by aoner            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	exist_file_ctrl(char *path, t_data *data)
{
	data->fd = open(path, O_RDONLY);
	if (data->fd < 0)
	{
		printf("Error\nThere is no map with the requested name!");
		free(data);
		close(data->fd);
		exit(1);
	}
}
