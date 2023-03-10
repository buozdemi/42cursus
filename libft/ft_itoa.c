/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozdemi <buozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 14:38:12 by buozdemi          #+#    #+#             */
/*   Updated: 2022/02/01 17:42:25 by buozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_digitnum(int n)
{
	int	count;

	if (n == 0)
		return (1);
	count = 0;
	if (n < 0)
		n = n * -1;
	while (n > 0)
	{
		count++;
		n = n / 10;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*result;
	int		sign;
	int		uzunluk;

	sign = n < 0;
	if (n == -2147483648)
	{
		result = ft_strdup("-2147483648");
		return (result);
	}
	uzunluk = ft_digitnum(n) + sign;
	result = malloc(sizeof(char) * (uzunluk + 1));
	if (!result)
		return (NULL);
	if (sign)
		n = -n;
	result[uzunluk--] = '\0';
	while (uzunluk != -1)
	{
		result[uzunluk--] = (n % 10) + 48;
		n = n / 10;
	}
	if (sign)
		result[uzunluk + 1] = '-';
	return (result);
}
/*
int	main(void)
{
	char	*i1;
	char	*i2;
	char	*i3;
	
	i1 = ft_itoa(-623);
	i2 = ft_itoa(156);
	i3 = ft_itoa(-0);

	printf("%s\n%s\n%s\n", i1, i2, i3);
} */