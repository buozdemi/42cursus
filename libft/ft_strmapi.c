/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozdemi <buozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 13:27:50 by buozdemi          #+#    #+#             */
/*   Updated: 2022/01/18 17:31:08 by buozdemi         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*p;
	size_t	i;

	if (s == NULL || f == NULL)
		return (NULL);
	i = 0;
	p = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!p)
		return (NULL);
	while (s[i] != '\0')
	{
		p[i] = f(i, s[i]);
		i++;
	}
	p[i] = '\0';
	return (p);
}
/*
char	benimfonk(unsigned int i, char str)
{
	if (i > -1)
		str = str - 32;
	return (str);
}
 int	main(void)
{
	char dizi[15] = "makamaraci";
	char	*s;

	printf("%s\n", dizi);
	s = ft_strmapi(dizi,benimfonk);
	printf("%s\n", s);
} */