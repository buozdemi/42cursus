/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <42istanbul.com.tr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 17:23:34 by aoner             #+#    #+#             */
/*   Updated: 2022/02/04 13:28:01 by aoner            ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */
/* src'yi dst'ye ekler ve
 sonuç boyutunu(not just lenght) döndürür. 
 dst src kopyalanması için yeterli alana sahip olmalı.*/

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dlen;
	size_t	slen;
	size_t	i;

	dlen = ft_strlen(dst);
	slen = ft_strlen(src);
	i = 0;
	if (dstsize <= dlen)
		return (dstsize + slen);
	while (i < dstsize - dlen - 1 && src[i])
	{
		dst[dlen + i] = src[i];
		i++;
	}
	dst[dlen + i] = '\0';
	return (dlen + slen);
}
/*
int main()
{
    char dst[30] = "selam aysu";
    const char src[30] = "nasilsin";
    printf("%zu",strlcat(dst,src, 11));
	//printf("%zu",ft_strlcat(dst,src, 11));
return (0);
}*/
