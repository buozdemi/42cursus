/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozdemi <buozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 14:38:12 by buozdemi          #+#    #+#             */
/*   Updated: 2023/06/06 15:25:44 by buozdemi         ###   ########.fr       */
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
