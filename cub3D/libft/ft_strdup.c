/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <42istanbul.com.tr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 20:10:36 by aoner             #+#    #+#             */
/*   Updated: 2022/02/04 13:52:14 by aoner            ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dest;

	dest = ((char *)malloc(ft_strlen(s1) + 1));
	if (dest != NULL)
	{
		ft_memcpy(dest, s1, ft_strlen(s1) + 1);
		dest[ft_strlen(s1) + 1] = 0;
		return (dest);
	}
	return (NULL);
}
/*
int main()
{
	char set[10] = "cicekorman";
	
	printf("o: %s\n", strdup(set));
	printf("t: %s", ft_strdup(set));
	return(0);
}*/
