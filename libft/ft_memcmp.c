/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozdemi <buozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 14:25:30 by buozdemi          #+#    #+#             */
/*   Updated: 2022/01/19 17:31:53 by buozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s1)[i] != ((unsigned char *)s2)[i])
			return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
		i++;
	}	
	return (0);
}
/* 
int	main(void)
{
	char	dizi[] = "makineler";
	char	dizi2[] = "makinasin";
	char	dizi3[] = "";

	printf("%d\n", ft_memcmp(dizi, dizi2, 6));
	printf("%d\n", memcmp(dizi, dizi2, 6));
	printf("%d\n", ft_memcmp(dizi, dizi2, 5));
	printf("%d\n", memcmp(dizi, dizi2, 5));
	printf("%d\n", ft_memcmp(dizi, dizi2, 0));
	printf("%d\n", memcmp(dizi, dizi2, 0));
	printf("%d\n", ft_memcmp(dizi, dizi3, 6));
	printf("%d\n", memcmp(dizi, dizi3, 6));
	return (0);
} */