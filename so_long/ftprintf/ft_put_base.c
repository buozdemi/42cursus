/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_base.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozdemi <buozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 14:41:59 by buozdemi          #+#    #+#             */
/*   Updated: 2022/04/08 14:13:59 by buozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_put_base(unsigned int nbr, const char *base, \
		int hexa_type, int *count)
{
	unsigned int		base_len;
	unsigned long int	nb;

	nb = nbr;
	base_len = ft_strlen(base);
	if (nbr < base_len)
	{
		*count += ft_putchar_newfd(base[nbr % base_len], 1);
		return ;
	}
	else
	{
		ft_put_base(nbr / base_len, base, hexa_type, count);
		ft_put_base(nbr % base_len, base, hexa_type, count);
	}
}
