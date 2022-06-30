/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_newfd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozdemi <buozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 19:10:34 by buozdemi          #+#    #+#             */
/*   Updated: 2022/02/20 13:44:43 by buozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr_newfd(char *str, int fd)
{
	size_t	i;
	int		count;

	count = 0;
	i = 0;
	if (!str)
	{
		count += ft_putstr_newfd("(null)", 1);
		return (count);
	}
	while (str[i])
	{
		count += write(fd, &str[i], 1);
		i++;
	}
	return (count);
}
