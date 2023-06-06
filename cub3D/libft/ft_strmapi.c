/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <42istanbul.com.tr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 17:32:13 by aoner             #+#    #+#             */
/*   Updated: 2022/02/04 13:55:51 by aoner            ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */
/*‘f’ fonksiyonunu ‘s’ stringinin bütün
karakterlerine uygular.stringden yenibir string yaratılır*/

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*temp;

	if (!s || !f)
		return (0);
	temp = ((char *)malloc(ft_strlen(s) + 1));
	if (!temp)
		return (0);
	i = 0;
	while (i < ft_strlen(s))
	{
		temp[i] = f(i, s[i]);
		i++;
	}
	temp[i] = '\0';
	return (temp);
}
/*
char my_f(unsigned int i, char str)
{
	printf("My_f i: %d and str[i]: %c\n", i, str);
    return str - 32;
}

int main()
{
 	char str[10] = "gezinti";
    
    printf("%s", ft_strmapi(str, my_f));
	
	return(0);
}*/
