/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <42istanbul.com.tr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 10:38:21 by aoner             #+#    #+#             */
/*   Updated: 2022/02/04 14:10:00 by aoner            ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */
/*strnstr() işlevi, n karakterden fazlasının aranmadığı,
 * s1 dizesinde boş sonlandırılmış s2 dizesinin ilk oluşumunu bulur.
 * `\0' karakterinden sonra gelen karakterler aranmaz.*/

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	i1;
	size_t	i2;

	if (s2[0] == '\0')
		return ((char *)s1);
	i1 = 0;
	while (s1[i1])
	{
		i2 = 0;
		while (i1 < len && (s1[i1] == s2[i2]) && s1[i1])
		{
			i1++;
			i2++;
		}
		if (!s2[i2])
			return ((char *)s1 + (i1 - i2));
		i1 = (i1 - i2) + 1;
	}
	return (0);
}
/*
int main()
{
	char set1[] = "kucucugumherseyim";
	char set2[] = "cugum";
	
	printf("o: %s\n", strnstr(set1, set2, 9));
	printf("t: %s\n", ft_strnstr(set1, set2, 9));

	return(0);
}*/
