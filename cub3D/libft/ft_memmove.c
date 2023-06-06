/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <42istanbul.com.tr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 17:10:16 by aoner             #+#    #+#             */
/*   Updated: 2022/02/04 13:52:54 by aoner            ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */
/*memcpy ile aynı işlev FAKAT the copy is always done 
in a non-destructive manner
YANİ src'nin dst'ten küçük olduğU durumlarda
dst'in yapısının bozulmasına izin vermez*/

#include "libft.h"

void	*ft_memmove(void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*dst;
	unsigned char	*src;

	dst = (unsigned char *)s1;
	src = (unsigned char *)s2;
	if (!s1 && !s2)
	{
		return (0);
	}
	if ((s1 == s2) || !n)
		return (s1);
	i = 1;
	if (s2 < s1)
	{
		while (i <= n)
		{
			dst[n - i] = src[n - i];
			i++;
		}
	}
	else
		ft_memcpy(s1, s2, n);
	return (s1);
}
/*
int main()
{
	char set1[20] = "xxxxxxx";
	char set2[20] = "123";
	
	printf("o: %s\n", memmove(set1, set2, 7));
	printf("t :%s", ft_memmove(set1, set2, 7));
	
	
	return(0);
}*/
