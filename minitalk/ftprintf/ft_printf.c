/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozdemi <buozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 16:31:09 by buozdemi          #+#    #+#             */
/*   Updated: 2022/04/08 14:14:07 by buozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	replace(char c, va_list argptr)
{
	int	count;

	count = 0;
	if (c == 'c')
		count += ft_putchar_newfd(va_arg(argptr, int), 1);
	if (c == 's')
		count += ft_putstr_newfd(va_arg(argptr, char *), 1);
	if (c == 'd' || c == 'i')
		ft_putnbr_newfd(va_arg(argptr, int), 1, &count);
	if (c == 'p')
	{
		count += write(1, "0x", 2);
		ft_put_pointer(va_arg(argptr, unsigned long long), &count);
	}
	if (c == 'u')
		ft_put_base(va_arg(argptr, unsigned int), "0123456789", 0, &count);
	if (c == 'x')
		ft_put_base(va_arg(argptr, unsigned int), \
				"0123456789abcdef", 1, &count);
	if (c == 'X')
		ft_put_base(va_arg(argptr, unsigned int), \
				"0123456789ABCDEF", 2, &count);
	if (c == '%')
		count += ft_putchar_newfd('%', 1);
	return (count);
}

static int	find_format(const char *str, va_list argptr)
{
	size_t	i;
	int		count;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1])
		{
			while (str[++i] == ' ')
				;
			if (!str[i])
				return (count);
			count += replace(str[i], argptr);
		}
		else
			count += ft_putchar_newfd(str[i], 1);
		i++;
	}
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	argptr;
	int		count;

	count = 0;
	va_start(argptr, str);
	count = find_format(str, argptr);
	va_end(argptr);
	return (count);
}
