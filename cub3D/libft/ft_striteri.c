/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <42istanbul.com.tr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 17:32:43 by aoner             #+#    #+#             */
/*   Updated: 2022/02/04 13:51:15 by aoner            ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */
/*f’ fonksiyonun stringin her karakterine uygular.
Eğer gerekli olursa her karakter adresi ile
gönderilmelidir*/

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	if (s != 0 && f != 0)
	{
		i = 0;
		while (i < ft_strlen(s))
		{
			f(i, s + i);
			i++;
		}
	}
}
/*
void my_f(unsigned int i, char *str)
{
	printf("my_f i: %d and adress s[i]: %s\n", i, str);
}*/
/*int main()
{
	char str[20] = "adresligezi";
	ft_striteri(str, my_f);
	printf("%s\n", str);
	
	return 0;
}*/
