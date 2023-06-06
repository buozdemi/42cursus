/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozdemi <buozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 12:25:33 by aoner             #+#    #+#             */
/*   Updated: 2023/01/02 17:19:42 by buozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	malloc_error(t_data *data)
{
	ft_putstr_fd("Error\nMalloc problems.\n", 2);
	clear_data(data);
	exit(EXIT_FAILURE);
}
