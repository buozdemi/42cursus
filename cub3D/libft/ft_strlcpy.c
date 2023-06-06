/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <42istanbul.com.tr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 17:12:52 by aoner             #+#    #+#             */
/*   Updated: 2022/02/04 13:27:11 by aoner            ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */
/*strlcpy dizeleri sırasıyla kopyalar ve birleştirir.
NULL ile sonlandırmayı garanti, return: the length of src*/

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (src[i] != '\0' && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}
/*
int main(void)
{
	char set1[15] = "aysuoner";
	char set2[15] = "ecole";
	printf("o: %d\n", strlcpy(set1, set2, 2));
	printf("t : %d", ft_strlcpy(set1, set2, 5));
	return(0);
}*/
