/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <42istanbul.com.tr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 17:27:42 by aoner             #+#    #+#             */
/*   Updated: 2022/02/04 14:04:53 by aoner            ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */
/*Malloc kullanarak hafızadan bir parça ayırılır ve
çıktı olarak s1 ve s2 stringlerinin birleştirilmiş
hali döndürülür.return == newstring.hafıza ayırmada
problem varsa NULL dönecek.*/

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*temp;
	int		i;
	int		k;

	if (!s1 || !s2)
		return (0);
	temp = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!temp)
		return (0);
	i = 0;
	while (s1[i] != '\0')
	{
		temp[i] = s1[i];
		i++;
	}
	k = 0;
	while (s2[k] != '\0')
		temp[i++] = s2[k++];
	temp[i] = '\0';
	return (temp);
}
/*
int main()
{
	char set1[20] = "01234";
	char set2[20] = "56789";
	
	printf("%s", ft_strjoin(set1, set2));	
	
	return(0);
}*/
