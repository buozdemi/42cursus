/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <aoner@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 17:27:50 by buozdemi          #+#    #+#             */
/*   Updated: 2022/12/30 14:27:16 by aoner            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	take_color_code(t_data *data)
{
	data->floor = mlx_get_color_value(data->mlx, \
		data->floor_color);
	data->ceilling = mlx_get_color_value(data->mlx, \
		data->ceil_color);
}
