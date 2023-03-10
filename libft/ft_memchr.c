/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozdemi <buozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 16:37:50 by buozdemi          #+#    #+#             */
/*   Updated: 2022/02/01 16:37:50 by buozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s)[i] == (unsigned char)c)
		{
			return ((void *)s + i);
		}
		i++;
	}
	return (NULL);
}
/* 
int	main(void)
{
	const char	dizi[] = "DinamoBukres";
	const char	*p;
	const char	*z;

	p = ft_memchr(dizi, 'm', 7);
	z = memchr(dizi, 'm', 7);
	printf("%u\n", p);
	printf("%u\n", p);
	return (0);
}
*/