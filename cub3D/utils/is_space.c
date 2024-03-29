/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_space.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <aoner@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 09:15:02 by aoner             #+#    #+#             */
/*   Updated: 2023/01/03 14:03:31 by aoner            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	is_space(int c)
{
	if (c == ' ' || c == '\n' || c == '\t' || \
	c == '\f' || c == '\r' || c == '\v')
		return (1);
	return (0);
}
