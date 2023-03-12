/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_pointer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozdemi <buozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 14:35:30 by buozdemi          #+#    #+#             */
/*   Updated: 2022/02/20 19:11:58 by buozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_put_pointer(unsigned long long n, int *count)
{
	char	*base;

	base = "0123456789abcdef";
	if (n < 16)
	{
		*count += ft_putchar_newfd(base[n], 1);
		return ;
	}
	if (n >= 16)
	{
		ft_put_pointer((n / 16), count);
		ft_put_pointer((n % 16), count);
	}
}
