/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_newfd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozdemi <buozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 19:26:17 by buozdemi          #+#    #+#             */
/*   Updated: 2022/02/20 13:44:29 by buozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_newfd(int n, int fd, int *count)
{
	long int	nb;

	nb = n;
	if (nb < 0)
	{
		*count += ft_putchar_newfd('-', fd);
		nb *= -1;
	}
	if (nb < 10)
	{
		*count += ft_putchar_newfd((nb + '0'), fd);
		return ;
	}
	if (nb >= 10)
	{
		ft_putnbr_newfd(nb / 10, fd, count);
		ft_putnbr_newfd(nb % 10, fd, count);
	}
}
