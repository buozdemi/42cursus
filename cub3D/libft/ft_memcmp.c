/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <aoner@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 19:09:51 by aoner             #+#    #+#             */
/*   Updated: 2022/02/04 13:30:33 by aoner            ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */
/*memcmp() işlevi, s1 bayt dizesini s2 bayt dizesiyle karşılaştırır
Her iki dizenin de n bayt uzunluğunda olduğu varsayılır*/

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*ss1;
	unsigned char	*ss2;
	size_t			i;

	ss1 = (unsigned char *)s1;
	ss2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (ss1[i] != ss2[i])
		{
			return (ss1[i] - ss2[i]);
		}
		i++;
	}
	return (0);
}
/*
int main()
{
	char set1[15] = "cv";
	char set2[15] = "aba";
	
	printf("t : %d\n", memcmp(set1, set2, 2));
	printf("t : %d", ft_memcmp(set1, set2, 2));

	return(0);
}*/
