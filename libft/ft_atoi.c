/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozdemi <buozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 12:10:11 by buozdemi          #+#    #+#             */
/*   Updated: 2022/01/24 16:13:18 by buozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int		c;
	int		s;
	long	res;

	c = 0;
	s = 1;
	res = 0;
	while (str[c] == ' ' || (str[c] >= 9 && str[c] <= 13))
		c++;
	if (str[c] == '-' || str[c] == '+')
	{
		if (str[c] == '-')
			s = -1;
		c++;
	}
	while (str[c] >= '0' && str[c] <= '9')
	{
		res = (res * 10) + (str[c] - '0') * s;
		if (res > 2147483647)
			return (-1);
		else if (res < -2147483648)
			return (0);
		c++;
	}
	return (res);
}
/* int main(void)
{
	char dizi[] = "Kraliyet";
	char rakamsal[] = "87878787";
	char dizrak[] = "kral10";
	char rakdiz[] = "10kral";
	char eksirak[] = "-0391";

	printf("%d\n",ft_atoi(dizi));
	printf("%d\n",atoi(dizi));
	printf("%d\n",ft_atoi(rakamsal));
	printf("%d\n",atoi(rakamsal));	
	printf("%d\n",ft_atoi(dizrak));
	printf("%d\n",atoi(dizrak));
	printf("%d\n",ft_atoi(rakdiz));
	printf("%d\n",atoi(rakdiz));
	printf("%d\n",ft_atoi(eksirak));
	printf("%d\n",atoi(eksirak));
	return (0);
} */