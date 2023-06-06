/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <aoner@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 16:42:38 by aoner             #+#    #+#             */
/*   Updated: 2022/02/04 13:32:14 by aoner            ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */
/*s paramatresinde n kadar c arar. bulduğunda bu BELLEK ADRESİNİ DÖNDÜRÜR.
Eğer s  parametresi NULL bir işaretçi ise anlamsız bir sonuç*/

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s)[i] == (unsigned char)c)
			return ((void *)(s + i));
		i++;
	}
	return (0);
}
/*
int main()
{
	char set[10] = "343";
	printf("o :%p\n", memchr(set, '3',  4));
	printf("t :%p", ft_memchr(set, '3', 4));
	
	return(0);
}*/
