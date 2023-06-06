/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <42istanbul.com.tr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 17:31:50 by aoner             #+#    #+#             */
/*   Updated: 2022/02/04 13:25:23 by aoner            ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */
/*Malloc kullanarak hafızada yer ayırılır ardından
integer değerini temsil eden string döndürülür*/

#include "libft.h"

static int	ft_digitnum(int n)
{
	int	count;

	count = 0;
	if (n == 0)
		count++;
	if (n < 0)
	{
		n = n * -1;
		count++;
	}
	while (n > 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		i;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	i = ft_digitnum(n);
	str = (char *)malloc(i + 1);
	if (!str)
		return (0);
	if (n < 0)
		n = n * -1;
	str[i--] = '\0';
	while (n > 0)
	{
		str[i] = n % 10 + 48;
		i--;
		n /= 10;
	}
	if (i == 0 && str[1] == '\0')
		str[i] = '0';
	else if (i == 0 && str[1] != '\0')
		str[i] = '-';
	return (str);
}
/*
int main()
{
	int a = -424;
	printf("%s\n", ft_itoa(a));
	return(0);
}
*/
