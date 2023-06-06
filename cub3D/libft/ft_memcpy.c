/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <42istanbul.com.tr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 12:09:21 by aoner             #+#    #+#             */
/*   Updated: 2022/02/04 13:32:32 by aoner            ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */
/*The memcpy() function copies n bytes from memory area s2 to memory area s1*/
#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	if (!dst && !src)
		return (0);
	i = 0;
	while (i < n)
	{
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dst);
}
/*int main()
{
	char size1[20] = "xxxxxxxxx";
	char size2[20] = "123";
	
	printf("O: %s\n", memcpy(size1, size2, 7));
	printf("T: %s\n", ft_memcpy(size1, size2, 7));
	
	return(0);
}*/
