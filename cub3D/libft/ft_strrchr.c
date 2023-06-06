/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <aoner@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 18:32:02 by aoner             #+#    #+#             */
/*   Updated: 2022/02/04 13:59:17 by aoner            ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */
/* sondan baslayarak parametre c'yi arıyor*/

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i--;
	}
	return (0);
}
/*int main()
{
	char set1[10] = "123456";
	printf("o: %s\n", strrchr(set1, '\0'));
	printf("t: %s", ft_strrchr(set1, '\0'));
		return(0);
}*/
